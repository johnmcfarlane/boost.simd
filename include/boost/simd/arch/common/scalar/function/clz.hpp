//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CLZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CLZ_HPP_INCLUDED

#ifndef __GNUC__
#include <boost/simd/function/ffs.hpp>
#include <boost/simd/function/reversebits.hpp>
#endif
#ifdef BOOST_MSVC
#include <intrin.h>
#endif
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>
#include <type_traits>
#include <boost/simd/detail/meta/size_picker.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>  BOOST_FORCEINLINE
  as_ui_t<T> clz_( BOOST_SIMD_SUPPORTS(cpu_)
              , T a0) BOOST_NOEXCEPT ;

  template<typename T>
  BOOST_FORCEINLINE
  as_ui_t<T> sclz_(T a0, detail::case_<0> const&) BOOST_NOEXCEPT //64bits
  {
    using result_t = as_ui_t<T>;
    result_t t1 = bitwise_cast<result_t>(a0);
    BOOST_ASSERT_MSG( t1, "clz not defined for 0" );

    #ifdef __GNUC__
      return __builtin_clzll(t1);
    #else
      return ffs(reversebits(t1))-1;
    #endif
  }

  template<typename T>
  BOOST_FORCEINLINE
  as_ui_t<T> sclz_(T a0, detail::case_<1> const&) BOOST_NOEXCEPT // 32bits
  {
    using result_t = as_ui_t<T>;
    result_t t1 = bitwise_cast<result_t>(a0);
    BOOST_ASSERT_MSG( t1, "clz not defined for 0" );

    #ifdef __GNUC__
      return __builtin_clz(t1);
    #else
      return ffs(reversebits(t1))-1;
    #endif
  }

  template<typename T>
  BOOST_FORCEINLINE
  as_ui_t<T> sclz_(T a0, detail::case_<2> const&) BOOST_NOEXCEPT //16bits
  {
    using i_t = as_ui_t<T>;
    i_t t1 = bitwise_cast<i_t>(a0);
    return clz(uint32_t(t1))-16;
  }

  template<typename T>
  BOOST_FORCEINLINE
  as_ui_t<T> sclz_(T a0, detail::case_<3> const&) BOOST_NOEXCEPT //8bits
  {
      using i_t = as_ui_t<T>;
      i_t t1 = bitwise_cast<i_t>(a0);
      return clz(uint32_t(t1))-24;
  }

  template<typename T>
  BOOST_FORCEINLINE
  as_ui_t<T> clz_( BOOST_SIMD_SUPPORTS(cpu_)
              , T a0) BOOST_NOEXCEPT
  {
    return sclz_(a0, size_picker<T>());
  }

} } }


#endif
