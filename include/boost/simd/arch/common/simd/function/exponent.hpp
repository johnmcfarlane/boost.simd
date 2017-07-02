//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPONENT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPONENT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/if_minus.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_invalid.hpp>
#endif
#if defined(__INTEL_COMPILER) && defined(BOOST_SIMD_HAS_AVX_SUPPORT) && !defined(BOOST_SIMD_HAS_AVX2_SUPPORT)
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/minus.hpp>
#endif


namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_si_t<pack<T, N>> vexponent_(pack<T,N> const& a0
                            , std::true_type const &) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    using r_t = as_si_t<pack<T, N>>;
    //computes exponent bits
    using sint_type = as_si_t<T>;
    const sint_type me = Maxexponent<T>();
    const sint_type nmb = Nbmantissabits<T>();
    const r_t Mask =r_t((2*me+1)<<nmb);
    r_t exponentbits = bitwise_and(Mask, a0);

    r_t x = shr(exponentbits, nmb);
    // workaround for ICC 14.0.3, tested on AVX
#if defined(__INTEL_COMPILER) && defined(BOOST_SIMD_HAS_AVX_SUPPORT) && !defined(BOOST_SIMD_HAS_AVX2_SUPPORT)
    x = x - if_else(a0, Maxexponent<p_t>(), Zero<r_t>());
#else
    x = if_minus(a0, x, Maxexponent<p_t>());
#endif
#ifndef BOOST_SIMD_NO_INVALIDS
    return if_zero_else( is_invalid(a0), x );
#else
    return x;
#endif
  }

  template<typename T, std::size_t N >
  BOOST_FORCEINLINE
  as_si_t<pack<T, N>> vexponent_( pack<T,N> const& a
                       , std::false_type) BOOST_NOEXCEPT
  {
    return Zero<as_si_t<pack<T, N>>>();
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_si_t<pack<T, N>>  exponent_(BOOST_SIMD_SUPPORTS(cpu_)
                            , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vexponent_(a, std::is_floating_point<T>());
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  as_si_t<pack<T,N,X>> exponent_( BOOST_SIMD_SUPPORTS(simd_)
                   , std_tag const&
                   , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::exponent), a);
  }
} } }

#endif

