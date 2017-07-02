//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REMQUO_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REMQUO_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/if_allbits_else.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/config.hpp>
#include <utility>

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE std::pair<pack<T,N>, as_si_t<pack<T,N>>>
  remquo_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    p_t d = nearbyint(a0/a1);

#if defined(BOOST_SIMD_NO_INVALIDS)
    p_t  a2 = if_allbits_else(is_eqz(a1),  fma(-d, a1, a0));
#else
    p_t  a2 = if_allbits_else(logical_or(is_invalid(a0), is_eqz(a1)),  fma(-d, a1, a0));
#endif
    return {a2, toint(d)};
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  remquo_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return remquo(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  remquo_(BOOST_SIMD_SUPPORTS(simd_)
          , T const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return remquo(p_t(a0), a1);
  }

// TO DO
//  template<typename T, std::size_t N>
//   BOOST_FORCEINLINE auto
//   remquo_(BOOST_SIMD_SUPPORTS(simd_)
//           , pack<T,N,simd_emulation_> const & a0
//           , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT_DECLTYPE_BODY
//   (
//     map_to(remquo, a0, a1)
//   )


} } }


#endif
