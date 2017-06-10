//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TRUNC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TRUNC_HPP_INCLUDED

#include <boost/simd/detail/constant/maxflint.hpp>
#include <boost/simd/function/pack_cast.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T strunc_( T const& a0, std::true_type const &) BOOST_NOEXCEPT
  {
    // this is incorrect for double < Maxflint < T >  and > Valmax < int32_t >
    // TODO if architectures dont provide
    return  bs::abs(a0) < Maxflint<T>() ? raw_(trunc)(a0) : a0;
  }

  template<typename T>
  BOOST_FORCEINLINE
  T strunc_( T const& a0, std::false_type const &) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T>
  BOOST_FORCEINLINE
  T trunc_(BOOST_SIMD_SUPPORTS(cpu_)
                 , T const& a0) BOOST_NOEXCEPT
  {
    return strunc_(a0, std::is_floating_point<T>());
  }

  //================================================================================================
  // std decorator
  template<typename T
           ,   typename = typename std::enable_if<is_floating_point<T>::value>::type>
  BOOST_FORCEINLINE
  auto trunc_(BOOST_SIMD_SUPPORTS(cpu_)
            , std_tag const&
            , T const& a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    std::trunc(a0)
  )

  //================================================================================================
  // raw  decorator
  template<typename T>
  BOOST_FORCEINLINE
  T srtrunc_( T const& a0, std::true_type const &) BOOST_NOEXCEPT
  {
     return T(si_t<T>(a0));
  }

  template<typename T>
  BOOST_FORCEINLINE
  T srtrunc_( T const& a0, std::false_type const &) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T>
  BOOST_FORCEINLINE
  T trunc_(BOOST_SIMD_SUPPORTS(cpu_)
                 , raw_tag const &
                 , T const& a0) BOOST_NOEXCEPT
  {
    return srtrunc_(a0, std::is_floating_point<T>());
  }

} } }

#endif
