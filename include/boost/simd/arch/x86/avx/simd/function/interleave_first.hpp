//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/slice_low.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/slide.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  template < typename T>
  pack<T,4,avx_>
  interleave_first_ ( BOOST_SIMD_SUPPORTS(sse2_)
                    , pack<T,4,avx_> const& a0
                    , pack<T,4,avx_> const& a1
                    ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,4,avx_>;
    using fp_t = f_t<p_t>;
    auto b0 = bitwise_cast<f_t>(a0);
    auto b1 = bitwise_cast<f_t>(a1);

    // 0x20 is SCR1[0:127]|SRC2[0:127] according to Intel AVX manual
    // The result of unpack_*_pd puts parts in the proper pairs beforehand
    return  bitwise_cast<p_t>(fp_t( _mm256_permute2f128_pd( _mm256_unpacklo_pd(b0,b1)
                                                          , _mm256_unpackhi_pd(b0,b1)
                                                          , 0x20
                                                          )
                                )
                            );
  }

  template < typename T>
  pack<T,8,avx_>
  interleave_first_ ( BOOST_SIMD_SUPPORTS(sse2_)
                    , pack<T,8,avx_> const& a0
                    , pack<T,8,avx_> const& a1
                    ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,8,avx_>;
    using fp_t = f_t<p_t>;
    auto b0 = bitwise_cast<fp_t>(a0);
    auto b1 = bitwise_cast<fp_t>(a1);

    // 0x20 is SCR1[0:127]|SRC2[0:127] according to Intel AVX manual
    // The result of unpack_*_pd puts parts in the proper pairs beforehand
    return  bitwise_cast<p_t>(fp_t( _mm256_permute2f128_ps( _mm256_unpacklo_ps(b0,b1)
                                                          , _mm256_unpackhi_ps(b0,b1)
                                                          , 0x20
                                                          )
                                  )
                             );
  }

//   template < typename T>
//   pack<T,16,avx_>
//   interleave_first_ ( BOOST_SIMD_SUPPORTS(sse2_)
//                     , pack<T,16,avx_> const& a0
//                     , pack<T,16,avx_> const& a1
//                     ) BOOST_NOEXCEPT
//   {
//     auto x0 = slice(a0);
//     auto x1 = slice(a1);
//     return  combine ( interleave_first(x0,y0)
//                     , interleave_first(slide<4>(x0), slide<4>(y0))
//                     );
//   }

//   template < typename T>
//   pack<T,32,avx_>
//   interleave_first_ ( BOOST_SIMD_SUPPORTS(sse2_)
//                     , pack<T,32,avx_> const& a0
//                     , pack<T,32,avx_> const& a1
//                     ) BOOST_NOEXCEPT
//   {
//     auto x0 = slice(a0);
//     auto x1 = slice(a1);
//     return  combine ( interleave_first(x0,y0)
//                     , interleave_first(slide<8>(x0), slide<8>(y0))
//                     );
//   }

} } }

#endif
