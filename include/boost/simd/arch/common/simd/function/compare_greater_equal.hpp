//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPARE_GREATER_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPARE_GREATER_EQUAL_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/compare_less.hpp>

namespace boost { namespace simd { namespace detail
{
  template< typename T, std::size_t N >
  BOOST_FORCEINLINE
  bool compare_greater_equal_ ( BOOST_SIMD_SUPPORTS(simd_)
                              , pack<T,N> const& a0
                              , pack<T,N> const& a1
                              ) BOOST_NOEXCEPT
  {
    return !compare_less(a0,a1);
  }

} } }

#endif

