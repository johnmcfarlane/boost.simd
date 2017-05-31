//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPARE_NOT_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPARE_NOT_EQUAL_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/slice.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/function/is_not_equal.hpp>
#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  template< typename T, std::size_t N >
  BOOST_FORCEINLINE bool vcompare_not_equal_ ( pack<T,N> const& a0
                                             , pack<T,N> const& a1
                                             , aggregate_storage const &
                                             ) BOOST_NOEXCEPT
  {
    auto s0 = slice(a0);
    auto s1 = slice(a1);
    return compare_not_equal(s0[0], s1[0]) || compare_not_equal(s0[1], s1[1]);
  }

  template< typename T, std::size_t N, typename K>
  BOOST_FORCEINLINE bool vcompare_not_equal_ ( pack<T,N> const& a0
                                             , pack<T,N> const& a1
                                             , K const
                                             ) BOOST_NOEXCEPT
  {
//    return bs::any(a0 !=  a1); //TODO
    return !bs::all(a0 == a1);
  }

  template< typename T, std::size_t N >
  BOOST_FORCEINLINE bool compare_not_equal_ ( BOOST_SIMD_SUPPORTS(simd_)
                                            , pack<T,N> const& a0
                                            , pack<T,N> const& a1
                                            ) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return vcompare_not_equal_(a0,a1, typename p_t::storage_kind{});
  }

} } }

#endif
