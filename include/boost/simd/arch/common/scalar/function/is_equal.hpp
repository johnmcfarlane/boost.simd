//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_EQUAL_HPP_INCLUDED

#include <boost/simd/logical.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
//#include <boost/simd/detail/meta/pick.hpp>

namespace boost { namespace simd { namespace detail
{

  BOOST_FORCEINLINE bool is_equal_ ( BOOST_SIMD_SUPPORTS(cpu_)
                                   , bool a
                                   , bool b
                                   ) BOOST_NOEXCEPT
  {
    return a == b;
  }

  template <typename T>
  BOOST_FORCEINLINE logical<T> is_equal_( BOOST_SIMD_SUPPORTS(cpu_)
                                        , logical<T> a
                                        , logical<T> b
                                        ) BOOST_NOEXCEPT
  {
    return a == b;
  }

  template <typename T>
  BOOST_FORCEINLINE logical<T> is_equal_( BOOST_SIMD_SUPPORTS(cpu_)
                                        , T a
                                        , T b
                                        ) BOOST_NOEXCEPT
  {
    return a == b;
  }


} } }


#endif
