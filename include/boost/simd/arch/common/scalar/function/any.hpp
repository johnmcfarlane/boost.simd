//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ANY_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ANY_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/logical.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template< typename T >
  BOOST_FORCEINLINE
  logical<T> any_(BOOST_SIMD_SUPPORTS(cpu_)
                 , T  a0) BOOST_NOEXCEPT
  {
    return is_nez(a0);
  }

  template< typename T >
  BOOST_FORCEINLINE
  logical<T> any_(BOOST_SIMD_SUPPORTS(cpu_)
        , logical<T>  a0) BOOST_NOEXCEPT
  {
    return a0;
  }

  BOOST_FORCEINLINE
  bool any_(BOOST_SIMD_SUPPORTS(cpu_)
           , bool a0) BOOST_NOEXCEPT
  {
    return a0;
  }

} } }


#endif
