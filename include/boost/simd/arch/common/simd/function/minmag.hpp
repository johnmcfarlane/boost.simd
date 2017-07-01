//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MINMAG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MINMAG_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_not_greater_equal.hpp>
#include <boost/simd/function/min.hpp>

namespace boost { namespace simd { namespace detail
{
  //regular
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  minmag_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    p_t aa0 = abs(a0);
    p_t aa1 = abs(a1);
        return if_else( is_not_greater_equal(aa0, aa1), a0
                      , if_else( is_not_greater_equal(aa1, aa0), a1
                               , bs::min(a0, a1) ) );
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  minmag_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return minmag(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  minmag_(BOOST_SIMD_SUPPORTS(simd_)
          , T const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return minmag(p_t(a0), a1);
  }
  // regular emulated
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  minmag_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N,simd_emulation_> const & a0
          , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(minmag, a0, a1);
  }

} } }

#endif

