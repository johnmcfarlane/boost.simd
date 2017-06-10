//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_GAMMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_GAMMA_HPP_INCLUDED

#include <boost/simd/function/std.hpp>
#include <boost/config.hpp>
#include <boost/simd/arch/common/detail/generic/gamma_kernel.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/copysign.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_even.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/sinpi.hpp>
#include <boost/simd/function/stirling.hpp>
#include <type_traits>

#include <cmath>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE bool inftest_(float a0) BOOST_NOEXCEPT
  {
    return a0 > 35.4f;
  }
  BOOST_FORCEINLINE bool inftest_(double a0) BOOST_NOEXCEPT
  {
    return a0 > 171.624;
  }

  template<typename T
           , typename =  typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE
  T gamma_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0) BOOST_NOEXCEPT
  {
    if (is_eqz(a0)) return copysign(Inf<T>(), a0);
#ifndef BOOST_SIMD_NO_INVALIDS
    if( is_nan(a0) || (a0 == Minf<T>()) ) return Nan<T>();
    if (a0 == Inf<T>()) return a0;
#endif

    T x = a0;
    if (inftest_(a0)) return Inf<T>();
    T q = bs::abs(x);
    if(x < T(-33.0))
    {
//        return std::tgamma(a0);
      T st = stirling(q);
      T p =  floor(q);
      auto iseven =  is_even(std::int32_t(p));
      if (p == q) return Nan<T>();
      T z = q - p;
      if( z > Half<T>() )
      {
        p += One<T>();
        z = q - p;
      }
      z = q*sinpi(z);
      if( is_eqz(z) ) return Nan<T>();
      st = Pi<T>()/(bs::abs(z)*st);
      return iseven  ? -st : st;
    }
    T z = One<T>();
    while( x >= Three<T>() )
    {
      x -= One<T>();
      z *= x;
    }
    while( is_ltz(x) )
    {
      z /= x;
      x += One<T>();
    }
    while( x < Two<T>() )
    {
      if( is_eqz(x)) return Nan<T>();
      z /= x;
      x +=  One<T>();
    }
    if( x == Two<T>() ) return(z);
    x -= Two<T>();
    return z*detail::gamma_kernel<T>::gamma1(x);
  }

  // std_ decorator
  template<typename T
           , typename =  typename std::enable_if<std::is_floating_point<T>::value >::type
  >
  BOOST_FORCEINLINE
  T acot_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const &
         , T const& a) BOOST_NOEXCEPT
  {
    return std::tgamma(a);
  }

} } }


#endif
