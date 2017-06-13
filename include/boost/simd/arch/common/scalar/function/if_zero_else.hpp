//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_ZERO_ELSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_ZERO_ELSE_HPP_INCLUDED

#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
 template<typename T, typename U>
  BOOST_FORCEINLINE U if_zero_else_(BOOST_SIMD_SUPPORTS(cpu_)
                                      , T  a0
                                      , U  a1) BOOST_NOEXCEPT
  {
    return  is_eqz(a0) ? a1 : Zero<U>();
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE U if_zero_else_(BOOST_SIMD_SUPPORTS(cpu_)
                                      , logical<T> const & a0
                                      , U a1) BOOST_NOEXCEPT
  {
    return  a0 ? Zero<U>() : a1;
  }

  BOOST_FORCEINLINE bool if_zero_else_(BOOST_SIMD_SUPPORTS(cpu_)
                                      , bool a0
                                      , bool a1) BOOST_NOEXCEPT
  {
    return  a0 ? false : a1;
  }

} } }


#endif
