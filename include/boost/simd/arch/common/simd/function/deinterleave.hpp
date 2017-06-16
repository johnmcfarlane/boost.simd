//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DEINTERLEAVE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DEINTERLEAVE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/deinterleave_first.hpp>
#include <boost/simd/function/deinterleave_second.hpp>
#include <array>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE  std::array<pack<T,N,X>,2>
  deinterleave_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N,X> const & x
          , pack<T,N,X> const & y) BOOST_NOEXCEPT
  {
    static_assert ( N >= 2
                  , "deinterleave requires at least two elements"
                  );
    std::array<pack<T,N,X>,2> that{{ deinterleave_first(x,y), deinterleave_second(x,y) }};
    return that;

  }

} } }

#endif
