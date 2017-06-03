//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DIST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DIST_HPP_INCLUDED

#include <boost/simd/function/abs.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE T
  sdist_( T a0
        , T a1, std::true_type const &) BOOST_NOEXCEPT
  {
     return bs::abs(a0 - a1);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  sdist_( T a0
        , T a1, std::false_type const &) BOOST_NOEXCEPT
  {
    return (a0>a1) ? a0-a1 : a1-a0;
  }
  template<typename T>
  BOOST_FORCEINLINE T
  dist_(BOOST_SIMD_SUPPORTS(cpu_)
       , T a0
       , T a1) BOOST_NOEXCEPT
  {
    return sdist_(a0, a1, std::is_floating_point<T>());
  }

  // -----------------------------------------------------------------------------------------------
  // Saturated cases

  template<typename T> BOOST_FORCEINLINE
  T sdist_( T a, T& b
          , detail::case_<0> const& ) BOOST_NOEXCEPT// IEEE case
  {
    return dist(a, b);
  }

  template<typename T> BOOST_FORCEINLINE // signed integral case
  T sdist_ ( T  a, T  b
           , detail::case_<1> const&
           ) BOOST_NOEXCEPT
  {
    auto tmp = dist(a, b);
    return tmp < Zero(as(a)) ? Valmax(as(a)) : tmp;
  }

  template<typename T> BOOST_FORCEINLINE
  T sdist_( T a, T& b
          , detail::case_<2> const& ) BOOST_NOEXCEPT // unsigned integral case
  {
    return dist(a, b);
  }

  template<typename T>
  BOOST_FORCEINLINE
  T dist_(BOOST_SIMD_SUPPORTS(cpu_)
         , saturated_tag const&
         , T  a
         , T  b) BOOST_NOEXCEPT
  {
    return sdist_ ( a ,b, fsu_picker<T>());
   }

} } }

#endif
