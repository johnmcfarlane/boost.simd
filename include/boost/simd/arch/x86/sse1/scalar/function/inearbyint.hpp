//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SCALAR_FUNCTION_INEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SCALAR_FUNCTION_INEARBYINT_HPP_INCLUDED

#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/is_nan.hpp>

namespace boost { namespace simd { namespace detail
{

  template<std::size_t N>
  BOOST_FORCEINLINE  std::int32_t
  inearbyint_(BOOST_SIMD_SUPPORTS(sse1_)
             ,float a0) BOOST_NOEXCEPT
  {
    return _mm_cvtss_si32(_mm_set_ss(a0));
  }

  template<std::size_t N>
  BOOST_FORCEINLINE  std::int32_t
  inearbyint_(BOOST_SIMD_SUPPORTS(sse1_)
             , pedantic_tag const &
             , float a0) BOOST_NOEXCEPT
  {
    if (BOOST_UNLIKELY(is_nan(a0))) return Zero<std::int32_t>();
    if (BOOST_UNLIKELY(a0 == Inf<float>())) return Valmax<std::int32_t>();
    return _mm_cvtss_si32(_mm_set_ss(a0));
  }

} } }

#endif
