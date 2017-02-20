//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_HMSB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_HMSB_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/bitset.hpp>
#include <boost/simd/detail/nsm.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bs =  boost::simd;
  namespace bd =  boost::dispatch;

  BOOST_DISPATCH_OVERLOAD ( hmsb_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::type8_<A0>, bs::sse_>
                         )
  {
    // bitmask fr sub-cardinal pack
    using mask = nsm::int32_t<(1 << A0::static_size) - 1>;

    BOOST_FORCEINLINE bs::bitset<A0::static_size> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      return nsm::select<nsm::bool_<A0::static_size==2>>
                        ( [&]() { return _mm_movemask_epi8(a0);     }
                        , [&]() { return _mm_movemask_epi8(a0) & mask::value; }
                        )();
    }
  };

  BOOST_DISPATCH_OVERLOAD ( hmsb_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE bs::bitset<A0::static_size> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      auto f = bitwise_cast<bd::as_floating_t<A0>>(a0);
      return hmsb(f);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( hmsb_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::type64_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE bs::bitset<A0::static_size> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      auto f = bitwise_cast<bd::as_floating_t<A0>>(a0);
      return nsm::select<nsm::bool_<A0::static_size==2>>
                        ( [&]() { return _mm_movemask_pd(f);     }
                        , [&]() { return _mm_movemask_pd(f) & 1; }
                        )();
    }
  };
} } }

#endif
