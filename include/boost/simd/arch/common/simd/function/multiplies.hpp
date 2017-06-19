//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/group.hpp>
#include <boost/simd/function/split_multiplies.hpp>
#include <boost/simd/detail/dispatch/meta/upgrade.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  // regular case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  multiplies_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return map_to(multiplies, a0, a1);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  multiplies_ ( BOOST_SIMD_SUPPORTS(simd_)
              , saturated_tag const&
              , pack<T,N,simd_emulation_> const& a
              , pack<T,N,simd_emulation_> const& b
              ) BOOST_NOEXCEPT
  {
    return map_to( saturated_(simd::multiplies), a, b);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  vsmultiplies_( pack<T,N> const & a0
               , pack<T,N> const & a1
               , std::false_type const &) BOOST_NOEXCEPT
  {
    return simd::multiplies(a0, a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  multiplies_(BOOST_SIMD_SUPPORTS(simd_)
          , const saturated_tag&
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return vsmultiplies_(a0, a1, nsm::bool_<std::is_integral<T>::value &&
                                            bd::is_upgradable<T>::value>()
                        );
  }

  // mixed cases
  // regular
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  multiplies_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , U const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return multiplies(a0, p_t(a1));
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  multiplies_(BOOST_SIMD_SUPPORTS(simd_)
          , U const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return multiplies(p_t(a0), a1);
  }

  // saturated
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  multiplies_(BOOST_SIMD_SUPPORTS(simd_)
             , const saturated_tag&
             , pack<T,N> const & a0
             , U const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return multiplies(a0, p_t(a1));
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  multiplies_(BOOST_SIMD_SUPPORTS(simd_)
           , const saturated_tag&
             , U const & a0
             , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return multiplies(p_t(a0), a1);
  }

} } }

#endif
