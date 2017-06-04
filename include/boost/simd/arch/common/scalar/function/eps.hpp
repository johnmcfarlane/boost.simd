//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EPS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EPS_HPP_INCLUDED

#ifndef BOOST_SIMD_NO_DENORMALS
#include <limits>
#endif

#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
 //================================================================================================
  // regular cases
  template<typename T>
  BOOST_FORCEINLINE T seps_( T a
                           , std::true_type const&) BOOST_NOEXCEPT
  {
    a = bs::abs(a);
    if (is_invalid(a))  return Nan<T>();
#ifndef BOOST_SIMD_NO_DENORMALS
    else  if (a < std::numeric_limits<T>::min()) return Mindenormal<T>();
#endif
    else
    {
      using i_t = bd::as_integer_t<T, unsigned>;

      i_t e1 = exponent(a)-Nbmantissabits<T>();
      return bitwise_cast<T>(bitwise_cast<i_t>(T(1))+(e1 << Nbmantissabits<T>()));
    }
  }

  template<typename T>
  BOOST_FORCEINLINE T seps_( T
                           , std::false_type const&) BOOST_NOEXCEPT
  {
    return One<T>();
  }

  template<typename T>
  BOOST_FORCEINLINE T eps_( BOOST_SIMD_SUPPORTS(cpu_)
                          , T a) BOOST_NOEXCEPT
  {
    return seps_(a, std::is_floating_point<T>{});
  }

} } }


#endif
