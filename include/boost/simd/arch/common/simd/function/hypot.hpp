//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_HYPOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_HYPOT_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/detail/constant/maxexponentm1.hpp>
#include <boost/simd/detail/constant/minexponent.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/predef/architecture.h>

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/constant/inf.hpp>
#endif

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  hypot_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
      return simd::sqrt(simd::fma(a0, a0, sqr(a1)));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  hypot_(BOOST_SIMD_SUPPORTS(simd_)
          , pedantic_tag const &
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    auto r =  bs::abs(a0);
    auto i =  bs::abs(a1);
    auto e =  exponent(bs::max(i, r));
    e = bs::min(bs::max(e,Minexponent<p_t>()),Maxexponentm1<p_t>());
    auto res =  pedantic_(ldexp)(sqrt(sqr(pedantic_(ldexp)(r, -e))
                                      +sqr(pedantic_(ldexp)(i, -e))), e);

#ifndef BOOST_SIMD_NO_INVALIDS
    auto test = logical_or(logical_and(is_nan(a0), is_inf(a1)),
                           logical_and(is_nan(a1), is_inf(a0)));
    auto v = if_else(test, Inf<p_t>(), res);
    return v;
#else
    return res;
#endif
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  hypot_(BOOST_SIMD_SUPPORTS(simd_)
        , std_tag const &
        , pack<T,N> const & a0
        , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return map_to(std_(hypot), a0, a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  hypot_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const & a0
        , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return hypot_(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  hypot_(BOOST_SIMD_SUPPORTS(simd_)
        , T const & a0
        , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return hypot_(p_t(a0), a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  hypot_(BOOST_SIMD_SUPPORTS(simd_)
        , pedantic_tag const &
        , pack<T,N> const & a0
        , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return hypot_(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  hypot_(BOOST_SIMD_SUPPORTS(simd_)
        , pedantic_tag const &
        , T const & a0
        , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return hypot_(p_t(a0), a1);
  }


  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  hypot_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N,simd_emulation_> const & a0
        , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(hypot, a0, a1);
  }

} } }

#endif

