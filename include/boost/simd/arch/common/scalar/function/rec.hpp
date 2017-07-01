//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/sign.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

#ifdef BOOST_MSVC
  #pragma warning(push)
  #pragma warning(disable: 4723) // potential divide by 0
#endif

  template<typename T> BOOST_FORCEINLINE T
  srec_( T a
       , case_<0> const&) BOOST_NOEXCEPT
  {
    return One<T>()/a;
  }

  template<typename T> BOOST_FORCEINLINE T
  srec_( T a0
       , case_<1> const&) BOOST_NOEXCEPT
  {
    return (a0 ? ((bs::abs(a0) == One<T>()) ? sign(a0) : Zero<T>()) : Valmax<T>());
  }

  template<typename T> BOOST_FORCEINLINE T
  srec_( T a0
       , case_<2> const&) BOOST_NOEXCEPT
  {
    return (a0 ? ((a0 == One<T>()) ? a0 : Zero<T>()) : Valmax<T>());
  }

  template<typename T>
  BOOST_FORCEINLINE T
  rec_( BOOST_SIMD_SUPPORTS(cpu_)
      , T a) BOOST_NOEXCEPT
  {
    return srec_(a, fsu_picker<T>{});
  }

  template<typename T>
  BOOST_FORCEINLINE T
  rec_( BOOST_SIMD_SUPPORTS(cpu_)
      , raw_tag const&, T a) BOOST_NOEXCEPT
  {
    return rec(a);
  }

} } }

#ifdef BOOST_MSVC
  #pragma warning(pop)
#endif

#endif
