//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd { namespace detail
{
  //------------------------------------------------------------------------------------------------
  // 64 bits cases
  template<typename... Values>
  BOOST_FORCEINLINE pack<double,4> make_ ( BOOST_SIMD_SUPPORTS(avx_)
                                        , as_<pack<double,4>> const&, Values const&... values
                                        ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == 4
                  , "simd::make - Invalid number of arguments"
                  );

    return _mm256_setr_pd(static_cast<double>(values)...);
  }

  template<typename T, typename... Values>
  BOOST_FORCEINLINE typename std::enable_if < std::is_integral<T>::value, pack<T,4,avx_>>::type
  make_(BOOST_SIMD_SUPPORTS(avx_),as_<pack<T,4,avx_>> const&,Values const&... values) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == 4
                  , "simd::make - Invalid number of arguments"
                  );

    return _mm256_setr_epi64x( static_cast<T>(values)... );
  }

  //------------------------------------------------------------------------------------------------
  // 32 bits cases
  template<typename T, typename... Values>
  BOOST_FORCEINLINE pack<T,8,avx_>
  make_(BOOST_SIMD_SUPPORTS(avx_),as_<pack<float,8>> const&,Values const&... values) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == 8
                  , "simd::make - Invalid number of arguments"
                  );

    return _mm256_setr_ps(static_cast<T>(values)...);
  }

  template<typename T, typename... Values>
  BOOST_FORCEINLINE typename std::enable_if<std::is_integral<T>::value, pack<T,8,avx_>>::type
  make_(BOOST_SIMD_SUPPORTS(avx_),as_<pack<T,8,avx_>> const&,Values const&... values) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == 8
                  , "simd::make - Invalid number of arguments"
                  );

    return _mm256_setr_epi32(static_cast<T>(values)...);
  }

  //------------------------------------------------------------------------------------------------
  // 16 bits cases
  template<typename T, typename... Values>
  BOOST_FORCEINLINE pack<T,16,avx_> make_ ( BOOST_SIMD_SUPPORTS(avx_)
                                        , as_<pack<T,16,avx_>> const&, Values const&... values
                                        ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == 16
                  , "simd::make - Invalid number of arguments"
                  );

    return _mm256_setr_epi16(static_cast<T>(values)...);
  }

  template<typename T, typename... Values>
  BOOST_FORCEINLINE pack<T,32,avx_> make_ ( BOOST_SIMD_SUPPORTS(avx_)
                                          , as_<pack<T,32,avx_>> const&, Values const&... values
                                          ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == 32
                  , "simd::make - Invalid number of arguments"
                  );

    return _mm256_setr_epi8(static_cast<T>(values)...);
  }
} } }

#endif
