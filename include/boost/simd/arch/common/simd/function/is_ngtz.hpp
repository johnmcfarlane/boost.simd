//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NGTZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NGTZ_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/is_not_greater.hpp>

namespace boost { namespace simd { namespace detail
{
 // Native implementation

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_ngtz_ ( BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a
                ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    is_not_greater(a, Zero(as(a)))
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto s_is_ngtz_ ( as_logical_t<pack<T,N>> const& a0
                  ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    !a0
  )

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_ngtz_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
     map_to( simd::is_ngtz, a)
  )

} } }
#endif

