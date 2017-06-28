//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEARBYINT_HPP_INCLUDED

#include <boost/simd/constant/twotonmb.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/detail/enforce_precision.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/config.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <cmath>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T >
  BOOST_FORCEINLINE
  T s_nearbyint_( T a0
                , std::true_type const &) BOOST_NOEXCEPT
  {
    detail::enforce_precision<T> enforcer;
    const T v = bs::abs(a0);
    const T t2n = Twotonmb<T>();
    T d0 = (v+t2n);
    T d = (d0-t2n);
    d = (v < t2n)?d:v;
    return is_negative(a0) ? -d : d;
  }

  template<typename T >
  BOOST_FORCEINLINE
  T s_nearbyint_( T a
                , std::false_type const &) BOOST_NOEXCEPT
  {
    return a;
  }



  template<typename T >
  BOOST_FORCEINLINE
  T nearbyint_(BOOST_SIMD_SUPPORTS(cpu_)
              , T a) BOOST_NOEXCEPT
  {
    return s_nearbyint_(a, std::is_floating_point<T>());
  }

  //std_ decorator
  template<typename T >
  BOOST_FORCEINLINE
  T nearbyint_(BOOST_SIMD_SUPPORTS(cpu_)
              , std_tag const &
              , T a) BOOST_NOEXCEPT
  {
    return  T(std::nearbyint(a));
  }

  //raw_ decorator
  template<typename T >
  BOOST_FORCEINLINE
  T nearbyint_(BOOST_SIMD_SUPPORTS(cpu_)
              , raw_tag const &
              , T a) BOOST_NOEXCEPT
  {
    return  nearbyint(a);
  }

} } }


#endif
