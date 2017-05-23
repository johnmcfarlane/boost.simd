
//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_ABS_HPP_INCLUDED

#include <type_traits>
#include <boost/simd/pack.hpp>
#include <cstdint>

namespace boost { namespace simd { namespace detail
{
  template < typename T
             , typename = typename std::enable_if<std::is_signed<T>::value>::type
             , typename = typename std::enable_if<sizeof(typename T::value_type) == 4>::type
  >
  BOOST_FORCEINLINE pack<T,4,sse_> abs_ ( BOOST_SIMD_SUPPORTS(ssse3_)
                                        , pack<T,4,sse_> const& a0
                                        ) BOOST_NOEXCEPT
  {
    return _mm_abs_epi32(a0);
  }

  template < typename T
             , typename = typename std::enable_if<std::is_signed<T>::value>::type
             , typename = typename std::enable_if<sizeof(typename T::value_type) == 2>::type
  >
  BOOST_FORCEINLINE pack<T,8,sse_> abs_ ( BOOST_SIMD_SUPPORTS(ssse3_)
                                        , pack<T,8,sse_> const& a0
                                        ) BOOST_NOEXCEPT
  {
    return _mm_abs_epi16(a0);
  }

  template < typename T
             , typename = typename std::enable_if<std::is_signed<T>::value>::type
             , typename = typename std::enable_if<sizeof(typename T::value_type) == 1>::type
  >
  BOOST_FORCEINLINE pack<T,16,sse_> abs_ ( BOOST_SIMD_SUPPORTS(ssse3_)
                                         , pack<T,16,sse_> const& a0
                                         ) BOOST_NOEXCEPT
  {
    return _mm_abs_epi8(a0);
  }

} } }

#endif
