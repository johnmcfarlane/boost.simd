//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ATAN2PI_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ATAN2PI_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/atan2.hpp>
#include <boost/simd/constant/invpi.hpp>
#include <boost/config.hpp>


namespace boost { namespace simd { namespace detail
{
  template<typename T, typename Arch>
  BOOST_FORCEINLINE
  T atan2pi_(BOOST_SIMD_SUPPORTS(Arch)
                  , T const& a
                  , T const& b) BOOST_NOEXCEPT
  {
    return Invpi<T>()*simd::atan2(a, b);
  };

  template<typename T, typename Arch>
  BOOST_FORCEINLINE
  T atan2pi_(BOOST_SIMD_SUPPORTS(Arch)
                  , pedantic_tag const &
                  , T const& a
                  , T const& b) BOOST_NOEXCEPT
  {
    return Invpi<T>()*pedantic_(simd::atan2)(a, b);
  };
} } }


#endif