//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG2_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>
#include <boost/config.hpp>

#include <boost/simd/function/musl.hpp>
#include <boost/simd/function/plain.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/function/simd/any.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_minus.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/ilog2.hpp>
#include <boost/simd/function/is_lez.hpp>
#include <boost/simd/function/is_ngez.hpp>
#include <boost/simd/function/musl.hpp>
#include <boost/simd/function/plain.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/tofloat.hpp>

#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/invlog_2.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/sqrt_2o_2.hpp>
#include <boost/simd/constant/two.hpp>

#include <boost/simd/detail/constant/invlog_2hi.hpp>
#include <boost/simd/detail/constant/invlog_2lo.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> v_log2_( pack<T,N> const& a0
                   ,  std::true_type const &) BOOST_NOEXCEPT
  {
    return musl_(log2)(a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> v_log2_( pack<T,N> const& a0
                   ,  std::false_type const & ) BOOST_NOEXCEPT
  {
    return bitwise_cast<pack<T,N>>(bs::ilog2(a0));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> log2_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return v_log2_(a0,  std::is_floating_point<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> log2_ ( BOOST_SIMD_SUPPORTS(simd_)
                                 , pack<T,N,simd_emulation_> const& a
                                 ) BOOST_NOEXCEPT
  {
    return map_to(simd::log2, a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> log2_( BOOST_SIMD_SUPPORTS(simd_)
                  , std_tag const&
                  , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::log2), a);
  }

  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N> log2_( BOOST_SIMD_SUPPORTS(simd_)
                     , musl_tag const&
                     , pack<float,N> const& a0) BOOST_NOEXCEPT
  {
    /* origin: FreeBSD /usr/src/lib/msun/src/e_log2f.c */
    /*
     * ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunPro, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice
     * is preserved.
     * ====================================================
     */
    using p_t   = pack<float,N>;
    using uip_t = pack<uint32_t,N>;
    using ip_t  = pack<int32_t,N>;
    p_t x =  a0;
    ip_t k(0);
    auto isnez = is_nez(a0);
#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      k = if_minus(test, k, ip_t(25));
      x = if_else(test, x*p_t(33554432ul), x);
    }
#endif
    uip_t ix = bitwise_cast<uip_t>(x);
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    ix += 0x3f800000 - 0x3f3504f3;
    k += bitwise_cast<ip_t>(ix>>23) - 0x7f;
    ix = (ix&0x007fffff) + 0x3f3504f3;
    x =  bitwise_cast<p_t>(ix);
    p_t f = dec(x);
    p_t s = f/(2.0f + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3eccce13, 0x3e789e26>(w);
    p_t t2= z*horn<p_t, 0x3f2aaaaa, 0x3e91e9ee>(w);
    p_t R = t2 + t1;
    p_t hfsq = Half<p_t>()*sqr(f);

    p_t dk = tofloat(k);
    p_t r =   fma(fms(s, hfsq+R, hfsq)+f, Invlog_2<p_t>(), dk);
    // The original algorithm does some extra calculation in place of the return line
    // to get extra precision but this is uneeded for float as the exhaustive test shows
    // a 0.5 ulp maximal error on the full range.
    // Moreover all log2(exp2(i)) i =  1..31 are flint
    // I leave the code here in case an exotic proc will not play the game.
    //       p_t  hi = f - hfsq;
    //       hi =  bitwise_and(hi, uip_t(0xfffff000ul));
    //       p_t  lo = fma(s, hfsq+R, f - hi - hfsq);
    //       p_t r = (lo+hi)*detail::Invlog_2lo<p_t>() + lo*detail::Invlog_2hi<p_t>() + hi*detail::Invlog_2hi<p_t>() + k;

#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }

  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N> log2_( BOOST_SIMD_SUPPORTS(simd_)
                      , musl_tag const&
                      , pack<double,N> const& a0) BOOST_NOEXCEPT
  {
    /* origin: FreeBSD /usr/src/lib/msun/src/e_log2f.c */
    /*
     * ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunPro, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice
     * is preserved.
     * ====================================================
     */
    using p_t = pack<double,N>;
    using uip_t = pack<uint64_t,N>;
    using ip_t  = pack<int64_t,N>;
    p_t x =  a0;
    uip_t hx = bitwise_cast<uip_t>(x) >> 32;
    ip_t k(0);
    auto isnez = is_nez(a0);

#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      k = if_minus(test, k, ip_t(54));
      x = if_else(test, x*p_t(18014398509481984ull), x);
    }
#endif
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    hx += 0x3ff00000 - 0x3fe6a09e;
    k += bitwise_cast<ip_t>(hx>>20) - 0x3ff;
    hx = (hx&0x000fffff) + 0x3fe6a09e;
    x = bitwise_cast<p_t>(hx<<32 | (bitwise_and(0xffffffffull, bitwise_cast<uip_t>(x))));

    p_t f = dec(x);
    p_t s = f/(2.0f + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3fd999999997fa04ll, 0x3fcc71c51d8e78afll, 0x3fc39a09d078c69fll > (w);
    p_t t2= z*horn<p_t, 0x3fe5555555555593ll, 0x3fd2492494229359ll
      , 0x3fc7466496cb03dell, 0x3fc2f112df3e5244ll> (w);
    p_t R = t2 + t1;
    p_t hfsq = Half<p_t>()*sqr(f);
    //        return -(hfsq-(s*(hfsq+R))-f)*Invlog_2<p_t>()+dk;  // fast ?

    /*
     * f-hfsq must (for args near 1) be evaluated in extra precision
     * to avoid a large cancellation when x is near sqrt(2) or 1/sqrt(2).
     * This is fairly efficient since f-hfsq only depends on f, so can
     * be evaluated in parallel with R.  Not combining hfsq with R also
     * keeps R small (though not as small as a true `lo' term would be),
     * so that extra precision is not needed for terms involving R.
     *
     * Compiler bugs involving extra precision used to break Dekker's
     * theorem for spitting f-hfsq as hi+lo, unless double_t was used
     * or the multi-precision calculations were avoided when double_t
     * has extra precision.  These problems are now automatically
     * avoided as a side effect of the optimization of combining the
     * Dekker splitting step with the clear-low-bits step.
     *
     * y must (for args near sqrt(2) and 1/sqrt(2)) be added in extra
     * precision to avoid a very large cancellation when x is very near
     * these values.  Unlike the above cancellations, this problem is
     * specific to base 2.  It is strange that adding +-1 is so much
     * harder than adding +-ln2 or +-log10_2.
     *
     * This uses Dekker's theorem to normalize y+val_hi, so the
     * compiler bugs are back in some configurations, sigh.  And I
     * don't want to used double_t to avoid them, since that gives a
     * pessimization and the support for avoiding the pessimization
     * is not yet available.
     *
     * The multi-precision calculations for the multiplications are
     * routine.
     */

    /* hi+lo = f - hfsq + s*(hfsq+R) ~ log(1+f) */
    p_t  hi = f - hfsq;
    hi =  bitwise_and(hi, (Allbits<uip_t>() << 32));
    p_t lo = fma(s, hfsq+R, f - hi - hfsq);

    p_t val_hi = hi*Invlog_2hi<p_t>();
    p_t val_lo = fma(lo+hi, Invlog_2lo<p_t>(), lo*Invlog_2hi<p_t>());

    p_t dk = tofloat(k);
    p_t w1 = dk + val_hi;
    val_lo += (dk - w1) + val_hi;
    val_hi = w1;
    p_t r =  val_lo + val_hi;
#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }

  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N> log2_( BOOST_SIMD_SUPPORTS(simd_)
                     , plain_tag const&
                     , pack<float,N> const& a0) BOOST_NOEXCEPT
  {
    /* origin: FreeBSD /usr/src/lib/msun/src/e_log2f.c */
    /*
     * ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunPro, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice
     * is preserved.
     * ====================================================
     */
    using p_t = pack<float,N>;
    p_t x =  a0;
    p_t dk = Zero<p_t>();
    auto isnez = is_nez(a0);
#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      dk = if_minus(test, dk, p_t(25));
      x = if_else(test, x*p_t(33554432ul), x);
    }
#endif
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    p_t kk;
    std::tie(x, kk) = frexp(x);
    auto x_lt_sqrthf = (Sqrt_2o_2<p_t>() > x);
    dk += if_dec(x_lt_sqrthf, kk);
    p_t f = dec(x+if_else_zero(x_lt_sqrthf, x));
    p_t s = f/(Two<p_t>() + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3eccce13, 0x3e789e26>(w);
    p_t t2= z*horn<p_t, 0x3f2aaaaa, 0x3e91e9ee>(w);
    p_t R = t2 + t1;
    p_t hfsq = Half<p_t>()*sqr(f);

    p_t r =   fma(fms(s, hfsq+R, hfsq)+f, Invlog_2<p_t>(), dk);
    // The original algorithm does some extra calculation in place of the return line
    // to get extra precision but this is uneeded for float as the exhaustive test shows
    // a 0.5 ulp maximal error on the full range.
    // Moreover all log2(exp2(i)) i =  1..31 are flint
    // I leave the code here in case an exotic proc will not play the game.
    //       p_t  hi = f - hfsq;
    //       hi =  bitwise_and(hi, uip_t(0xfffff000ul));
    //       p_t  lo = fma(s, hfsq+R, f - hi - hfsq);
    //       p_t r = (lo+hi)*Invlog_2lo<p_t>() + lo*Invlog_2hi<p_t>() + hi*Invlog_2hi<p_t>() + k;

#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }

  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N> log2_( BOOST_SIMD_SUPPORTS(simd_)
                      , plain_tag const&
                      , pack<double,N> const& a0) BOOST_NOEXCEPT
  {
    /* origin: FreeBSD /usr/src/lib/msun/src/e_log2f.c */
    /*
     * ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunPro, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice
     * is preserved.
     * ====================================================
     */
    using p_t = pack<double,N>;
    p_t x =  a0;
    p_t dk = Zero<p_t>();
    auto isnez = is_nez(a0);

#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      dk = if_minus(test, dk, p_t(54));
      x = if_else(test, x*p_t(18014398509481984ull), x);
    }
#endif
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    p_t kk;
    std::tie(x, kk) = frexp(x);
    auto x_lt_sqrthf = (Sqrt_2o_2<p_t>() > x);
    dk += if_dec(x_lt_sqrthf, kk);
    p_t f = dec(x+if_else_zero(x_lt_sqrthf, x));
    p_t s = f/(Two<p_t>() + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3fd999999997fa04ll, 0x3fcc71c51d8e78afll, 0x3fc39a09d078c69fll > (w);
    p_t t2= z*horn<p_t, 0x3fe5555555555593ll, 0x3fd2492494229359ll
      , 0x3fc7466496cb03dell, 0x3fc2f112df3e5244ll> (w);
    p_t R = t2 + t1;
    p_t hfsq = Half<p_t>()*sqr(f);
//        return -(hfsq-(s*(hfsq+R))-f)*Invlog_2<p_t>()+dk;  // fast ?

    /*
     * f-hfsq must (for args near 1) be evaluated in extra precision
     * to avoid a large cancellation when x is near sqrt(2) or 1/sqrt(2).
     * This is fairly efficient since f-hfsq only depends on f, so can
     * be evaluated in parallel with R.  Not combining hfsq with R also
     * keeps R small (though not as small as a true `lo' term would be),
     * so that extra precision is not needed for terms involving R.
     *
     * Compiler bugs involving extra precision used to break Dekker's
     * theorem for spitting f-hfsq as hi+lo, unless double_t was used
     * or the multi-precision calculations were avoided when double_t
     * has extra precision.  These problems are now automatically
     * avoided as a side effect of the optimization of combining the
     * Dekker splitting step with the clear-low-bits step.
     *
     * y must (for args near sqrt(2) and 1/sqrt(2)) be added in extra
     * precision to avoid a very large cancellation when x is very near
     * these values.  Unlike the above cancellations, this problem is
     * specific to base 2.  It is strange that adding +-1 is so much
     * harder than adding +-ln2 or +-log10_2.
     *
     * This uses Dekker's theorem to normalize y+val_hi, so the
     * compiler bugs are back in some configurations, sigh.  And I
     * don't want to used double_t to avoid them, since that gives a
     * pessimization and the support for avoiding the pessimization
     * is not yet available.
     *
     * The multi-precision calculations for the multiplications are
     * routine.
     */

    /* hi+lo = f - hfsq + s*(hfsq+R) ~ log(1+f) */
    p_t  hi = f - hfsq;
    using uip_t =  pack<uint64_t,N>;
    hi =  bitwise_and(hi, (Allbits<uip_t>() << 32));  //TODO don't use uip_t, here stay in double
    p_t lo = fma(s, hfsq+R, f - hi - hfsq);

    p_t val_hi = hi*Invlog_2hi<p_t>();
    p_t val_lo = fma(lo+hi, Invlog_2lo<p_t>(), lo*Invlog_2hi<p_t>());

    p_t w1 = dk + val_hi;
    val_lo += (dk - w1) + val_hi;
    val_hi = w1;
    p_t r =  val_lo + val_hi;
#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }

} } }


#endif
