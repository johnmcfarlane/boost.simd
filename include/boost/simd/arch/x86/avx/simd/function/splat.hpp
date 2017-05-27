//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_SPLAT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/as.hpp>

#ifdef BOOST_MSVC
# pragma warning(push)
# pragma warning(disable: 4244) // conversion loss of data
#endif

namespace boost { namespace simd { namespace detail
{
  template<typename Value>
  BOOST_FORCEINLINE pack<double,4> splat_ ( BOOST_SIMD_SUPPORTS(avx_)
                                          , as_<pack<double,4>> const&, Value const& v
                                          ) BOOST_NOEXCEPT
  {
    return _mm256_set1_pd(static_cast<double>(v));
  }

  template<typename T, typename Value>
  BOOST_FORCEINLINE typename std::enable_if < std::is_integral<T>::value
                                            , pack<T,4,avx_>
                                            >::type
  splat_(BOOST_SIMD_SUPPORTS(avx_), as_<pack<T,4,avx_>> const&, Value const& v) BOOST_NOEXCEPT
  {
    return _mm256_set1_epi64x(v);
  }

  template<typename T, typename Value>
  BOOST_FORCEINLINE typename std::enable_if < std::is_integral<T>::value
                                            , pack<T,8,avx_>
                                            >::type
  splat_ ( BOOST_SIMD_SUPPORTS(avx_), as_<pack<T,8,avx_>> const&, Value const& v) BOOST_NOEXCEPT
  {
    return _mm256_set1_epi32(static_cast<T>(v));
  }

  template<typename T, typename Value>
  BOOST_FORCEINLINE typename std::enable_if < std::is_integral<T>::value
                                            , pack<T,16,avx_>
                                            >::type
  splat_(BOOST_SIMD_SUPPORTS(avx_), as_<pack<T,16,avx_>> const&, Value const& v) BOOST_NOEXCEPT
  {
    return _mm256_set1_epi16(static_cast<T>(v));
  }

  template<typename T, typename Value>
  BOOST_FORCEINLINE typename std::enable_if < std::is_integral<T>::value
                                            , pack<T,32,avx_>
                                            >::type
  splat_(BOOST_SIMD_SUPPORTS(avx_), as_<pack<T,32,avx_>> const&, Value const& v) BOOST_NOEXCEPT
  {
    return _mm256_set1_epi8(static_cast<T>(v));
  }
} } }

#ifdef BOOST_MSVC
# pragma warning(pop)
#endif

#endif
