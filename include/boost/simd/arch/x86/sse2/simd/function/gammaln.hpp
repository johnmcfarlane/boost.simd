//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_GAMMALN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_GAMMALN_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/gammaln.hpp>

namespace boost { namespace simd { namespace detail
{
  namespace bs = boost::simd;
  BOOST_FORCEINLINE pack<double,2> gammaln_( BOOST_SIMD_SUPPORTS(sse2_)
                                           , pack<double,2> const& a0
                                           ) BOOST_NOEXCEPT
  {
    using result_t = pack<double,2>;
    return result_t(bs::gammaln(double(a0[0])),  bs::gammaln(double(a0[1])));
  }

} } }

#endif
