//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_NTHROOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_NTHROOT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/nthroot.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template < typename T,
             typename =  typename std::enable_if<std::is_integral<T>::value>
  >
  BOOST_FORCEINLINE pack<double,2, sse_>
  nthroot_( BOOST_SIMD_SUPPORTS(sse2_)
          , pack<double,2, sse_> const& a0
          , pack<T,2, sse_> const & a1
          ) BOOST_NOEXCEPT
  {
    using result_t = pack<double,2, sse_>;
    return result_t( nthroot(double(a0[0]), T(a1[0]))
                   , nthroot(double(a0[1]), T(a1[1])));
  }

  template < typename T,
             typename =  typename std::enable_if<std::is_integral<T>::value>
  >
  BOOST_FORCEINLINE pack<double,2, sse_>
  nthroot_( BOOST_SIMD_SUPPORTS(sse2_)
          , raw_tag const &
          , pack<double,2, sse_> const& a0
          , pack<T,2, sse_> const & a1
          ) BOOST_NOEXCEPT
  {
    using result_t = pack<double,2, sse_>;
    return result_t(raw_(nthroot)(double(a0[0]), T(a1[0]))
                   , raw_(nthroot)(double(a0[1]),T(a1[1])));
  }

} } }

#endif
