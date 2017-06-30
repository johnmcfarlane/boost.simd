//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOGICAL_NOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOGICAL_NOT_HPP_INCLUDED

#include <boost/simd/logical.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{

  BOOST_FORCEINLINE bool
  logical_not_(BOOST_SIMD_SUPPORTS(cpu_)
              , bool a) BOOST_NOEXCEPT
  {
    return !a;
  }

  template<typename T>
  BOOST_FORCEINLINE logical<T>
  logical_not_(BOOST_SIMD_SUPPORTS(cpu_)
              , T a) BOOST_NOEXCEPT
  {
    return !a;
  }

  template<typename T>
  BOOST_FORCEINLINE logical<T>
  logical_not_(BOOST_SIMD_SUPPORTS(cpu_)
              , logical<T> const & a
              ) BOOST_NOEXCEPT
  {
    return !a.value();
  }

} } }

#endif
