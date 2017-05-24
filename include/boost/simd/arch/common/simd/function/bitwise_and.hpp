//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // Native implementation
  template< typename T1, std::size_t N1, typename X1
          , typename T2, std::size_t N2, typename X2
          >
  BOOST_FORCEINLINE pack<T1,N1,X1> bitwise_and_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                , pack<T1,N1,X1> const& a
                                                , pack<T2,N2,X2> const& b
                                                ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof(a) == sizeof(b)
                  , "simd::bitwise_and - Arguments have incompatible size"
                  );

    return bitwise_and(a, simd::bitwise_cast<pack<T1,N1,X1>>(b));
  }

  //================================================================================================
  // Emulated implementation
  template<typename T1, typename T2, std::size_t N, std::size_t M>
  BOOST_FORCEINLINE
  pack<T1,N,simd_emulation_> bitwise_and_ ( BOOST_SIMD_SUPPORTS(simd_)
                                          , pack<T1,N,simd_emulation_> const& a
                                          , pack<T2,M,simd_emulation_> const& b
                                          ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof(a) == sizeof(b)
                  , "simd::bitwise_and - Arguments have incompatible size"
                  );

    return map_to( simd::bitwise_and, a, b);
  }
} } }

#endif

