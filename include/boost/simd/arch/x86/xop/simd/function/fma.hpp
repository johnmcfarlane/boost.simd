//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_XOP_SIMD_FUNCTION_FMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_XOP_SIMD_FUNCTION_FMA_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/size_picker.hpp>

#if BOOST_HW_SIMD_X86_AMD_XOP
namespace boost { namespace simd { namespace detail
{
  template < typename T>
  BOOST_FORCEINLINE pack<std::int32_t,4,sse_> xfma_( pack<std::int32_t,4,sse_> const& a0
                                                   , pack<std::int32_t,4,sse_> const& a1
                                                   , pack<std::int32_t,4,sse_> const& a2
                                                   , std::true_type const &
                                                   ) BOOST_NOEXCEPT //32 bits
  {
    return _mm_macc_epi32(a0, a1, a2);
  }

  template < typename T>
  BOOST_FORCEINLINE pack<std::int16_t,8,sse_> xfma_( pack<std::int16_t,8,sse_> const& a0
                                                   , pack<std::int16_t,8,sse_> const& a1
                                                   , pack<std::int16_t,8,sse_> const& a2
                                                   , std::false_type const &
                                                   ) BOOST_NOEXCEPT //16 bits
  {
    return  _mm_macc_epi16(a0, a1, a2);
  }
  template < typename T>
  BOOST_FORCEINLINE pack<std::uint32_t,4,sse_> xfma_( pack<std::uint32_t,4,sse_> const& a0
                                                    , pack<std::uint32_t,4,sse_> const& a1
                                                    , pack<std::uint32_t,4,sse_> const& a2
                                                    , std::true_type const &
                                                    ) BOOST_NOEXCEPT //32 bits
  {
    return _mm_macc_epi32(a0, a1, a2);
  }

  template < typename T>
  BOOST_FORCEINLINE pack<std::uint16_t,8,sse_> xfma_( pack<std::uint16_t,8,sse_> const& a0
                                                    , pack<std::uint16_t,8,sse_> const& a1
                                                    , pack<std::uint16_t,8,sse_> const& a2
                                                    , std::false_type const &
                                                    ) BOOST_NOEXCEPT //16 bits
  {
    return  _mm_macc_epi16(a0, a1, a2);
  }

} } }
#endif

#endif
