//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_HMSB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_HMSB_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/bitset.hpp>
#include <boost/simd/detail/nsm.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( hmsb_
                          , (typename A0)
                          , bs::sse1_
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    // bitmask fr sub-cardinal pack
    using mask = nsm::int32_t<(1 << A0::static_size) - 1>;

    BOOST_FORCEINLINE bs::bitset<A0::static_size> operator()( const A0 & a0 ) const BOOST_NOEXCEPT
    {
      return nsm::select<nsm::bool_<A0::static_size==4>>
                        ( [&]() { return _mm_movemask_ps(a0); }
                        , [&]() { return _mm_movemask_ps(a0) & mask::value; }
                        )();
    }
  };
} } }

#endif
