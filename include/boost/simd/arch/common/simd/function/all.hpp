//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ALL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ALL_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/hmsb.hpp>
#include <boost/simd/function/slice.hpp>
#include <boost/simd/function/splatted.hpp>

namespace boost { namespace simd { namespace detail
{
  template< typename T, std::size_t N >
  BOOST_FORCEINLINE bool vall_ ( pack<T,N> const& a0
                               , aggregate_storage const &
                               ) BOOST_NOEXCEPT
  {
    auto const all0 = all(slice_high(a0));
    auto const all1 = all(slice_low(a0) );
    return  all0 && all1;
  }

  template< typename T, std::size_t N, typename K>
  BOOST_FORCEINLINE bool vall_ ( pack<T,N> const& a0
                               , K const
                               ) BOOST_NOEXCEPT
  {
    return hmsb(genmask(a0)).all();
  }

  template< typename T, std::size_t N >
  BOOST_FORCEINLINE bool all_ ( BOOST_SIMD_SUPPORTS(simd_)
                              , pack<T,N> const& a0
                              ) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return vall_(a0, typename p_t::storage_kind{});
  }

  template< typename T, std::size_t N >
  BOOST_FORCEINLINE auto all_ ( BOOST_SIMD_SUPPORTS(simd_)
                              , splatted_tag const&
                              , pack<T,N> const& a0
                              ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    (as_logical_t<pack<T, N>>(all(a0)))
  )

} } }

#endif
