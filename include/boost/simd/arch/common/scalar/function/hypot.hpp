//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_HYPOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_HYPOT_HPP_INCLUDED
#include <boost/simd/function/pedantic.hpp>


#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_nan.hpp>
#endif
#include <boost/simd/detail/constant/maxexponentm1.hpp>
#include <boost/simd/detail/constant/minexponent.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE T
  hypot_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , T a1) BOOST_NOEXCEPT
  {
    return simd::sqrt(simd::fma(a0, a0, sqr(a1)));
  }

  template<typename T>
  BOOST_FORCEINLINE T
  hypot_(BOOST_SIMD_SUPPORTS(cpu_)
        , pedantic_tag const &
        , T a0
        , T a1) BOOST_NOEXCEPT
  {
      #ifndef BOOST_SIMD_NO_INVALIDS
      if (is_nan(a0) && is_inf(a1)) return Inf<T>();
      if (is_inf(a0) && is_nan(a1)) return Inf<T>();
      #endif
      auto r =  bs::abs(a0);
      auto i =  bs::abs(a1);
      auto e =  exponent(bs::max(i, r));
      e = bs::min(bs::max(e,Minexponent<T>()),Maxexponentm1<T>());
      return bs::pedantic_(ldexp)(sqrt(sqr(bs::pedantic_(ldexp)(r, -e))
                                       +sqr(bs::pedantic_(ldexp)(i, -e))), e);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  hypot_(BOOST_SIMD_SUPPORTS(cpu_)
        , std_tag const &
        , T a0
        , T a1) BOOST_NOEXCEPT
  {
    return std::hypot(a0, a1);
  }

} } }


#endif
