//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ACOS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ACOS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/acos.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<double,2,sse_>
  acos_( BOOST_SIMD_SUPPORTS(sse2_)
       , pack<double,2,sse_> const& a0
       ) BOOST_NOEXCEPT
  {
    using result_t = pack<double,2,sse_>;
    return result_t(simd::acos(double(a0[0]))
                   , simd::acos(double(a0[1])));
  }

  BOOST_FORCEINLINE pack<double,2,sse_>
  acos_( BOOST_SIMD_SUPPORTS(sse2_)
       , pedantic_tag const &
       , pack<double,2,sse_> const& a0
       ) BOOST_NOEXCEPT
  {
    using result_t = pack<double,2>;
    return  result_t(simd::pedantic_(simd::acos)(double(a0[0]))
                    , simd::pedantic_(simd::acos)(double(a0[1])));
  }


} } }


#endif
