//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPARE_LESS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPARE_LESS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/slice.hpp>
#include <boost/simd/function/compare_equal.hpp>
#include <algorithm>

namespace boost { namespace simd { namespace detail
{
   template< typename T, std::size_t N >
   BOOST_FORCEINLINE bool vcompare_less_ ( pack<T,N> const& a0
                                         , pack<T,N> const& a1
                                         , aggregate_storage const &
                                         ) BOOST_NOEXCEPT
   {
     auto s0 = slice(a0);
     auto s1 = slice(a1);
     return compare_less(s0[0], s1[0]) ||
       (compare_equal(s0[0], s1[0]) && compare_less(s0[1], s1[1]));
   }

  template< typename T, std::size_t N, typename K>
  BOOST_FORCEINLINE bool vcompare_less_ ( pack<T,N> const& a0
                                        , pack<T,N> const& a1
                                        , K const
                                        ) BOOST_NOEXCEPT
  {
    return std::lexicographical_compare(a0.begin(),a0.end(),a1.begin(),a1.end());
  }

  template< typename T, std::size_t N >
  BOOST_FORCEINLINE bool compare_less_ ( BOOST_SIMD_SUPPORTS(simd_)
                                       , pack<T,N> const& a0
                                       , pack<T,N> const& a1
                                       ) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return vcompare_less_(a0,a1, typename p_t::storage_kind{});
  }

} } }

#endif
