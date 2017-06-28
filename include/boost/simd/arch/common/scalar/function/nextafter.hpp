//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXTAFTER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXTAFTER_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/next.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/prev.hpp>
#include <boost/simd/function/sign.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // regular cases
  template<typename T>
  BOOST_FORCEINLINE T
  s_nextafter_( T x
              , T y
              , detail::case_<0> const&) BOOST_NOEXCEPT
  {
    return  (y >  x)  ? next(x) : ((y <  x) ?  prev(x) : x);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  s_nextafter_( T a0
              , T a1
              , detail::case_<1> const&) BOOST_NOEXCEPT
  {
    return a0+sign(a1-a0);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  s_nextafter_(T a0
              , T a1
              , detail::case_<2> const&) BOOST_NOEXCEPT
  {
    return (a1 == a0) ? a0 : (a1 > a0) ? saturated_(inc)(a0) : saturated_(dec)(a0);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  nextafter_(BOOST_SIMD_SUPPORTS(cpu_)
             , T const& a
             , T const& b) BOOST_NOEXCEPT
  {
    return s_nextafter_(a, b, fsu_picker<T>{});
  }

  template<typename T>
  BOOST_FORCEINLINE T
  std_nextafter_( T a0
                , T a1
                , std::false_type const&) BOOST_NOEXCEPT
  {
    return next_after(a0, a1);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  std_nextafter_(T a0
                , T a1
                , std::true_type const&) BOOST_NOEXCEPT
  {
    return std::nextafter(a0, a1);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  next_after_(BOOST_SIMD_SUPPORTS(cpu_)
             , std_tag const &
             , T const& a
             , T const& b) BOOST_NOEXCEPT
  {
    return std_nextafter_(a, b, std::is_floating_point<T>{});
  }

} } }

#endif
