//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_UNORD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_UNORD_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/is_not_equal.hpp>
#include <boost/simd/constant/false.hpp>


namespace boost { namespace simd { namespace detail
{
   // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_unord_ ( pack<T,N> const& a0
                   , pack<T,N> const& a1
                   , std::true_type const &
                   ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    logical_or((a0 != a0), (a1 != a1))
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_unord_ ( pack<T,N> const&
                   ,  pack<T,N> const&
                 , std::false_type const &
                 ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    ( False<pack<T,N>>())
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_unord_ ( BOOST_SIMD_SUPPORTS(simd_)
                    , pack<T,N> const& a
                    , pack<T,N> const& b
                    ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    v_is_unord_(a, b, std::is_floating_point<T>())
  )

 // mixed implementation
  template< typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE typename std::enable_if<std::is_convertible<U, T>::value
                                            , as_logical_t< pack<T,N>>>::type
  is_unord_ ( BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N> const& a
            , U b
            ) BOOST_NOEXCEPT
  {
    return is_unord(a, pack<T,N>(b));
  }


  template< typename T, std::size_t N, typename U >
  BOOST_FORCEINLINE typename std::enable_if<std::is_convertible<U, T>::value
                                            , as_logical_t< pack<T,N>>>::type
  is_unord_ ( BOOST_SIMD_SUPPORTS(simd_)
            , U a
            , pack<T,N> const& b
            ) BOOST_NOEXCEPT
  {
    return is_unord(pack<T,N>(a), b);
  }

// Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_unord_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const& a
         , pack<T,N,simd_emulation_> const& b
         ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
     map_to( simd::is_unord, a, b)
  )

} } }


#endif


