//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INSERT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INSERT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/aliasing.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template< typename T, std::size_t N, typename X
          , typename I, typename V
          >
  BOOST_FORCEINLINE void insert_( BOOST_SIMD_SUPPORTS(simd_)
                                , pack<T,N,X>& dst, I const& i, V const& value
                                ) BOOST_NOEXCEPT
  {
    reinterpret_cast<detail::may_alias_t<T>*>(&dst.storage())[i] = value;
  }

  template< typename T, std::size_t N, typename X
          , typename I, typename V
          >
  BOOST_FORCEINLINE void insert_impl( aggregate_storage const&
                                    , pack<logical<T>,N,X>& dst, I const& i, V const& value
                                    ) BOOST_NOEXCEPT
  {
    pack<logical<T>,N,X>::traits::at(dst,i) = value;
  }

  template< typename T, std::size_t N, typename X
          , typename I, typename V
          , typename K
          >
  BOOST_FORCEINLINE void insert_impl( K const&
                                    , pack<logical<T>,N,X>& dst, I const& i, V const& value
                                    ) BOOST_NOEXCEPT
  {
    reinterpret_cast<detail::may_alias_t<T>*>(&dst.storage())[i] = genmask(value, as_<T>());
  }

  template< typename T, std::size_t N, typename X
          , typename I, typename V
          >
  BOOST_FORCEINLINE void insert_( BOOST_SIMD_SUPPORTS(simd_)
                                , pack<logical<T>,N,X>& dst, I const& i, V const& value
                                ) BOOST_NOEXCEPT
  {
    return insert_impl(typename pack<logical<T>,N,X>::storage_kind{},dst,i,value);
  }
} } }

#endif
