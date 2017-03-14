//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_ACOS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_ACOS_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/type/complex/function/is_real.hpp>
#include <boost/simd/type/complex/function/is_imag.hpp>
#include <boost/simd/type/complex/function/is_invalid.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/acos.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/atan.hpp>
#include <boost/simd/function/average.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/if_neg.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/log1p.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_notand.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/safe_max.hpp>
#include <boost/simd/function/safe_min.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/constant/eight.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( acos_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      //
      // This implementation is a simd transcription and adaptation of the boost_math code
      // which itself is a transcription of the pseudo-code in:
      //
      // "Implementing the complex Arcsine and Arccosine Functions using Exception Handling."
      // T E Hull, Thomas F Fairgrieve and Ping Tak Peter Tang.
      // ACM Transactions on Mathematical Software, Vol 23, No 3, Sept 1997.
      //
      using rtype =  typename A0::value_type;
      const rtype a_crossover(1.5);
      const rtype b_crossover(0.6417);
      auto  ltzra0 = is_ltz(a0.real);
      auto  gtzia0 = is_gtz(a0.imag);
      //
      // Begin by insuring a0.real >= 0 and bs::imag(a0) >= 0 :
      //
      rtype x = bs::abs(a0.real);
      rtype y = bs::abs(a0.imag);
      rtype proper_real = bs::acos(x);
      auto lexone = (x <= One<rtype>());
      auto is_proper_real = logical_and(is_real(a0), lexone);

      const rtype s_max = safe_max(Eight<rtype>());
      const rtype s_min = safe_min(Four<rtype>());
      rtype xp1 = bs::inc(x);
      rtype xm1 = bs::dec(x);
      auto not_in_safe_zone = logical_or(logical_or((x > s_max), (x < s_min)),
                                         logical_or((y > s_max), (y < s_min)));
      //compute for safe zone
      rtype r, i;
      rtype yy = bs::sqr(y);
      rtype tr = bs::sqrt(sqr(xp1) + yy);
      rtype ts = bs::sqrt(sqr(xm1) + yy);
      rtype a = bs::average(tr, ts);
      rtype b = x/a;
      //compute r for b >  b_crossover
      rtype apx = a + x;
      r = if_else(lexone,
                  bs::atan(bs::sqrt(Half<rtype>()*apx*(yy/(tr+xp1)+(ts-xm1)))/x),
                  bs::atan((y*bs::sqrt(Half<rtype>()*(apx/(tr+xp1)+apx/(ts+xm1))))/x)
        );
      // r is computed
      r = if_else((b <= b_crossover), bs::acos(b), r);
      //compute am1 temporary for i for a <= a_crossover
      rtype tmp = yy/(tr+xp1);
      rtype am1 = if_else(lexone,
                          bs::average(tmp, yy/(ts-xm1)),
                          bs::average(tmp, (ts+xm1)));
      i =  if_else((a <= a_crossover),
                   bs::log1p(am1 + bs::sqrt(am1*(bs::inc(a)))),
                   bs::log(a + bs::sqrt(bs::dec(bs::sqr(a))))
        );
      // i is computed
      //compute for exception zone
      if (bs::any(not_in_safe_zone))
      {
        auto zone1 =  (y <= bs::Eps<rtype>()*bs::abs(xm1));
        if (bs::any(logical_and(zone1, not_in_safe_zone)))
        {
          rtype rr = if_else_zero(lexone, proper_real);
          rtype ii = if_else(lexone, y/bs::sqrt(-xp1*xm1),
                             if_else((Valmax<rtype>()/xp1 > xm1),
                                     bs::log1p(xm1 + bs::sqrt(xp1*xm1)),
                                     Log_2<rtype>() + bs::log(x)
                               )
            );
          r = if_else(zone1, rr, r);
          i = if_else(zone1, ii, i);
        }
        auto zone2 = (y <= s_min);
        auto not_treated = logical_notand(zone1, not_in_safe_zone);
        if (bs::any(logical_and(zone2, not_treated)))
        {
          rtype sqrty =  bs::sqrt(y);
          r = if_else(zone2, sqrty, r);
          i = if_else(zone2, sqrty, i);
        }
        auto zone3 = (dec(Eps<rtype>()*y) >= x);
        not_treated = logical_notand(zone2, not_treated);
        if (bs::any(logical_and(zone3, not_treated)))
        {
          r = if_else(zone3,  Pio_2<rtype>(), r);
          i = if_else(zone3,  Log_2<rtype>() + bs::log(y), i);
        }
        auto zone4 = (x > One<rtype>());
        not_treated = logical_notand(zone3, not_treated);
        if (bs::any(logical_and(zone4, not_treated)))
        {
          r = if_else(zone4, bs::atan(y/x), r);
          i = if_else(zone4, Log_2<rtype>() + bs::log(y) + Half<rtype>()*bs::log1p(sqr(x/y)), i);
        }
        not_treated = logical_notand(zone4, not_treated);
        if (bs::any(not_treated))
        {
          rtype aa = bs::sqrt(bs::inc(sqr(y)));
          r = if_else(not_treated, Pio_2<rtype>(), r);
          i = if_else(not_treated, Half<rtype>()*bs::log1p(Two<rtype>()*y*(y+aa)), i);
        }
      }
      if (bs::any(bs::is_invalid(a0))) // this is perhaps for pedantic specialization ?
      {
        auto nanx = bs::is_nan(x);
        auto nany = bs::is_nan(y);
        auto infx = (x == Inf<rtype>()) ;
        auto infy = (y == Inf<rtype>()) ;
        if (bs::any(infx))
        {
          r = bs::if_else(infx, Zero<rtype>(), r);
          i = bs::if_else(infx, Inf<rtype>(), i);
          r = bs::if_else(logical_and(infx, infy), Pio_4<rtype>(), r);
          i = bs::if_else(logical_and(infx, infy), Inf<rtype>(), i);

          r =  if_else(logical_and(infx, nany), y, r);
          i =  if_else(logical_and(infx, nany), Minf<rtype>(), i);
        }
        if (bs::any(nanx))
        {
          r =  if_else(nanx, x, r);
          i =  if_else(nanx, x, i);
          i =  if_else(logical_and(nanx, infy), y, i);
        }
        auto test = logical_notand(logical_or(infx, nanx), infy);
        if (bs::any(test))
        {
          r = if_else(logical_and(infy, test), Pio_2<rtype>(), r);
          i = if_else(logical_and(infy, test), y, i);
        }
        test = logical_notand(logical_or(infx, nanx), nany);
        r = if_else(test,if_else(bs::is_imag(a0), Pio_2<rtype>(), y), r);
        i = if_else(test,y,i);
      }
      // use proper real results
      r = if_else(is_proper_real, proper_real,   r);
      i = if_else(is_proper_real, Zero<rtype>(), i);
      // restore signs
      r = if_else(ltzra0, Pi<rtype>()-r, r);
      i = if_neg(gtzia0, i);
      return {r, i};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( cmplx_acos_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE auto operator()(A0 const& a0) const BOOST_NOEXCEPT_DECLTYPE_BODY
      (
        bs::acos(a0)
      )
  };

  BOOST_DISPATCH_OVERLOAD ( cmplx_acos_
                          , (typename A0)
                          , bd::cpu_
                          , bd::floating_<A0>
                          )
  {
    using result_type =  cmplx::complex<A0>;
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      if (bs::all(bs::abs(a0) <= One<A0>())) return {bs::acos(a0.real),Zero<A0>()} ;
    return bs::acos(result_type(a0.real, Zero<A0>())); //TODO optimize it
    }
  };

} } }

#endif
