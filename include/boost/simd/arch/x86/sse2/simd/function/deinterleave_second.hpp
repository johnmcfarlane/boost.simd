//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/detail/nsm.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( deinterleave_second_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                         )
  {
    static_assert ( A0::static_size >= 2
                  , "deinterleave_first requires at least two elements"
                  );

    BOOST_FORCEINLINE A0 operator()(const A0 & a0, const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return _mm_unpackhi_pd(a0, a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( deinterleave_second_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::ints16_<A0>, bs::sse_>
                          , bs::pack_<bd::ints16_<A0>, bs::sse_>
                         )
  {
    static_assert ( A0::static_size >= 2
                  , "deinterleave_first requires at least two elements"
                  );
    static_assert ( A0::static_size >= 2
                  , "deinterleave_first requires at least two elements"
                  );

    BOOST_FORCEINLINE A0 do_(const A0& a0, const A0& a1,nsm::size_t<2> const) const BOOST_NOEXCEPT
    {
      return A0( extract<1>(a0), extract<1>(a1) );
    }

    BOOST_FORCEINLINE A0 do_(const A0& a0, const A0& a1,nsm::size_t<4> const) const BOOST_NOEXCEPT
    {
      return A0( extract<1>(a0), extract<3>(a0), extract<1>(a1), extract<3>(a1) );
    }

    BOOST_FORCEINLINE A0 do_(const A0& a0, const A0& a1,nsm::size_t<8> const) const BOOST_NOEXCEPT
    {
      auto const  x = _mm_unpacklo_epi16(a0,a1);
      auto const  y = _mm_unpackhi_epi16(a0,a1);

      return _mm_unpackhi_epi16 ( _mm_unpacklo_epi16(x,y)
                                , _mm_unpackhi_epi16(x,y)
                                );
    }

    BOOST_FORCEINLINE A0 operator()(const A0& a0, const A0& a1 ) const BOOST_NOEXCEPT
    {
      return do_(a0,a1, nsm::size_t<A0::static_size>{});
    }
  };

  BOOST_DISPATCH_OVERLOAD ( deinterleave_second_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                          , bs::pack_<bd::ints32_<A0>, bs::sse_>
                         )
  {
    static_assert ( A0::static_size >= 2
                  , "deinterleave_first requires at least two elements"
                  );

    BOOST_FORCEINLINE A0 operator()(const A0 & a0, const A0 & a1 ) const BOOST_NOEXCEPT
    {
      using f_t = bd::as_floating_t<A0>;
      return bitwise_cast<A0> ( deinterleave_second ( bitwise_cast<f_t>(a0)
                                                    , bitwise_cast<f_t>(a1)
                                                    )
                              );

    }
  };

  BOOST_DISPATCH_OVERLOAD ( deinterleave_second_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::ints64_<A0>, bs::sse_>
                          , bs::pack_<bd::ints64_<A0>, bs::sse_>
                         )
  {
    static_assert ( A0::static_size >= 2
                  , "deinterleave_first requires at least two elements"
                  );

    BOOST_FORCEINLINE A0 operator()(const A0 & a0, const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return _mm_unpackhi_epi64(a0,a1);
    }
  };
} } }

#endif
