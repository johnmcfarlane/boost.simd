//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MASK2LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MASK2LOGICAL_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/meta/is_bitwise_logical.hpp>
#include <boost/assert.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_logical_t<pack<T,N>>
  v_mask2logical_ ( pack<T,N> const& a0
                  , std::true_type const &
                  ) BOOST_NOEXCEPT
  {
    return bitwise_cast<as_logical_t<pack<T,N>>>(a0);
  }

  template<typename T, std::size_t N>    //this is never to be called
  BOOST_FORCEINLINE as_logical_t<pack<T,N>>
  v_mask2logical_ ( pack<T,N> const& a0
                  , std::false_type const &
                  ) BOOST_NOEXCEPT
  {
    return is_nez(a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_logical_t<pack<T,N>>
  mask2logical_ ( BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a
                ) BOOST_NOEXCEPT
  {

    BOOST_ASSERT_MSG(assert_is_mask(a), "Argument to mask2logical is not a valid logical mask");
    return v_mask2logical_(a, is_bitwise_logical<pack<T,N>>());
  }

  // Emulated implementation
    template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto mask2logical_ ( BOOST_SIMD_SUPPORTS(simd_)
                     , pack<T,N,simd_emulation_> const& a
                     ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::mask2logical, a)
  )

    } } }

#endif
