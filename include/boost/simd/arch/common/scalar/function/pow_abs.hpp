//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_POW_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_POW_ABS_HPP_INCLUDED

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/function/is_nan.hpp>
#endif
#include <boost/simd/arch/common/detail/generic/pow_kernel.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/log2_em1.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/sixteen.hpp>
#include <boost/simd/detail/constant/powlargelim.hpp>
#include <boost/simd/detail/constant/powlowlim.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/pow2.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/config.hpp>
#include <tuple>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  template < typename T>
  BOOST_FORCEINLINE T pow_abs_reduc(const T& x)
  {
    // Find a multiple of 1/16 that is within 1/16 of x.
    return Ratio<T, 1, 16>()*floor(Sixteen<T>()*x);
  }

  template<typename T>
  inline T
  pow_abs_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , T a1) BOOST_NOEXCEPT
  {
    const T Oneo_16 = Ratio<T, 1, 16>();
    using i_t = bd::as_integer_t<T>;
    const i_t Sixteen = Ratio<i_t, 16>();
    T x =  bs::abs(a0);
    if (x == One<T>()) return x;
    if (is_eqz(x)) return is_eqz(a1) ? One<T>() : is_ltz(a1) ? Inf<T>() : Zero<T>();
#ifndef BOOST_SIMD_NO_INFINITIES
    if(x == a1 && a1 == Inf<T>())  return Inf<T>();
    if(x == Inf<T>() && a1 == Minf<T>()) return Zero<T>();
    if(a1 == Inf<T>()) return (x < One<T>()) ? Zero<T>() : Inf<T>();
    if(a1 == Minf<T>()) return (x >  One<T>()) ? Zero<T>() : Inf<T>();
    if(x == Inf<T>()) return (a1 < Zero<T>()) ? Zero<T>() : ((a1 == Zero<T>()) ? One<T>() : Inf<T>());
#endif
#ifndef BOOST_SIMD_NO_INVALIDS
    if(is_nan(a0)) return is_eqz(a1) ? One<T>() : a0;
    if(is_nan(a1)) return Nan<T>();
#endif
    i_t e;
    std::tie(x, e) = pedantic_(bs::ifrexp)(x);
    i_t i  = detail::pow_kernel<T>::select(x);
    T z = sqr(x);
    T w = detail::pow_kernel<T>::pow1(x, z);
    w = fma(Mhalf<T>(), z, w);
    w = fma(Log2_em1<T>(), w, w);
    z = fma(Log2_em1<T>(), x, w);
    z += x;
    w =  fma(T(-i), Oneo_16, T(e));
    T ya = pow_abs_reduc(a1);
    T yb = a1 - ya;
    T W = fma(z, a1, w*yb);
    T Wa = pow_abs_reduc(W);
    T Wb = W - Wa;
    W = fma(w, ya, Wa);
    Wa = pow_abs_reduc(W);
    T u = W - Wa;
    W = Wb + u;
    Wb = pow_abs_reduc(W);
    w = Ratio<T, 16>()*(Wa + Wb);

    // Test the power of 2 for overflow
    if( w > Powlargelim<T>() ) return Inf<T>();
    if( w < Powlowlim<T>()   ) return Zero<T>();
    e = w;
    Wb = W - Wb;
    if( Wb > 0.0f )
    {
      ++e;
      Wb -= Oneo_16;
    }
    z = detail::pow_kernel<T>::pow2(Wb)*Wb;
    i = (e/Sixteen) + (e>=0);
    e = fms(i, Sixteen, e);
    w =  detail::pow_kernel<T>::twomio16(e);
    z = fma(w, z, w);
    z = pedantic_(ldexp)( z, i );
    return z;
  }

  template<typename T>
  BOOST_FORCEINLINE T
  pow_abs_(BOOST_SIMD_SUPPORTS(cpu_)
          , raw_tag const &
          , T a0
          , T a1) BOOST_NOEXCEPT
  {
    return simd::exp(a1*simd::log(simd::abs(a0)));
  }

} } }


#endif
