//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_INEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_INEARBYINT_HPP_INCLUDED
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE auto
  s_inearbyint_( T a0
          , std::true_type const &) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    toint(nearbyint(a0))
  )

  template<typename T>
  BOOST_FORCEINLINE T
  s_inearbyint_( T a0
          , std::false_type const ) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T>
  BOOST_FORCEINLINE auto
  inearbyint_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    s_inearbyint_(a0, std::is_floating_point<T>())
  )

  //pedantic
  template<typename T>
  BOOST_FORCEINLINE auto
  sp_inearbyint_( T a0
                , std::true_type const &) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    saturated_(toint)(bs::nearbyint(a0))
  )

    template<typename T>
  BOOST_FORCEINLINE T
  sp_inearbyint_( T a0
                , std::false_type const ) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T>
  BOOST_FORCEINLINE auto
  inearbyint_(BOOST_SIMD_SUPPORTS(cpu_)
             , pedantic_tag const &
             , T a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    sp_inearbyint_(a0, std::is_floating_point<T>())
  )

} } }

#endif

