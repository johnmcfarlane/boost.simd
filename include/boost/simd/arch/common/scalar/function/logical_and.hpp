//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOGICAL_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOGICAL_AND_HPP_INCLUDED

#include <boost/simd/logical.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{

  BOOST_FORCEINLINE bool
  logical_and_(BOOST_SIMD_SUPPORTS(cpu_)
              , bool a
              , bool b) BOOST_NOEXCEPT
  {
    return a && b;
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE logical<T>
  logical_and_(BOOST_SIMD_SUPPORTS(cpu_)
              , T a
              , U b) BOOST_NOEXCEPT
  {
    return a && b;
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE logical<T>
  logical_and_(BOOST_SIMD_SUPPORTS(cpu_)
              , logical<T> const & a
              , U b) BOOST_NOEXCEPT
  {
    return a.value() && b;
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE logical<T>
  logical_and_(BOOST_SIMD_SUPPORTS(cpu_)
              , logical<T> const & a
              , logical<U> const & b) BOOST_NOEXCEPT
  {
    return a.value() && b.value();
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE logical<T>
  logical_and_(BOOST_SIMD_SUPPORTS(cpu_)
              , T const & a
              , logical<U> const & b) BOOST_NOEXCEPT
  {
    return a && b.value();
  }

} } }

#endif
