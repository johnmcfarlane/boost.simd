//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MINMOD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MINMOD_HPP_INCLUDED

#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/is_nltz.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{

  template<typename T> BOOST_FORCEINLINE
  T sminmod_( T a0, T a1
          , detail::case_<0> const& ) BOOST_NOEXCEPT// IEEE case
  {
     return is_nltz(a0*a1) ? simd::min(a0,a1) : Zero<T>();
  }

  template<typename T> BOOST_FORCEINLINE // signed integral case
  T sminmod_ ( T  a0, T  a1
             , detail::case_<1> const&
             ) BOOST_NOEXCEPT
  {
    return is_gez(bitwise_xor(a0, a1)) ? simd::min(a0, a1): Zero<T>();
  }

  template<typename T> BOOST_FORCEINLINE
  T sminmod_( T a0, T& a1
            , detail::case_<2> const& ) BOOST_NOEXCEPT // unsigned integral case
  {
    return simd::min(a0,a1);
  }

  template<typename T>
  BOOST_FORCEINLINE
  T minmod_(BOOST_SIMD_SUPPORTS(cpu_)
           , T  a
           , T  b) BOOST_NOEXCEPT
  {
    return sminmod_ ( a ,b, fsu_picker<T>());
  }

} } }


#endif
