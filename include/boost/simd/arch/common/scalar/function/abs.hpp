//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ABS_HPP_INCLUDED

#include <boost/simd/config.hpp>
// to move elsewhere
#include <boost/simd/detail/dispatch/meta/as_unsigned.hpp>
#include <boost/simd/detail/meta/pick.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/bitwise_notand.hpp>
#include <boost/simd/function/saturate.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/config.hpp>
#include <type_traits>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // abs picker
  template<typename T>
  using abs_picker = typename detail::pick< T
                                          , tt_::is_floating_point, tt_::is_signed, tt_::is_unsigned
                                          >::type;

  //================================================================================================
  // regular cases
  template<typename T>
  BOOST_FORCEINLINE T reg_abs_(T a, detail::case_<0> const&) BOOST_NOEXCEPT
  {
    return bitwise_notand(Mzero<T>(),a);
  }

  template<typename T>
  BOOST_FORCEINLINE T reg_abs_(T a, detail::case_<1> const&) BOOST_NOEXCEPT
  {
    using utype = dispatch::as_unsigned_t<T>;

    utype mask = a >> (sizeof(T)*8 - 1);
    return (a + mask) ^ mask;
  }

  template<typename T>
  BOOST_FORCEINLINE T reg_abs_(T a, detail::case_<2> const&) BOOST_NOEXCEPT
  {
    return a;
  }

  template<typename T>
  BOOST_FORCEINLINE T abs_(BOOST_SIMD_SUPPORTS(cpu_), T const& a) BOOST_NOEXCEPT
  {
    return reg_abs_(a, abs_picker<T>{});
  }

  //================================================================================================
  // std_ decorator
  template<typename T> BOOST_FORCEINLINE T std_abs_(T a, detail::case_<0> const&) BOOST_NOEXCEPT
  {
    return std::fabs(a);
  }

  template<typename T> BOOST_FORCEINLINE T std_abs_(T a, detail::case_<1> const&) BOOST_NOEXCEPT
  {
    return std::abs(a);
  }

  template<typename T> BOOST_FORCEINLINE T std_abs_(T a, detail::case_<2> const&) BOOST_NOEXCEPT
  {
    return a;
  }

  template<typename T>
  BOOST_FORCEINLINE T abs_(BOOST_SIMD_SUPPORTS(cpu_), std_tag const&, T const& a) BOOST_NOEXCEPT
  {
    return std_abs_(a, abs_picker<T>{});
  }

  //================================================================================================
  // saturated_ decorator
  template<typename T> BOOST_FORCEINLINE T sabs_(T a, detail::case_<0> const&) BOOST_NOEXCEPT
  {
    return boost::simd::abs(a);
  }

  template<typename T> BOOST_FORCEINLINE T sabs_(T a, detail::case_<1> const&) BOOST_NOEXCEPT
  {
    return (a==Valmin<T>())?Valmax<T>():boost::simd::abs(a);
  }

  template<typename T> BOOST_FORCEINLINE T sabs_(T a, detail::case_<2> const&) BOOST_NOEXCEPT
  {
    return a;
  }

  template<typename T>
  BOOST_FORCEINLINE T abs_( BOOST_SIMD_SUPPORTS(cpu_), saturated_tag const&, T const& a) BOOST_NOEXCEPT
  {
    return sabs_(a, abs_picker<T>{});
  }
} } }

#endif
