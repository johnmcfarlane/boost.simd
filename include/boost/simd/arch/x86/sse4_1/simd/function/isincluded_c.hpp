//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_ISINCLUDED_C_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_ISINCLUDED_C_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template < typename T, std::size_t N >
  BOOST_FORCEINLINE bool
  v_isincluded_c_ ( pack<T,N,sse_> const& a0
                , pack<T,N,sse_> const& a1
                , std::false_type const &
                ) BOOST_NOEXCEPT
  {
    return _mm_testz_si128(a1, a0);
  }

  template < typename T, std::size_t N >
  BOOST_FORCEINLINE bool
  v_isincluded_c_ ( pack<T,N,sse_> const& a0
                , pack<T,N,sse_> const& a1
                , std::true_type const &
                ) BOOST_NOEXCEPT
  {
    using p_t = as_i_t<pack<T, N>>;
    return isincluded_c(bitwise_cast<p_t>(a0), bitwise_cast<p_t>(a1));
  }

  template < typename T, std::size_t N >
  BOOST_FORCEINLINE bool
  isincluded_c_ ( BOOST_SIMD_SUPPORTS(sse2_)
           , pack<T,N,sse_> const& a0
           , pack<T,N,sse_> const& a1
           ) BOOST_NOEXCEPT
  {
    return v_isincluded_c_(a0, a1, std::is_floating_point<T>());
  }


} } }

#endif

