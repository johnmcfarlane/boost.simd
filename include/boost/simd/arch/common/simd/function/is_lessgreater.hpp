//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_LESSGREATER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_LESSGREATER_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/is_ord.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <type_traits>


namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_logical_t<pack<T, N>>
  v_is_lessgreater_ ( pack<T, N> const& a0
                    , pack<T, N> const& a1
                    , std::false_type const &
                    ) BOOST_NOEXCEPT
  {
    return is_not_equal(a0, a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_logical_t<pack<T, N>>
  v_is_lessgreater_ ( pack<T, N> const& a0
                    , pack<T, N> const& a1
                    , std::true_type const &
                    ) BOOST_NOEXCEPT
  {
    return logical_and(is_ord(a0,a1), is_not_equal(a0, a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_logical_t<pack<T, N>>
  is_lessgreater_ ( BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T, N> const& a
                  , pack<T, N> const& b
                  ) BOOST_NOEXCEPT
  {
    return v_is_lessgreater_(a, b, std::is_floating_point<T>());
  }

  // mixed implementation
  template< typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE typename std::enable_if<std::is_convertible<U, T>::value
                                            , as_logical_t< pack<T,N>>>::type
  is_lessgreater_ ( BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N> const& a
            , U b
            ) BOOST_NOEXCEPT
  {
    return is_lessgreater(a, pack<T,N>(b));
  }


  template< typename T, std::size_t N, typename U >
  BOOST_FORCEINLINE typename std::enable_if<std::is_convertible<U, T>::value
                                            , as_logical_t< pack<T,N>>>::type
  is_lessgreater_ ( BOOST_SIMD_SUPPORTS(simd_)
            , U a
            , pack<T,N> const& b
            ) BOOST_NOEXCEPT
  {
    return is_lessgreater(pack<T,N>(a), b);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_logical_t<pack<T, N, simd_emulation_>>
  is_lessgreater_ ( BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N,simd_emulation_> const& a
            , pack<T,N,simd_emulation_> const& b
            ) BOOST_NOEXCEPT
  {
    return map_to( simd::is_lessgreater, a, b);
  }

  // std implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_logical_t<pack<T, N>>
  is_lessgreater_ ( BOOST_SIMD_SUPPORTS(simd_)
                  , std_tag const &
                  , pack<T,N,simd_emulation_> const& a
                  , pack<T,N,simd_emulation_> const& b
                  ) BOOST_NOEXCEPT
  {
    return map_to( std_(is_lessgreater), a, b);
  }

} } }


#endif
