//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_XOP_SIMD_FUNCTION_FRAC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_XOP_SIMD_FUNCTION_FRAC_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>

#if BOOST_HW_SIMD_X86_AMD_XOP
namespace boost { namespace simd { namespace detail
{
  template < typename T>
  BOOST_FORCEINLINE pack<double,2,sse_> fma_(BOOST_SIMD_SUPPORTS(sse2_)
                                            , pack<double,2,sse_> const& a0
                                            ) BOOST_NOEXCEPT
  {
    return _mm_frcz_pd(a0);
  }

  template < typename T>
  BOOST_FORCEINLINE pack<float,4,sse_> fma_(BOOST_SIMD_SUPPORTS(sse2_)
                                            pack<float,4,sse_> const& a0
                                           ) BOOST_NOEXCEPT
  {
    return _mm_frcz_ps(a0);
  }

  template < typename T>
  BOOST_FORCEINLINE pack<double,4,avx_> fma_(BOOST_SIMD_SUPPORTS(avx_)
                                            , pack<double,4,avx_> const& a0
                                            ) BOOST_NOEXCEPT
  {
    return _mm256_frcz_pd(a0);
  }

  template < typename T>
  BOOST_FORCEINLINE pack<float,8,avx_> fma_(BOOST_SIMD_SUPPORTS(avx_)
                                            pack<float,8,avx_> const& a0
                                           ) BOOST_NOEXCEPT
  {
    return _mm256_frcz_ps(a0);
  }


} } }
#endif

#endif
