//==================================================================================================
/**
  Copyright 2017 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_INTERLEAVE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_INTERLEAVE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
##include <boost/simd/detail/overload.hpp>
#include <array>

namespace boost { namespace simd { namespace detail
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  template< typename T>
  BOOST_FORCEINLINE pack<T,32,avx_> get_low(pack<T,32,avx_> const& a0, pack<T,32,avx_> const& a1, nsm::size_t<32> const& ) const
  {
    return _mm256_unpacklo_epi8(a0, a1);
  }

  template< typename T>
  BOOST_FORCEINLINE pack<T,16,avx_> get_low(pack<T,16,avx_> const& a0, pack<T,16,avx_> const& a1, nsm::size_t<16> const& ) const
  {
    return _mm256_unpacklo_epi16(a0, a1);
  }

  template< typename T>
  BOOST_FORCEINLINE pack<T,N,avx_> get_low(pack<T,N,avx_> const& a0, pack<T,N,avx_> const& a1, nsm::size_t< 8> const& ) const
  {
    return _mm256_unpacklo_epi32(a0, a1);
  }

  template< typename T>
  BOOST_FORCEINLINE pack<T,4,avx_> get_low(pack<T,4,avx_> const& a0, pack<T,4,avx_> const& a1, nsm::size_t< 4> const& ) const
  {
    return _mm256_unpacklo_epi64(a0, a1);
  }

  template< typename T>
  BOOST_FORCEINLINE pack<T,32,avx_> get_high(pack<T,32,avx_> const& a0, pack<T,32,avx_> const& a1, nsm::size_t<32> const& ) const
  {
    return _mm256_unpackhi_epi8(a0, a1);
  }

  template< typename T>
  BOOST_FORCEINLINE pack<T,16,avx_> get_high(pack<T,16,avx_> const& a0, pack<T,16,avx_> const& a1, nsm::size_t<16> const& ) const
  {
    return _mm256_unpackhi_epi16(a0, a1);
  }

  template< typename T>
  BOOST_FORCEINLINE pack<T,8,avx_> get_high(pack<T,8,avx_> const& a0, pack<T,8,avx_> const& a1, nsm::size_t< 8> const& ) const
  {
    return _mm256_unpackhi_epi32(a0, a1);
  }

  template< typename T>
  BOOST_FORCEINLINE pack<T,4,avx_> get_high(pack<T,4,avx_> const& a0, pack<T,4,avx_> const& a1, nsm::size_t< 4> const& ) const
  {
    return _mm256_unpackhi_epi64(a0, a1);
  }

  template< typename T, std::size_t N >
  BOOST_FORCEINLINE pack<T,N,avx_> interleave_( BOOST_SIMD_SUPPORTS(avx2_)
                                              , pack<T,N,avx_> const& a0
                                              , pack<T,N,avx_> const& a1
                                              ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N,avx_>;
    using sz_t = nsm::size_t<N>;
    auto l = get_low(a0, a1, sz_t{});
    auto h = get_high(a0, a1, sz_t{});

    std::array<p_t,2> that{_mm256_permute2x128_si256(l, h, 0x20),_mm256_permute2x128_si256(l, h, 0x31)};
    return that;
  }

} } }

#endif
