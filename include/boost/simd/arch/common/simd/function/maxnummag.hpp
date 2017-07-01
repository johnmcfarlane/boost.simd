//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MAXNUMMAG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MAXNUMMAG_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/maxmag.hpp>

namespace boost { namespace simd { namespace detail
{
  //regular
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_maxnummag_( pack<T,N> const & a0
              , pack<T,N> const & a1
              , std::true_type const &) BOOST_NOEXCEPT
  {
    return maxmag(if_else(is_nan(a0),a1,a0), a1);
  }
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_maxnummag_( pack<T,N> const & a0
              , pack<T,N> const & a1
              , std::false_type const &) BOOST_NOEXCEPT
  {
    return  maxmag(a0, a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  maxnummag_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return v_maxnummag_(a0, a1, std::is_floating_point<T>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  maxnummag_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return maxnummag(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  maxnummag_(BOOST_SIMD_SUPPORTS(simd_)
          , T const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return maxnummag(p_t(a0), a1);
  }
  // regular emulated
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  maxnummag_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N,simd_emulation_> const & a0
          , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(maxnummag, a0, a1);
  }

} } }

#endif
