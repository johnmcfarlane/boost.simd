//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ICEIL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ICEIL_HPP_INCLUDED

#include <boost/simd/function/ceil.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
 template<typename T>
 BOOST_FORCEINLINE as_i_t<T>
 siceil_( T a0
        , std::true_type const &) BOOST_NOEXCEPT
 {
   return saturated_(toint)(simd::ceil(a0));
 }

  template<typename T>
  BOOST_FORCEINLINE T
  siceil_( T a0
         , std::false_type const & ) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T>
  BOOST_FORCEINLINE auto
  iceil_(BOOST_SIMD_SUPPORTS(cpu_)
        , T a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    siceil_(a0, std::is_floating_point<T>())
  )

} } }


#endif
