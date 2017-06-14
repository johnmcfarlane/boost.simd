//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ILOGB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ILOGB_HPP_INCLUDED

#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  // floating point
  template<typename T> BOOST_FORCEINLINE
  i_t<T> silogb_( T a0, std::true_type const&) BOOST_NOEXCEPT
  {
    return is_inf(a0) ? Valmax<si_t<T>>() : exponent(a0);
  }

  // integral
  template<typename T> BOOST_FORCEINLINE
  i_t<T> silogb_( T a0, std::false_type const&) BOOST_NOEXCEPT
  {
    return simd::ilogb(f_t<T>(a0));
  }

  template<typename T> BOOST_FORCEINLINE
  auto ilogb_( BOOST_SIMD_SUPPORTS(cpu_)
             , T a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    silogb_(a0, std::is_floating_point<T>())
  )

  // std decorator
  template<typename T,
           typename = typename std::enable_if<std::is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE
  auto ilogb_( BOOST_SIMD_SUPPORTS(cpu_)
             , std_tag const &
             , T a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    std::ilogb(a0)
  )

  // pedantic decorator
  template<typename T,
           typename = typename std::enable_if<std::is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE
  auto ilogb_( BOOST_SIMD_SUPPORTS(cpu_)
             , pedantic_tag const &
             , T a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    std::ilogb(a0)
  )


} } }


#endif
