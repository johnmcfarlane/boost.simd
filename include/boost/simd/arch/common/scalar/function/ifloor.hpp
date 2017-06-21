//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IFLOOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IFLOOR_HPP_INCLUDED

#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE auto
  sifloor_( T a0
          , std::true_type const &) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    saturated_(toint)(bs::floor(a0))
  )

  template<typename T>
  BOOST_FORCEINLINE T
  sifloor_( T a0
          , std::false_type const ) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T>
  BOOST_FORCEINLINE auto
  ifloor_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    sifloor_(a0, std::is_floating_point<T>())
  )


    } } }


#endif
