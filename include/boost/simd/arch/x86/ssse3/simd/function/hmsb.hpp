//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_HMSB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_HMSB_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/detail/bitset.hpp>
#include <boost/simd/detail/nsm.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bs =  boost::simd;
  namespace bd =  boost::dispatch;

  BOOST_DISPATCH_OVERLOAD ( hmsb_
                          , (typename A0)
                          , bs::ssse3_
                          , bs::pack_<bd::ints16_<A0>, bs::sse_>
                          )
  {
    struct mask_
    {
      template<typename I, typename C>
      struct apply : nsm::ptrdiff_t< I::value < A0::static_size ? 2*I::value+1 : -1> {};
    };

    BOOST_FORCEINLINE bs::bitset<A0::static_size> operator()(const A0 & a0) const BOOST_NOEXCEPT
    {
      using s8type = typename A0::template retype<int8_t, 16>;
      return _mm_movemask_epi8(shuffle<mask_>(bitwise_cast<s8type>(a0)));
    }
  };
} } }

#endif
