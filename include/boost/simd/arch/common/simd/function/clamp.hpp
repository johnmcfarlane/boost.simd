//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CLAMP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CLAMP_HPP_INCLUDED

#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/assert.hpp>
namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> clamp_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& x
                  , pack<T,N> const& lo
                  , pack<T,N> const& hi) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(assert_all(is_less_equal(lo, hi)), "lo is not less or equal to hi");
    return bs::min(bs::max(x, lo), hi);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> clamp_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pack<T,N,simd_emulation_> const& x
                                   , pack<T,N,simd_emulation_> const& lo
                                   , pack<T,N,simd_emulation_> const& hi
                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::clamp, x, lo, hi);
  }

  //================================================================================================
  // pedantic_ decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> clamp_(BOOST_SIMD_SUPPORTS(simd_)
                  , pedantic_tag const &
                  , pack<T,N> const& x
                  , pack<T,N> const& lo
                  , pack<T,N> const& hi) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(assert_all(is_less_equal(lo, hi)), "lo is not less or equal to hi");
    return if_else(x < lo, lo, if_else(hi < x, hi, x));
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> clamp_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pedantic_tag const &
                                   , pack<T,N,simd_emulation_> const& x
                                   , pack<T,N,simd_emulation_> const& lo
                                   , pack<T,N,simd_emulation_> const& hi
                                   ) BOOST_NOEXCEPT
  {
    return map_to(pedantic_(simd::clamp), x, lo, hi);
  }

  // mixed implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> clamp_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& x
                  , T const& lo
                  , T const& hi) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    BOOST_ASSERT_MSG(is_less_equal(lo, hi), "lo is not less or equal to hi");
    return bs::min(bs::max(x, p_t(lo)), p_t(hi));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> clamp_(BOOST_SIMD_SUPPORTS(simd_)
                  , T const& x
                  , pack<T,N> const& lo
                  , T const& hi) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    BOOST_ASSERT_MSG(assert_all(is_less_equal(lo, p_t(hi))), "lo is not less or equal to hi");
    return bs::min(bs::max(p_t(x), lo), p_t(hi));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> clamp_(BOOST_SIMD_SUPPORTS(simd_)
                  , T const& x
                  , T const& lo
                  , pack<T,N> const& hi) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    BOOST_ASSERT_MSG(assert_all(is_less_equal(p_t(lo), hi)), "lo is not less or equal to hi");
    return bs::min(bs::max(p_t(x), p_t(lo)), hi);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> clamp_(BOOST_SIMD_SUPPORTS(simd_)
                  , T const& x
                  , pack<T,N> const& lo
                  , pack<T,N> const& hi) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    BOOST_ASSERT_MSG(assert_all(is_less_equal(lo, hi)), "lo is not less or equal to hi");
    return bs::min(bs::max(p_t(x), lo), hi);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> clamp_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& x
                  ,T const& lo
                  , pack<T,N> const& hi) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    BOOST_ASSERT_MSG(assert_all(is_less_equal(p_t(lo), hi)), "lo is not less or equal to hi");
    return bs::min(bs::max(x, p_t(lo)), hi);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> clamp_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& x
                  , pack<T,N> const& lo
                  , T const& hi) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    BOOST_ASSERT_MSG(assert_all(is_less_equal(lo, hi)), "lo is not less or equal to hi");
    return bs::min(bs::max(x, lo), p_t(hi));
  }

} } }

#endif
