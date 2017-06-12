//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_ELSE_HPP_INCLUDED

#ifdef BOOST_SIMD_BRANCH_FREE_IF_ELSE
#include <boost/simd/function/bitwise_select.hpp>
#include <boost/simd/function/genmask.hpp>
#endif

#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{

 template<typename T, typename U, typename V>
  BOOST_FORCEINLINE U
  if_else_(BOOST_SIMD_SUPPORTS(cpu_)
          , T cond
          , U a1
          , V a2 ) BOOST_NOEXCEPT
  {
#ifdef BOOST_SIMD_BRANCH_FREE_IF_ELSE
    return bitwise_select(genmask(cond), a1, U(a2));
#else
    return cond ? a1 : U(a2);
#endif
  }

} } }


#endif
