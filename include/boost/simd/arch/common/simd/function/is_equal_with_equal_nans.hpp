//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_EQUAL_WITH_EQUAL_NANS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_EQUAL_WITH_EQUAL_NANS_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

  // Native implementation
  template<typename T, std::size_t N> //floating
  BOOST_FORCEINLINE auto
  s_is_equal_with_equal_nans_ ( pack<T,N> const& a0
                              , pack<T,N> const& a1
                              , std::true_type const &
                              ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    logical_or(is_equal(a0,a1), logical_and(bs::is_nan(a0), bs::is_nan(a1)))
  )

  template<typename T, std::size_t N> //floating
  BOOST_FORCEINLINE auto
  s_is_equal_with_equal_nans_ ( pack<T,N> const& a0
                              , pack<T,N> const& a1
                              , std::false_type const &
                              ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    is_equal(a0,a1)
  )



  template<typename T, std::size_t N>
  BOOST_FORCEINLINE auto
  is_equal_with_equal_nans_ ( BOOST_SIMD_SUPPORTS(simd_)
                            , pack<T,N> const& a
                            , pack<T,N> const& b
                            ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
     s_is_equal_with_equal_nans_(a, b, std::is_floating_point<T>())
  )

  // Native mixed implementation
  template< typename T, std::size_t N, typename U
          , typename =  std::enable_if<std::is_convertible<U, T>::value>
  >
  BOOST_FORCEINLINE auto
  is_equal_with_equal_nans_ ( BOOST_SIMD_SUPPORTS(simd_)
                            , pack<T,N> const& a
                            , U b
                            ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_equal_with_equal_nans, a, pack<T,N>(b))
  )

  template< typename T, std::size_t N, typename U
          , typename =  std::enable_if<std::is_convertible<U, T>::value>
  >
  BOOST_FORCEINLINE auto
  is_equal_with_equal_nans_ ( BOOST_SIMD_SUPPORTS(simd_)
                            , U a
                            , pack<T,N> const& b
                            ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_equal_with_equal_nans, pack<T,N>(a), b)
  )
  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE auto
  is_equal_with_equal_nans_ ( BOOST_SIMD_SUPPORTS(simd_)
                            , pack<T,N,simd_emulation_> const& a
                            , pack<T,N,simd_emulation_> const& b
                            ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_equal_with_equal_nans, a, b)
  )

  // Emulated mixed implementation
  template<typename T, std::size_t N, typename U,
           typename =  std::enable_if<std::is_convertible<U, T>::value>
  >
  BOOST_FORCEINLINE auto
  is_equal_with_equal_nans_ ( BOOST_SIMD_SUPPORTS(simd_)
                            , pack<T,N,simd_emulation_> const& a
                            , U b
                            ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_equal_with_equal_nans, a, pack<T,N,simd_emulation_>(b))
  )

  template< typename T, std::size_t N, typename U
          , typename =  std::enable_if<std::is_convertible<U, T>::value>
  >
  BOOST_FORCEINLINE auto
  is_equal_with_equal_nans_ ( BOOST_SIMD_SUPPORTS(simd_)
                            , U a
                            , pack<T,N,simd_emulation_> const& b
                            ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_equal_with_equal_nans, pack<T,N,simd_emulation_>(a), b)
  )

} } }

#endif

