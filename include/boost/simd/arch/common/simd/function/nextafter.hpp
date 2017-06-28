//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEXTAFTER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEXTAFTER_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/next.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/prev.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  s_nextafter_( pack<T,N> const & a0
              , pack<T,N> const & a1
              , std::true_type const &) BOOST_NOEXCEPT
  {
    return if_else(is_less(a0, a1), next(a0)
                  , if_else(is_equal(a0, a1),  a0, prev(a0)));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  s_nextafter_( pack<T,N> const & a0
              , pack<T,N> const & a1
              , std::false_type const &) BOOST_NOEXCEPT
  {
    return  if_else(bs::is_equal(a0,a1), a0,
                    if_else(is_greater(a1,a0)
                           , saturated_(inc)(a0)
                           , saturated_(dec)(a0)
                           )
                   );
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  nextafter_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return s_nextafter_(a0, a1, std::is_floating_point<T>());
  }


  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  nextafter_(BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N> const & a0
            , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return nextafter_(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  nextafter_(BOOST_SIMD_SUPPORTS(simd_)
            , T const & a0
            , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return nextafter_(p_t(a0), a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  nextafter_(BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N,simd_emulation_> const & a0
            , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(nextafter, a0, a1);
  }

} } }

#endif

