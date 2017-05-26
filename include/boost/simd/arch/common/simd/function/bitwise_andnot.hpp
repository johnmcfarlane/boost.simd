//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED

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
  BOOST_FORCEINLINE pack<T1,N1,X1> bitwise_andnot_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                   , pack<T1,N1,X1> const& a
                                                   , pack<T2,N2,X2> const& b
                                                   ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof(a) == sizeof(b)
                  , "simd::bitwise_andnot - Arguments have incompatible size"
                  );

    return bitwise_andnot(a, simd::bitwise_cast<pack<T1,N1,X1>>(b));
  }

  //================================================================================================
  // Emulated implementation
  template<typename T1, typename T2, std::size_t N, std::size_t M>
  BOOST_FORCEINLINE
  pack<T1,N,simd_emulation_> bitwise_andnot_ ( BOOST_SIMD_SUPPORTS(simd_)
                                             , pack<T1,N,simd_emulation_> const& a
                                             , pack<T2,M,simd_emulation_> const& b
                                             ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof(a) == sizeof(b)
                  , "simd::bitwise_andnot - Arguments have incompatible size"
                  );

    return map_to( simd::bitwise_andnot, a, b);
  }

  //================================================================================================
  // mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T2,M> bitwise_andnot_ ( BOOST_SIMD_SUPPORTS(simd_)
                             , T1 a
                             , pack<T2,M> const& b
                             ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return simd::bitwise_andnot(p_t(a), b);
  }

  // mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
                                     , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T1,N> bitwise_andnot_ ( BOOST_SIMD_SUPPORTS(simd_)
                             , pack<T1,N> const& a
                             , T2 b
                             ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return simd::bitwise_andnot(a, p_t(b));
  }
} } }

#endif

