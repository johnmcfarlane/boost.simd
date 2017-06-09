//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FMS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FMS_HPP_INCLUDED

#include <boost/simd/function/fma.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //==========================================================================
  //regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE T
  fms_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , T a1
          , T a2 ) BOOST_NOEXCEPT
  {
    return a0*a1-a2;
  }

   //==========================================================================
  //std decorator
  template<typename T
           , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE T
  fms_(BOOST_SIMD_SUPPORTS(cpu_)
      , std_tag const&
      , T a0
      , T a1
      , T a2 ) BOOST_NOEXCEPT
  {
    return std::fma(a0, a1, -a2);
  }

  //==========================================================================
  //pedantic decorator
  template<typename T>
  BOOST_FORCEINLINE T
  fms_(BOOST_SIMD_SUPPORTS(cpu_)
      , pedantic_tag const&
          , T a0
          , T a1
          , T a2 ) BOOST_NOEXCEPT
  {
    return pedantic_(fma)(a0, a1, T(-a2));
  }


} } }


#endif
