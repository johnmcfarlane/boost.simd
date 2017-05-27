//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/insert.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename... Values>
  BOOST_FORCEINLINE pack<double,2> make_( BOOST_SIMD_SUPPORTS(sse2_)
                                        , as_<pack<double,2>> const&, Values const&... values
                                        ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == 2
                  , "simd::make - Invalid number of arguments"
                  );

    return _mm_setr_pd(static_cast<double>(values)...);
  }

  template<typename T, typename V0, typename V1>
  BOOST_FORCEINLINE typename std::enable_if < std::is_integral<T>::value
                                            , pack<T,2,sse_>
                                            >::type
  make_ ( BOOST_SIMD_SUPPORTS(sse2_)
        , as_<pack<T,2,sse_>> const&, V0 const& v0, V1 const& v1
        ) BOOST_NOEXCEPT
  {
    pack<T,2,sse_> that;
    simd::insert<0>(that,v0);
    simd::insert<1>(that,v1);
    return that;
  }

  template<typename T, typename... Values>
  BOOST_FORCEINLINE typename std::enable_if < std::is_integral<T>::value
                                            , pack<T,4,sse_>
                                            >::type
  make_ ( BOOST_SIMD_SUPPORTS(sse2_)
                                        , as_<pack<T,4,sse_>> const&, Values const&... values
                                        ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == 4
                  , "simd::make - Invalid number of arguments"
                  );

    return _mm_setr_epi32(static_cast<T>(values)...);
  }

  template<typename T, typename... Values>
  BOOST_FORCEINLINE pack<T,8,sse_> make_ ( BOOST_SIMD_SUPPORTS(sse2_)
                                        , as_<pack<T,8,sse_>> const&, Values const&... values
                                        ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == 8
                  , "simd::make - Invalid number of arguments"
                  );

    return _mm_setr_epi16(static_cast<T>(values)...);
  }

  template<typename T, typename... Values>
  BOOST_FORCEINLINE pack<T,16,sse_> make_ ( BOOST_SIMD_SUPPORTS(sse2_)
                                          , as_<pack<T,16,sse_>> const&, Values const&... values
                                          ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == 16
                  , "simd::make - Invalid number of arguments"
                  );

    return _mm_setr_epi8(static_cast<T>(values)...);
  }
} } }

#endif
