//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompnoneing file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_NONE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_NONE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/detail/constant/butsign.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

  template< typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool v_none_ (pack<T,N,sse_> const& a0
             , std::false_type const &
             ) BOOST_NOEXCEPT
  {
    return _mm_testz_si128(a0, Allbits(as(a0))); // is it bool or logical < T >
  }

  template< typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool v_none_ (pack<T,N,sse_> const& a0
             , std::true_type const &
             ) BOOST_NOEXCEPT
  {
    using p_t  = pack<T,N,sse_>;
    using ip_t = bd::as_integer_t<p_t>;
    return _mm_testz_si128(bitwise_cast<ip_t>(a0), Butsign<ip_t>());
  }

  template< typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool none_ (BOOST_SIMD_SUPPORTS(sse4_1_)
            , pack<T,N,sse_> const& a0
            ) BOOST_NOEXCEPT
  {
    return v_none_(a0, std::is_floating_point<T>());
  }

} } }

#endif
