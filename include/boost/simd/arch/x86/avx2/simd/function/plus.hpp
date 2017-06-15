//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_PLUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_PLUS_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE pack<T,32,avx_> plus_ ( BOOST_SIMD_SUPPORTS(avx2_)
                                          , pack<T,32,avx_> const& a0, pack<T,32,avx_> const& a1
                                          ) BOOST_NOEXCEPT
  {
    return _mm256_add_epi8(a0,a1);
  }

  template<typename T>
  BOOST_FORCEINLINE pack<T,16,avx_> plus_ ( BOOST_SIMD_SUPPORTS(avx2_)
                                          , pack<T,16,avx_> const& a0, pack<T,16,avx_> const& a1
                                          ) BOOST_NOEXCEPT
  {
    return _mm256_add_epi16(a0,a1);
  }

  template< typename T
          , typename = typename tt_::enable_if<tt_::is_integral<T>::value>::type
          >
  BOOST_FORCEINLINE pack<T,8,avx_> plus_( BOOST_SIMD_SUPPORTS(avx2_)
                                        , pack<T,8,avx_> const& a0, pack<T,8,avx_> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm256_add_epi32(a0,a1);
  }

  template< typename T
          , typename = typename tt_::enable_if<tt_::is_integral<T>::value>::type
          >
  BOOST_FORCEINLINE pack<T,4,avx_> plus_( BOOST_SIMD_SUPPORTS(avx2_)
                                        , pack<T,4,avx_> const& a0, pack<T,4,avx_> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm256_add_epi64(a0,a1);
  }

  // -----------------------------------------------------------------------------------------------
  // Support for saturated cases
  template<typename T> BOOST_FORCEINLINE
  pack<T,32,avx_> saturated_plus_ ( pack<T,32,avx_> const& a0, pack<T,32,avx_> const& a1
                                  , tt_::true_type const&
                                  ) BOOST_NOEXCEPT
  {
    return _mm256_adds_epi8(a0,a1);
  }

  template<typename T> BOOST_FORCEINLINE
  pack<T,32,avx_> saturated_plus_ ( pack<T,32,avx_> const& a0, pack<T,32,avx_> const& a1
                                  , tt_::false_type const&
                                  ) BOOST_NOEXCEPT
  {
    return _mm256_adds_epu8(a0,a1);
  }

  template<typename T>
  BOOST_FORCEINLINE pack<T,32,avx_> plus_ ( BOOST_SIMD_SUPPORTS(avx2_)
                                          , saturated_tag const&
                                          , pack<T,32,avx_> const& a0, pack<T,32,avx_> const& a1
                                          ) BOOST_NOEXCEPT
  {
    return saturated_plus_(a0,a1, tt_::is_signed<T>{});
  }

  template<typename T> BOOST_FORCEINLINE
  pack<T,16,avx_> saturated_plus_ ( pack<T,16,avx_> const& a0, pack<T,16,avx_> const& a1
                                  , tt_::true_type const&
                                  ) BOOST_NOEXCEPT
  {
    return _mm256_adds_epi16(a0,a1);
  }

  template<typename T> BOOST_FORCEINLINE
  pack<T,16,avx_> saturated_plus_ ( pack<T,16,avx_> const& a0, pack<T,16,avx_> const& a1
                                  , tt_::false_type const&
                                  ) BOOST_NOEXCEPT
  {
    return _mm256_adds_epu16(a0,a1);
  }
  template<typename T>
  BOOST_FORCEINLINE pack<T,16,avx_> plus_ ( BOOST_SIMD_SUPPORTS(avx2_)
                                          , saturated_tag const&
                                          , pack<T,16,avx_> const& a0, pack<T,16,avx_> const& a1
                                          ) BOOST_NOEXCEPT
  {
    return saturated_plus_(a0,a1, tt_::is_signed<T>{});
  }
} } }

#endif
