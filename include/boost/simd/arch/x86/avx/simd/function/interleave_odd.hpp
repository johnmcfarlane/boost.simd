//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  template < typename T>
  pack<T,4,avx_>
  interleave_odd_ ( BOOST_SIMD_SUPPORTS(sse2_)
                  , pack<T,4,avx_> const& a0
                  , pack<T,4,avx_> const& a1
                  ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,4,avx_>;
    using fp_t = f_t<p_t>;
    return  bitwise_cast<p_t>(fp_t( _mm256_unpackhi_pd( bitwise_cast<fp_t>(a0)
                                                      , bitwise_cast<fp_t>(a1)
                                                      )
                                  )
                             );
  }

  template < typename T>
  pack<T,8,avx_>
  interleave_odd_ ( BOOST_SIMD_SUPPORTS(sse2_)
                  , pack<T,8,avx_> const& a0
                  , pack<T,8,avx_> const& a1
                  ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,8,avx_>;
    using fp_t = f_t<p_t>;
    auto b0 = bitwise_cast<fp_t>(a0);
    auto b1 = bitwise_cast<fp_t>(a1);
    return  bitwise_cast<p_t>(fp_t( _mm256_unpackhi_ps( _mm256_shuffle_ps(b0, b0, _MM_SHUFFLE(3,1,2,0))
                                                     , _mm256_shuffle_ps(b1, b1, _MM_SHUFFLE(3,1,2,0))
                                                     )
                                 )
                             );
  }

  template < typename T>
  pack<T,16,avx_>
  interleave_odd_ ( BOOST_SIMD_SUPPORTS(sse2_)
                  , pack<T,16,avx_> const& a0
                  , pack<T,16,avx_> const& a1
                  ) BOOST_NOEXCEPT
  {
    auto s0 = slice(a0);
    auto s1 = slice(a1);
    return  combine(interleave_odd(s0[0],s1[0]), interleave_odd(s0[1],s1[1]));
  }

  template < typename T>
  pack<T,32,avx_>
  interleave_odd_ ( BOOST_SIMD_SUPPORTS(sse2_)
                  , pack<T,32,avx_> const& a0
                  , pack<T,32,avx_> const& a1
                  ) BOOST_NOEXCEPT
  {
    auto s0 = slice(a0);
    auto s1 = slice(a1);
    return  combine(interleave_odd(s0[0],s1[0]), interleave_odd(s0[1],s1[1]));
  }

} } }

#endif
