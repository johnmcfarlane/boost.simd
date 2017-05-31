//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ALL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ALL_HPP_INCLUDED

#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/logical.hpp>

namespace boost { namespace simd { namespace detail
{
  template< typename T >
  BOOST_FORCEINLINE
  logical<T> all_(BOOST_SIMD_SUPPORTS(cpu_)
                 , T  a0) BOOST_NOEXCEPT
  {
    return is_nez(a0);
  }

  template< typename T >
  BOOST_FORCEINLINE
  logical<T> all_(BOOST_SIMD_SUPPORTS(cpu_)
        , logical<T>  a0) BOOST_NOEXCEPT
  {
    return a0;
  }

  BOOST_FORCEINLINE
  bool all_(BOOST_SIMD_SUPPORTS(cpu_)
           , bool a0) BOOST_NOEXCEPT
  {
    return a0;
  }

} } }

#endif
