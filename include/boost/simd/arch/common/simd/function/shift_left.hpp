//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // regular cases
  template<typename T,std::size_t N>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_floating_point<T>::value, pack<T, N>>::type
  shift_left_( BOOST_SIMD_SUPPORTS(simd_)
             , pack<T,N> const& v, int s
             ) BOOST_NOEXCEPT
  {
//    using type = pack<typename std::make_unsigned<T>::type,N>;
    using p_t  = pack<T,N>;

    //   BOOST_ASSERT_MSG(assert_good_shift<p_t>(s), "shift_left : shift is out of range");
    return bitwise_cast<p_t>(shift_left( bitwise_cast<si_t<p_t>>(v), s));
  }

  template< typename T, typename U, std::size_t N
            , typename X, typename Y
            , typename = typename std::enable_if<std::is_integral<U>::value>::type
  >
  BOOST_FORCEINLINE pack<T,N,X>
  shift_left_( BOOST_SIMD_SUPPORTS(simd_)
             , pack<T,N,X> const& v
             , pack<U,N,Y> const& s
             ) BOOST_NOEXCEPT
  {
    // we map_to to maximize the potential of reusing the fast (pack,int) version
    return map_to(simd::shift_left,v,s);
  }

 //  template< typename T, typename U, std::size_t N
//             , typename X
//             , typename = typename std::enable_if<std::is_integral<U>::value>::type
//   >
//   BOOST_FORCEINLINE pack<T,N,X>
//   shift_left_( BOOST_SIMD_SUPPORTS(simd_)
//              , pack<T,N,X> const& v
//              , U s
//              ) BOOST_NOEXCEPT
//   {
//     // we map_to to maximize the potential of reusing the fast (pack,int) version
//     return map_to(simd::shift_left,v,s);
//   }
} } }

#endif

