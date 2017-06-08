//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FMA_HPP_INCLUDED


#include <boost/simd/function/std.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/function/sign.hpp>
#include <boost/simd/function/two_add.hpp>
#include <boost/simd/function/two_prod.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <tuple>
#include <boost/simd/detail/meta/fsu_picker.hpp>

namespace boost { namespace simd { namespace detail
{
  //==========================================================================
  //regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE T
  fma_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , T a1
          , T a2 ) BOOST_NOEXCEPT
  {
    return a0*a1+a2;
  }

  template<typename T
           , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE T
  fma_(BOOST_SIMD_SUPPORTS(cpu_)
      , std_tag const&
      , T a0
      , T a1
      , T a2 ) BOOST_NOEXCEPT
  {
    return std::fma(a0, a1, a2);
  }
  //==========================================================================
  //pedantic_ decorator
  BOOST_FORCEINLINE float
  fma_(BOOST_SIMD_SUPPORTS(cpu_)
      , pedantic_tag const &
      , float a0
      , float a1
      , float a2 ) BOOST_NOEXCEPT
  {
    return static_cast<float>( static_cast<double>(a0)*static_cast<double>(a1)
                               + static_cast<double>(a2)
                             );
  }

  BOOST_FORCEINLINE double
  fma_(BOOST_SIMD_SUPPORTS(cpu_)
      , pedantic_tag const &
      , double a0
      , double a1
      , double a2 ) BOOST_NOEXCEPT
  {
    double p, rp, s, rs;
#ifndef BOOST_SIMD_DONT_CARE_FMA_OVERFLOW
    auto e0 = bs::exponent(a0);
    auto e1 = bs::exponent(a1);
    auto e = -bs::max(e0, e1)/2;
    double ae2  = bs::ldexp(a2, e);
    auto choose = (e0 > e1);
    double amax = choose ? ldexp(a0, e) : ldexp(a1, e);
    double amin = choose ? a1 : a0;
    std::tie(p, rp) = two_prod(amax, amin);
    std::tie(s, rs) = two_add(p, ae2);
    return ldexp(s+(rp+rs), -e);
#else
    std::tie(p, rp) = two_prod(a0, a1);
    std::tie(s, rs) = two_add(p, a2);
    return s+(rp+rs);
#endif
  }

  template<typename T >
  BOOST_FORCEINLINE T
  ifma_( T a0
       , T a1
       , T a2, std::true_type const &) BOOST_NOEXCEPT
  {
    // correct fma has to ensure "no intermediate overflow".
    // This is done in the case of signed integers by transtyping to unsigned type
    // to perform the computations in a guaranted 2-complement environment
    // since signed integer overflows in C++ produce "undefined results"
    using u_t = bd::as_integer_t<T, unsigned>;
    return T(fma(u_t(a0), u_t(a1), u_t(a2)));
  }

  template<typename T >
  BOOST_FORCEINLINE T
  ifma_( T a0
       , T a1
       , T a2, std::false_type const &) BOOST_NOEXCEPT
  {
    return a0*a1+a2;
  }

  template<typename T >
  BOOST_FORCEINLINE T
  fma_(BOOST_SIMD_SUPPORTS(cpu_)
      , pedantic_tag const &
      , T a0
      , T a1
      , T a2 ) BOOST_NOEXCEPT
  {
    return ifma_(a0, a1, a2, std::is_signed<T>());
  }
} } }

#endif
