//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_ZERO_ELSE_ONE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_ZERO_ELSE_ONE_HPP_INCLUDED

#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //TODO add a template parameter to choose the return type
  template<typename T>
  BOOST_FORCEINLINE T if_zero_else_one_(BOOST_SIMD_SUPPORTS(cpu_)
                             , T  a0) BOOST_NOEXCEPT
  {
     return  T(a0 == Zero<T>());
  }

  template<typename T>
  BOOST_FORCEINLINE T if_zero_else_one_(BOOST_SIMD_SUPPORTS(cpu_)
                             , logical<T> const& a0) BOOST_NOEXCEPT
  {
    return  a0 ? One<T>() : Zero<T>();
  }

  BOOST_FORCEINLINE bool if_zero_else_one__(BOOST_SIMD_SUPPORTS(cpu_)
                                          , bool  a0) BOOST_NOEXCEPT
  {
    return !a0;
  }

} } }


#endif
