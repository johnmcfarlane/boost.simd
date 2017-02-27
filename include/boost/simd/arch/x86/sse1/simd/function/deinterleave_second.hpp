//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/detail/nsm.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( deinterleave_second_
                          , (typename A0)
                          , bs::sse1_
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    static_assert ( A0::static_size >= 2
                  , "deinterleave_first requires at least two elements"
                  );

    BOOST_FORCEINLINE A0 operator()(const A0 & a0, const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return nsm::select<nsm::bool_<A0::static_size==4>>
                        ( [&]() { return _mm_shuffle_ps(a0, a1, _MM_SHUFFLE(3,1,3,1)); }
                        , [&]() { return make(as_<A0>{},extract<1>(a0), extract<1>(a1)); }
                        )();
    }
  };
} } }

#endif

