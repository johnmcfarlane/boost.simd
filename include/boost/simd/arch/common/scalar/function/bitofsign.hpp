//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITOFSIGN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITOFSIGN_HPP_INCLUDED

#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <type_traits>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE
  T sbitofsign_( T a, std::true_type const &) BOOST_NOEXCEPT
  {
    return bitwise_and(a, Signmask<T>());
  }

  template<typename T>
  BOOST_FORCEINLINE
  T sbitofsign_( T , std::false_type const &) BOOST_NOEXCEPT
  {
    return Zero<T>();
  }

  template<typename T>
  BOOST_FORCEINLINE
  T bitofsign_(BOOST_SIMD_SUPPORTS(cpu_)
              , T a) BOOST_NOEXCEPT
  {
    return sbitofsign_(a, std::is_signed<T>()); ;
  }

} } }


#endif
