//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_INTERLEAVE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_INTERLEAVE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/slice.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/interleave_first.hpp>
#include <boost/simd/function/interleave_second.hpp>
#include <array>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template < typename T, std::size_t N
           , typename = typename std::enable_if<std::is_integral<T>::value>
  >
  BOOST_FORCEINLINE pack<T,N,avx_>
  interleave_ ( BOOST_SIMD_SUPPORTS(avx_)
              , pack<T,N,avx_> const& a0
              , pack<T,N,avx_> const& a1
              ) BOOST_NOEXCEPT
  {
    auto x0 = slice_low(a0);
    auto y0 = slice_low(a1);
    auto f  = combine ( interleave_first(x0,y0)
                      , interleave_first( slide<N/4>(x0)
                                        , slide<N/4>(y0)
                                        )
                      );

    x0 = slice_high(a0);
    y0 = slice_high(a1);

    auto s =  combine ( interleave_first(x0,y0)
                      , interleave_first( slide<N/4>(x0)
                                        , slide<N/4>(y0)
                                        )
                      );

    std::array<pack<T,N,avx_>,2> that{{f,s}};
    return that;
  }

} } }

#endif
