//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_POW_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_POW_ABS_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/log2_em1.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/detail/constant/powlargelim.hpp>
#include <boost/simd/detail/constant/powlowlim.hpp>
#include <boost/simd/constant/sixteen.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/if_else_nan.hpp>
#include <boost/simd/function/if_one_else_zero.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_odd.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/pow2.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <boost/simd/function/if_minus.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/function/signnz.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <utility>
#include <type_traits>
#include <boost/simd/detail/meta/convert_helpers.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/if_zero_else_one.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_ltz.hpp>
#endif

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N>
  inline pack<T,N>
  pow_abs_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    using pi_t = as_si_t<p_t>;
    pi_t e;
    p_t ax = bs::abs(a0);
    p_t x;
    std::tie(x, e) = pedantic_(ifrexp)(ax);
    pi_t i  = detail::pow_kernel<p_t>::select(x);
    p_t z = sqr(x);
    p_t w = detail::pow_kernel<p_t>::pow1(x, z);
    w = fma(Mhalf<p_t>(), z, w);
    w = fma(Log2_em1<p_t>(), w, w);
    z = fma(Log2_em1<p_t>(), x, w);
    z += x;
    w =  fma(tofloat(-i), Ratio<p_t, 1, 16>(), tofloat(e));
    p_t ya = pow_abs_reduc(a1);
    p_t yb = a1 - ya;
    p_t W = fma(z, a1, w*yb);
    p_t Wa = pow_abs_reduc(W);
    p_t Wb = W - Wa;
    W = fma(w, ya, Wa);
    Wa = pow_abs_reduc(W);
    p_t u = W - Wa;
    W = Wb + u;
    Wb = pow_abs_reduc(W);
    w = Sixteen<p_t>()*(Wa + Wb);
    // Test the power of 2 for over/underflow
    auto inf_ret = is_greater(w, Powlargelim<p_t>());
    auto zer_ret = is_less(w, Powlowlim<p_t>());
    e = toint(w);
    Wb = W - Wb;
    auto test = is_gtz(Wb);
    e = if_inc(test, e);
    Wb = if_minus(test, Wb, Ratio<p_t, 1, 16>());
    z = detail::pow_kernel<p_t>::pow2(Wb)*Wb;
    i = if_inc(is_gtz(e), (e/Sixteen<pi_t>()));
    e = (i*Sixteen<pi_t>()) - e;
    w =  detail::pow_kernel<p_t>::twomio16(e);
    z = fma(w, z, w);
    z = pedantic_(ldexp)( z, i );
#ifndef BOOST_SIMD_NO_INFINITIES
    auto gtax1 = is_greater(ax,One<p_t>());
    z =  if_else(is_equal(a1,  Inf<p_t>()),if_else_zero(gtax1, Inf<p_t>()), z);
    z =  if_else(is_equal(a1, Minf<p_t>()),if_zero_else(gtax1, Inf<p_t>()), z);
    z =  if_else(is_equal(ax, Inf<p_t>()),
                 if_else(is_gtz(a1),
                         Inf<p_t>(),
                         if_zero_else_one(is_ltz(a1))),
                 z);
#endif
    z = if_zero_else(zer_ret, z);
    z = if_else(inf_ret, Inf<p_t>(), z);
    z = if_else(is_equal(ax, One<p_t>()), ax, z);

    z = if_else(is_eqz(a0),
                if_else(is_ltz(a1), bs::Inf<p_t>(),
                        if_one_else_zero(is_eqz(a1))
                       ),
                z
               );
#ifndef BOOST_SIMD_NO_NANS
    z = if_else(is_nan(a0),
                if_else_nan(is_eqz(a1), One<p_t>()),
                z
               );
#endif
    return z;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  pow_abs_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return pow_abs(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  pow_abs_(BOOST_SIMD_SUPPORTS(simd_)
          , T const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return pow_abs(p_t(a0), a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  pow_abs_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N,simd_emulation_> const & a0
          , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(pow_abs, a0, a1);
  }

  //raw decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  pow_abs_(BOOST_SIMD_SUPPORTS(simd_)
          , raw_tag const &
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return simd::exp(a1*simd::log(bs::abs(a0)));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  pow_abs_(BOOST_SIMD_SUPPORTS(simd_)
          , raw_tag const &
          , pack<T,N> const & a0
          , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return raw_(pow_abs)(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  pow_abs_(BOOST_SIMD_SUPPORTS(simd_)
          , raw_tag const &
          , T const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return raw_(pow_abs)(p_t(a0), a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  pow_abs_(BOOST_SIMD_SUPPORTS(simd_)
          , raw_tag const &
          , pack<T,N,simd_emulation_> const & a0
          , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(raw_(pow_abs), a0, a1);
  }


} } }


#endif
