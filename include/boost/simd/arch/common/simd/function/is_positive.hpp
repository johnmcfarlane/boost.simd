//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_POSITIVE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_POSITIVE_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_ltz.hpp>

namespace boost { namespace simd { namespace detail
{
   // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_logical_t< pack<T,N>>
  v_is_positive_ ( pack<T,N> const& a0
                 , std::true_type const &
                 ) BOOST_NOEXCEPT
  {
    return is_equal(bitwise_or(bitofsign(a0), One(as(a0))),One(as(a0)));
  }


  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_positive_ ( pack<T,N> const& a0
                      , std::false_type const &
                      ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    (is_gez(a0))
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_logical_t< pack<T,N>>
  is_positive_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N> const& a
               ) BOOST_NOEXCEPT
  {
    return v_is_positive_(a, std::is_floating_point<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_positive_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
     map_to( simd::is_positive, a)
  )

} } }

#endif

