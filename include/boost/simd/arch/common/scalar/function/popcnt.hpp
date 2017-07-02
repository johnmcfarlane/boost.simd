//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_POPCNT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_POPCNT_HPP_INCLUDED

#ifdef BOOST_MSVC
#include <intrin.h>
#endif
#include <boost/simd/function/hi.hpp>
#include <boost/simd/function/lo.hpp>
#include <boost/simd/function/sbits.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <type_traits>
#include <boost/simd/detail/meta/size_picker.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{

  template<typename T>  BOOST_FORCEINLINE
  as_ui_t<T> s1_popcnt_(T a0
                    , detail::case_<0> const&) BOOST_NOEXCEPT // 64bits
  {
#if defined BOOST_MSVC && defined _WIN64
    return __popcnt64(a0);
#elif defined BOOST_MSVC
    return  __popcnt( hi(a0) )
      + __popcnt( lo(a0) );
#else
    return  __builtin_popcount( hi(a0) )
      + __builtin_popcount( lo(a0) );
#endif
  }

  template<typename T>
  BOOST_FORCEINLINE
  as_ui_t<T> s1_popcnt_(T a0
                    , detail::case_<1> const&) BOOST_NOEXCEPT // 32bits
  {
#ifdef BOOST_MSVC
    return __popcnt(a0);
#else
    return __builtin_popcount(a0);
#endif
  }

  template<typename T>
  BOOST_FORCEINLINE
  as_ui_t<T> s1_popcnt_(T a0
                    , detail::case_<2> const&) BOOST_NOEXCEPT //16bits
  {
#ifdef BOOST_MSVC
    return __popcnt16(a0);
#else
    return __builtin_popcount(int32_t(a0) & 0xFFFF);
#endif

  }

  template<typename T>
  BOOST_FORCEINLINE
  as_ui_t<T> s1_popcnt_(T a0
                    , detail::case_<3> const&) BOOST_NOEXCEPT //8bits
  {
#ifdef BOOST_MSVC
    return __popcnt16(int16_t(a0) & 0xFF);
#else
    return __builtin_popcount(int32_t(a0) & 0xFF);
#endif
  }


  template<typename T>
  BOOST_FORCEINLINE  as_ui_t<T> //floating
  s0_popcnt_( T a0
            , std::true_type const & ) BOOST_NOEXCEPT
  {
    return s1_popcnt_(sbits(a0), size_picker<T>());
  }

  template<typename T>
  BOOST_FORCEINLINE  as_ui_t<T> //integers
  s0_popcnt_( T a0
            , std::false_type const & ) BOOST_NOEXCEPT
  {
    return s1_popcnt_(a0, size_picker<T>());
  }

  template<typename T>
  BOOST_FORCEINLINE
  as_ui_t<T> popcnt_( BOOST_SIMD_SUPPORTS(cpu_)
                 , T a0) BOOST_NOEXCEPT
  {
    return s0_popcnt_(a0, std::is_floating_point<T>());
  }

} } }


#endif
