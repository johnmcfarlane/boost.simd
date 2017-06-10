//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FRAC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FRAC_HPP_INCLUDED

#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
 template<typename T>
 BOOST_FORCEINLINE T
 sfrac_( T a0, std::true_type const &) BOOST_NOEXCEPT
 {
    return a0-simd::trunc(a0);
 }

  template<typename T>
  BOOST_FORCEINLINE T
  sfrac_( T, std::false_type const &) BOOST_NOEXCEPT
  {
    return  Zero<T>();
  }

  template<typename T>
  BOOST_FORCEINLINE T
  frac_(BOOST_SIMD_SUPPORTS(cpu_)
       , T a0) BOOST_NOEXCEPT
  {
    return sfrac_(a0, std::is_floating_point<T>());
  }

} } }


#endif
