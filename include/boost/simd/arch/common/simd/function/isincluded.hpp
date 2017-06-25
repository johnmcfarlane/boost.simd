//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ISINCLUDED_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ISINCLUDED_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>


#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/is_equal.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool isincluded_(BOOST_SIMD_SUPPORTS(simd_)
                       , pack<T,N> const& a0
                       , pack<T,N> const& a1) BOOST_NOEXCEPT
  {
    return all(is_equal(bitwise_or(a0, a1), a1));
  }

} } }
#endif

