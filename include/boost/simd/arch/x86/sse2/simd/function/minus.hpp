//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MINUS_HPP_INCLUDED
#include <type_traits>
#include <boost/simd/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<double,2> minus_( BOOST_SIMD_SUPPORTS(sse2_)
                                        , pack<double,2> const& a0, pack<double,2> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm_sub_pd(a0,a1);
  }

  template<typename T>
  BOOST_FORCEINLINE pack<T,16,sse_> minus_ ( BOOST_SIMD_SUPPORTS(sse2_)
                                          , pack<T,16,sse_> const& a0, pack<T,16,sse_> const& a1
                                          ) BOOST_NOEXCEPT
  {
    return _mm_sub_epi8(a0,a1);
  }

  template<typename T>
  BOOST_FORCEINLINE pack<T,8,sse_> minus_( BOOST_SIMD_SUPPORTS(sse2_)
                                        , pack<T,8,sse_> const& a0, pack<T,8,sse_> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm_sub_epi16(a0,a1);
  }

  template< typename T
          , typename = typename std::enable_if<std::is_integral<T>::value>::type
          >
  BOOST_FORCEINLINE pack<T,4,sse_> minus_( BOOST_SIMD_SUPPORTS(sse2_)
                                        , pack<T,4,sse_> const& a0, pack<T,4,sse_> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm_sub_epi32(a0,a1);
  }

  template< typename T
          , typename = typename std::enable_if<std::is_integral<T>::value>::type
          >
  BOOST_FORCEINLINE pack<T,2,sse_> minus_( BOOST_SIMD_SUPPORTS(sse2_)
                                        , pack<T,2,sse_> const& a0, pack<T,2,sse_> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm_sub_epi64(a0,a1);
  }

  // -----------------------------------------------------------------------------------------------
  // Support for saturated cases
  template<typename T> BOOST_FORCEINLINE
  pack<T,16,sse_> saturated_minus_ ( pack<T,16,sse_> const& a0, pack<T,16,sse_> const& a1
                                  , std::true_type const&
                                  ) BOOST_NOEXCEPT
  {
    return _mm_subs_epi8(a0,a1);
  }

  template<typename T> BOOST_FORCEINLINE
  pack<T,16,sse_> saturated_minus_ ( pack<T,16,sse_> const& a0, pack<T,16,sse_> const& a1
                                  , std::false_type const&
                                  ) BOOST_NOEXCEPT
  {
    return _mm_subs_epu8(a0,a1);
  }

  template<typename T>
  BOOST_FORCEINLINE pack<T,16,sse_> minus_ ( BOOST_SIMD_SUPPORTS(sse2_)
                                          , saturated_tag const&
                                          , pack<T,16,sse_> const& a0, pack<T,16,sse_> const& a1
                                          ) BOOST_NOEXCEPT
  {
    return saturated_minus_(a0,a1, std::is_signed<T>{});
  }

  template<typename T> BOOST_FORCEINLINE
  pack<T,8,sse_> saturated_minus_( pack<T,8,sse_> const& a0, pack<T,8,sse_> const& a1
                                , std::true_type const&
                                ) BOOST_NOEXCEPT
  {
    return _mm_subs_epi16(a0,a1);
  }

  template<typename T> BOOST_FORCEINLINE
  pack<T,8,sse_> saturated_minus_( pack<T,8,sse_> const& a0, pack<T,8,sse_> const& a1
                                , std::false_type const&
                                ) BOOST_NOEXCEPT
  {
    return _mm_subs_epu16(a0,a1);
  }
  template<typename T>
  BOOST_FORCEINLINE pack<T,8,sse_> minus_( BOOST_SIMD_SUPPORTS(sse2_)
                                        , saturated_tag const&
                                        , pack<T,8,sse_> const& a0, pack<T,8,sse_> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return saturated_minus_(a0,a1, std::is_signed<T>{});
  }
} } }

#endif

