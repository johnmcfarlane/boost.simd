//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FNMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FNMA_HPP_INCLUDED

#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //==========================================================================
  //regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE T
  fnma_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , T a1
          , T a2 ) BOOST_NOEXCEPT
  {
    return -a0*a1-a2;
  }

  //==========================================================================
  //pedantic decorator
  template<typename T>
  BOOST_FORCEINLINE T
  fnma_(BOOST_SIMD_SUPPORTS(cpu_)
      , pedantic_tag const&
          , T a0
          , T a1
          , T a2 ) BOOST_NOEXCEPT
  {
    return -pedantic_(fma)(a0, a1, a2);
  }

} } }


#endif
