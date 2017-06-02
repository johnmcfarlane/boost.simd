//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CSC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CSC_HPP_INCLUDED

#include <boost/simd/function/restricted.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sin.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T csc_(BOOST_SIMD_SUPPORTS(cpu_)
        , T const& a) BOOST_NOEXCEPT
  {
    return rec(sin(a));
  }

  //================================================================================================
  // restricted_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T csc_(BOOST_SIMD_SUPPORTS(cpu_)
        , restricted_tag const&
        , T const& a) BOOST_NOEXCEPT
  {
    return rec(restricted_(sin)(a));
  }

  //================================================================================================
  // other_ tags
  template<typename T, typename Tag>
  BOOST_FORCEINLINE
  T csc_(BOOST_SIMD_SUPPORTS(cpu_)
        , T const& a
        , Tag const& ) BOOST_NOEXCEPT
  {
    return rec(sin(a, Tag()));
  }

} } }


#endif
