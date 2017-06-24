//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TENPOWER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TENPOWER_HPP_INCLUDED

#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exp10.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_odd.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>


namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular cases
  template<typename T>
  BOOST_FORCEINLINE T
  s_tenpower_(T a, detail::case_<0> const&) BOOST_NOEXCEPT
  {
    return exp10(a);
  }

  template<typename T>
  BOOST_FORCEINLINE f_t<T>
  s_tenpower_(T expo, detail::case_<1> const&) BOOST_NOEXCEPT
  {
    using r_t =  f_t<T>;

    r_t result = One<r_t>();
    r_t base = Ten<r_t>();
    auto neg = is_ltz(expo);
    expo = simd::abs(expo);
    while(expo)
    {
      if (is_odd(expo)) result *= base;
      expo >>= 1;
      base = sqr(base);
    }
    return neg ? rec(result) : result;
  }

  template<typename T>
  BOOST_FORCEINLINE T
  s_tenpower_(T expo, detail::case_<2> const&) BOOST_NOEXCEPT
  {
    using r_t =  f_t<T>;

    r_t result = One<r_t>();
    r_t base = Ten<r_t>();
    while(expo)
    {
      if (is_odd(expo)) result *= base;
      expo >>= 1;
      base = sqr(base);
    }
    return result;
  }

  template<typename T>
  BOOST_FORCEINLINE f_t<T>
  tenpower_(BOOST_SIMD_SUPPORTS(cpu_)
                          , T a) BOOST_NOEXCEPT
  {
    return s_tenpower_(a, fsu_picker<T>{});
  }

} } }


#endif
