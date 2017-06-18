//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/mata/convert_helpers.hpp>
#include <boost/simd/detail/mata/size_picker.hpp>

namespace boost { namespace simd { namespace ext
{

  BOOST_FORCEINLINE
  as_logical_t<pack<int64_t,4,avx_>>
  v_is_greater_( pack<int64_t,4,avx_> const& a0
               , pack<int64_t,4,avx_> const& a1
               , case_<0> const &
               ) BOOST_NOEXCEPT
  {
    return _mm256_cmpgt_epi64(a0,a1);
  }

  BOOST_FORCEINLINE
  as_logical_t<pack<int32_t,8,avx_>>
  v_is_greater_( pack<int32_t,8,avx_> const& a0
               , pack<int32_t,8,avx_> const& a1
               , case_<0> const &
               ) BOOST_NOEXCEPT
  {
    return _mm256_cmpgt_epi32(a0,a1);
  }

  BOOST_FORCEINLINE
  as_logical_t<pack<int16_t,16,avx_>>
  v_is_greater_( pack<int16_t,16,avx_> const& a0
               , pack<int16_t,16,avx_> const& a1
               , case_<0> const &
               ) BOOST_NOEXCEPT
  {
    return _mm256_cmpgt_epi16(a0,a1);
  }

  BOOST_FORCEINLINE
  as_logical_t<pack<int8_t,32,avx_>>
  v_is_greater_( pack<int8_t,32,avx_> const& a0
               , pack<int8_t,32,avx_> const& a1
               , case_<0> const &
               ) BOOST_NOEXCEPT
  {
    return _mm256_cmpgt_epi8(a0,a1);
  }

  template < typename T,  std::size_t N>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_signed<T>, as_logical_t<pack<T,N,avx_>>>::type
  is_greater_( BOOST_SIMD_SUPPORTS(avx2_)
             , pack<T,N,avx_> const& a0
             , pack<T,N,avx_> const& a1
             ) BOOST_NOEXCEPT
  {
    return v_is_greater_(a0, a1, size_picker<T>());
  }

  template < typename T,  std::size_t N>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_unsigned<T>, as_logical_t<pack<T,N,avx_>>>::type
  is_greater_( BOOST_SIMD_SUPPORTS(avx2_)
             , pack<T,N,avx_> const& a0
             , pack<T,N,avx_> const& a1
             ) BOOST_NOEXCEPT
  {
    using r_t = as_logical_t<pack<T,N,avx_>>;
    using s_t = si_t<pack<T,N,avx_>>;
    auto const m = Signmask<s_t>();
    return bitwise_cast<result>((bitwise_cast<s_t>(a0) - m) > (bitwise_cast<s_t>(a1) - m));
  }

} } }

#endif
