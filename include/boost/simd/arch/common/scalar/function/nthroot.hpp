//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NTHROOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NTHROOT_HPP_INCLUDED
#include <boost/simd/function/raw.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/function/is_inf.hpp>
#endif
#ifndef BOOST_SIMD_NO_INVALID
#include <boost/simd/function/is_nan.hpp>
#endif
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_odd.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/pow_abs.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sign.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename U,
           typename = typename std::enable_if<std::is_integral<U>::value>
  >
  /*BOOST_FORCEINLINE*/ T
  nthroot_( BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , U a1
          ) BOOST_NOEXCEPT
  {
#ifndef BOOST_SIMD_NO_INVALID
    if (is_nan(a0)) return a0;
#endif
    auto is_ltza0 = is_ltz(a0);
    auto is_odda1 = is_odd(a1);
    if (is_ltza0 && !is_odda1) return Nan<T>();
    T x = bs::abs(a0);
    if (x == One<T>()) return a0;
    if (!a1) return (x < One<T>()) ? Zero<T>() : sign(a0)*Inf<T>();
    if (!a0) return Zero<T>();
#ifndef BOOST_SIMD_NO_INFINITIES
    if (is_inf(a0)) return (a1) ? a0 : One<T>();
#endif
    T aa1 = static_cast<T>(a1);
    T y = bs::raw_(bs::pow_abs)(x,rec(aa1));
    // Correct numerical errors (since, e.g., 64^(1/3) is not exactly 4)
    // by one iteration of Newton's method
    if (y)
    {
      T p = raw_(bs::pow_abs)(y, aa1);
      y -= (p - x) / (aa1*p/y);
    }

    return (is_ltza0 && is_odda1)? -y : y;
  }

  template<typename T, typename U
           , typename =  typename std::enable_if<std::is_integral<U>::value >
  >
  /*BOOST_FORCEINLINE*/  T
  nthroot_( BOOST_SIMD_SUPPORTS(cpu_)
          , raw_tag const &
          , T a0
          , U a1
          ) BOOST_NOEXCEPT
  {
    auto is_ltza0 = is_ltz(a0);
    auto is_odda1 = is_odd(a1);
    if (is_ltza0 && !is_odda1) return Nan<T>();
    T x = bs::abs(a0);
    if (x == One<T>()) return a0;
    if (!a1) return (x < One<T>()) ? Zero<T>() : sign(a0)*Inf<T>();
    if (!a0) return Zero<T>();
    T aa1 = static_cast<T>(a1);
    T y = raw_(bs::pow_abs)(x,rec(aa1));
    return (is_ltza0 && is_odda1)? -y : y;
  }

} } }


#endif
