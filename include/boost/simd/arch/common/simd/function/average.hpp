//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_AVERAGE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_AVERAGE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  saverage_( pack<T,N> const & a0
           , pack<T,N> const & a1, std::true_type const &) BOOST_NOEXCEPT
  {
    return fma(a0,Half(as(a0)),a1*Half(as(a0)));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  saverage_( pack<T,N> const & a0
           , pack<T,N> const & a1, std::false_type const &) BOOST_NOEXCEPT
  {
    return  bitwise_and(a0, a1)+shift_right(bitwise_xor(a0, a1),1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  average_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return saverage_(a0, a1, std::is_floating_point<T>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  average_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return average_(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  average_(BOOST_SIMD_SUPPORTS(simd_)
          , T const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return average_(p_t(a0), a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  average_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N,simd_emulation_> const & a0
          , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(average, a0, a1);
  }


} } }


#endif
