//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CSCD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CSCD_HPP_INCLUDED

#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sind.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
 //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T cscd_(BOOST_SIMD_SUPPORTS(cpu_)
         , T const& a) BOOST_NOEXCEPT
  {
    return cscd(a, tag::big_);
  }

  //================================================================================================
  // restricted_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T cscd_(BOOST_SIMD_SUPPORTS(cpu_)
         , restricted_tag const&
         , T const& a) BOOST_NOEXCEPT
  {
    return rec(restricted_(sind)(a));
  }

  //================================================================================================
  // other_ tags
  template<typename T, typename Tag>
  BOOST_FORCEINLINE
  T cscd_(BOOST_SIMD_SUPPORTS(cpu_)
         , T const& a
        , Tag const& ) BOOST_NOEXCEPT
  {
      return if_nan_else( is_nez(a)&&is_flint(a*Ratio<T,1,180>())
                        , rec(sind(a, tag::big_)));
  }

} } }


#endif
