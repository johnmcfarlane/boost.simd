//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DIST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DIST_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/function/min.hpp>
#include <type_traits>
#include <boost/simd/detail/meta/fsu_picker.hpp>

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // regular cases
   template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  sdist_( pack<T,N> const & a0
        , pack<T,N> const & a1, std::true_type const &) BOOST_NOEXCEPT //floating
  {
    return simd::abs(a0 - a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  sdist_( pack<T,N> const & a0
           , pack<T,N> const & a1, std::false_type const &) BOOST_NOEXCEPT //integral
  {
    return bs::max(a0, a1) - bs::min(a0,a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  dist_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return sdist_(a0, a1, std::is_floating_point<T>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  dist_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return dist_(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  dist_(BOOST_SIMD_SUPPORTS(simd_)
          , T const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return dist_(p_t(a0), a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  dist_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N,simd_emulation_> const & a0
          , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(dist, a0, a1);
  }


  // -----------------------------------------------------------------------------------------------
  // saturated cases
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> sdist_( pack<T,N> const& a, pack<T,N> const& b
                                    , case_<0> const& // IEEE saturated dist
                                    ) BOOST_NOEXCEPT
  {
    return dist(a, b);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> sdist_( pack<T,N> const& a, pack<T,N> const& b
                                    , case_<1> const& // signed integers saturated dist
                                    ) BOOST_NOEXCEPT
  {
    auto tmp = dist(a, b);
    return if_else(is_ltz(tmp), Valmax(as(a)), tmp);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> sdist_( pack<T,N> const& a, pack<T,N> const& b
                                    , case_<2> const& // unsigned integers saturated dist
                                    ) BOOST_NOEXCEPT
  {
    return dist(a, b);
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> dist_ ( BOOST_SIMD_SUPPORTS(simd_)
                                    , saturated_tag const&, pack<T,N> const& a, pack<T,N> const& b
                                    ) BOOST_NOEXCEPT
  {
    return sdist_ ( a, b, fsu_picker<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> dist_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                    , saturated_tag const&
                                                    , pack<T,N,simd_emulation_> const& a
                                                    , pack<T,N,simd_emulation_> const& b
                                                    ) BOOST_NOEXCEPT
  {
    return map_to( saturated_(simd::dist), a, b);
  }

  //================================================================================================
  // mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T2,M> dist_ ( BOOST_SIMD_SUPPORTS(simd_)
                   , T1 a
                   , pack<T2,M> const& b
                   ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return simd::dist(p_t(a), b);
  }

  // mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
    , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T1,N> dist_ ( BOOST_SIMD_SUPPORTS(simd_)
                   , pack<T1,N> const& a
                   , T2 b
                   ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return simd::dist(a, p_t(b));
  }

  // saturated mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T2, M> dist_ ( BOOST_SIMD_SUPPORTS(simd_)
                    , saturated_tag const&
                    , T1 a
                    , pack<T2,M> const& b
                    ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return saturated_(simd::dist)(p_t(a), b);
  }

  // saturated mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
    , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T1,N> dist_ ( BOOST_SIMD_SUPPORTS(simd_)
                   , saturated_tag const&
                   , pack<T1,N> const& a
                   , T2 b
                   ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return saturated_(simd::dist)(a, p_t(b));
  }

} } }

#endif
