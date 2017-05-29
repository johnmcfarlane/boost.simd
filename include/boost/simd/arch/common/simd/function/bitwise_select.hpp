//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_SELECT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_SELECT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_andnot.hpp>
#include <boost/simd/function/bitwise_or.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // Native implementation
  template< typename T1, std::size_t N1, typename X1
          , typename T2, std::size_t N2, typename X2
          >
  BOOST_FORCEINLINE pack<T2,N2,X1> bitwise_select_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                , pack<T1,N1,X1> const& a0
                                                , pack<T2,N2,X2> const& a1
                                                , pack<T2,N2,X2> const& a2
                                                ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof(a0) == sizeof(a1)
                  , "simd::bitwise_select - Arguments have incompatible size"
                  );

      return bitwise_or(bitwise_and(a1, a0), bitwise_andnot(a2,a0));
  }

  //================================================================================================
  // Emulated implementation
  template<typename T1, typename T2, std::size_t N, std::size_t M>
  BOOST_FORCEINLINE
  pack<T2,M,simd_emulation_> bitwise_select_ ( BOOST_SIMD_SUPPORTS(simd_)
                                          , pack<T1,N,simd_emulation_> const& a0
                                          , pack<T2,M,simd_emulation_> const& a1
                                          , pack<T2,M,simd_emulation_> const& a2
                                          ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof(a0) == sizeof(a1)
                  , "simd::bitwise_select - Arguments have incompatible size"
                  );
    using p_t = pack<T2, M, simd_emulation_>;
    return map_to( simd::bitwise_select, bitwise_cast<p_t>(a0), a1, a2);
  }

  //================================================================================================
  // mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T2,M> bitwise_select_ ( BOOST_SIMD_SUPPORTS(simd_)
                         , T1 a0
                         , pack<T2,M> const& a1
                         , pack<T2,M> const& a2
                         ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return simd::bitwise_select(p_t(a0), a1, a2);
  }

  // mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
                                     , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T1,N> bitwise_select_ ( BOOST_SIMD_SUPPORTS(simd_)
                         , pack<T1,N> const& a0
                         , T2 a1
                         , T2 a2
                         ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return simd::bitwise_select(a0, p_t(a1), p_t(a2));
  }

} } }

#endif
