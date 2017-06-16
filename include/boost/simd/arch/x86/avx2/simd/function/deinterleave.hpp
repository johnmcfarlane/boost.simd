//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_DEINTERLEAVE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_DEINTERLEAVE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/deinterleave_first.hpp>
#include <boost/simd/function/deinterleave_second.hpp>
#include <boost/simd/meta/detail/size_picker.hpp>
#include <array>

namespace boost { namespace simd { namespace detail
{

  template< typename T>
  BOOST_FORCEINLINE std::array<pack<T,32,avx_>, 2> // 8bits
  vdeinterleave_( pack<T,32,avx_> const& a0
                , pack<T,32,avx_> const& a1
                , case_<3> const& ) const
  {
    auto l    = _mm256_unpacklo_epi8(a0,a1);
    auto h    = _mm256_unpackhi_epi8(a0,a1);

    auto u0 = _mm256_unpacklo_epi8(l,h);
    auto u1 = _mm256_unpackhi_epi8(l,h);

    auto lh0  = _mm256_unpacklo_epi8(u0,u1);
    auto lh1  = _mm256_unpackhi_epi8(u0,u1);

    std::array<pack<T,32,avx_>,2> that { _mm256_permute4x64_epi64(_mm256_unpacklo_epi8(lh0, lh1), 0xD8)
                                       , _mm256_permute4x64_epi64(_mm256_unpackhi_epi8(lh0, lh1), 0xD8)
                                       };
    return that;
  }

  template< typename T>
  BOOST_FORCEINLINE std::array<pack<T,16,avx_>, 2> // 16bits
  vdeinterleave_( pack<T,16,avx_> const& a0
                , pack<T,16,avx_> const& a1
                , case_<2> const& ) const
  {
    auto l = _mm256_unpacklo_epi16(a0,a1);
    auto h = _mm256_unpackhi_epi16(a0,a1);

    auto u0 = _mm256_unpacklo_epi16(l,h);
    auto u1 = _mm256_unpackhi_epi16(l,h);

    l = _mm256_unpacklo_epi16(u0, u1);
    h = _mm256_unpackhi_epi16(u0, u1);

    std::array<pack<T,16,avx_,2> that { _mm256_permute4x64_epi64(l, 0xD8 )
                                      , _mm256_permute4x64_epi64(h, 0xD8 )
                                      };

    return that;
  }

  template< typename T>
  BOOST_FORCEINLINE std::array<pack<T,8,avx_>, 2> // 32bits
  vdeinterleave_( pack<T,8,avx_> const& a0
                , pack<T,8,avx_> const& a1
                , case_<1> const& ) const
  {
    auto l = _mm256_unpacklo_epi32(a0,a1);
    auto h = _mm256_unpackhi_epi32(a0,a1);
    A0   idx(0,1,4,5,2,3,6,7);

    std::array<pack<T,8,avx_>,2> that { _mm256_permutevar8x32_epi32(_mm256_unpacklo_epi32(l, h), idx)
                                      , _mm256_permutevar8x32_epi32(_mm256_unpackhi_epi32(l, h), idx)
                                      };
      return that;
  }

   template< typename T>
   BOOST_FORCEINLINE std::array<pack<T,4,avx_>, 2> // 64bits
   vdeinterleave_( pack<T,4,avx_> const& a0
                 , pack<T,4,avx_> const& a1
                 , case_<0> const& ) const
   {
     std::array<pack<T,4,avx_>,2> that { _mm256_permute4x64_epi64(_mm256_unpacklo_epi64(a0,a1), 0xD8)
                                       , _mm256_permute4x64_epi64(_mm256_unpackhi_epi64(a0,a1), 0xD8)
                                       };
      return that;
   }

  template< typename T, std::size_t N >
  BOOST_FORCEINLINE pack<T,N,avx_> deinterleave_( BOOST_SIMD_SUPPORTS(avx2_)
                                                , pack<T,N,avx_> const& a0
                                                , pack<T,N,avx_> const& a1
                                                ) BOOST_NOEXCEPT
  {
    return vdeinterleave_(a0, a1, size_picker<T>());
  }



} } }

#endif
