//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REMQUO_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REMQUO_HPP_INCLUDED

#include <boost/simd/function/std.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <utility>
#include <cmath>

namespace boost { namespace simd { namespace detail
{

  template<typename T>
  BOOST_FORCEINLINE std::pair<T,si_t<T>>
  remquo_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a0
         , T a1) BOOST_NOEXCEPT
  {
    T d = nearbyint(a0/a1);
#if defined(BOOST_SIMD_NO_INVALIDS)
    T  a2 = is_eqz(a1) ? Nan<T>() : fma(-d, a1, a0);
#else
    T  a2 = (is_invalid(a0) || is_eqz(a1)) ? Nan<T>() : fma(-d, a1, a0);
#endif
    return {a2, toint(d)};
  }

  template<typename T>
  BOOST_FORCEINLINE std::pair<T,si_t<T>>
  remquo_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const &
         , T a0
         , T a1) BOOST_NOEXCEPT
  {
    int q;
    T r = std::remquo(a0, a1, &q);
    return {r, q};
  }

} } }

#endif
