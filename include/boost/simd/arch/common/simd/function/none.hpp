//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NONE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NONE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/slice.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/splatted.hpp>
#include <boost/simd/function/hmsb.hpp>
#include <boost/simd/function/genmask.hpp>


namespace boost { namespace simd { namespace detail
{
  template< typename T, std::size_t N >
  BOOST_FORCEINLINE bool
  v_none_ ( pack<T,N> const& a0
          , aggregate_storage const &
          ) BOOST_NOEXCEPT
  {
    auto const none0 = none(slice_high(a0));
    auto const none1 = none(slice_low(a0) );
    return  none0 && none1;
  }

  template< typename T, std::size_t N, typename K>
  BOOST_FORCEINLINE bool
  v_none_ ( pack<T,N> const& a0
          , K const
          ) BOOST_NOEXCEPT
  {
    return hmsb(genmask(a0)).none();
  }

  template< typename T, std::size_t N >
  BOOST_FORCEINLINE bool
  none_ ( BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const& a0
        ) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return v_none_(a0, typename p_t::storage_kind{});
  }

  template< typename T, std::size_t N >
  BOOST_FORCEINLINE auto
  none_ ( BOOST_SIMD_SUPPORTS(simd_)
        , splatted_tag const&
        , pack<T,N> const& a0
        ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    (as_logical_t<pack<T, N>>(none(a0)))
  )

} } }

#endif
