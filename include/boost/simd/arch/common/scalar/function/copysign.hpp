//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COPYSIGN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COPYSIGN_HPP_INCLUDED

#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitwise_notand.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/signnz.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE T
  scopysign_( T a0
            , T a1, std::true_type const &) BOOST_NOEXCEPT
  {
    return bitwise_or(bitofsign(a1), bitwise_notand(Signmask(as(a0)), a0));
  }

  template<typename T>
  BOOST_FORCEINLINE T
  scopysign_( T a0
            , T a1, std::false_type const &) BOOST_NOEXCEPT
  {
    return saturated_(abs)(a0)*signnz(a1);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  copysign_(BOOST_SIMD_SUPPORTS(cpu_)
           , T a0
           , T a1) BOOST_NOEXCEPT
  {
    return scopysign_(a0, a1, std::is_floating_point<T>());
  }

  template<typename T>
  BOOST_FORCEINLINE T
  copysign_(BOOST_SIMD_SUPPORTS(cpu_)
           ,  std_tag const &
           , T a0
           , T a1) BOOST_NOEXCEPT
  {
    return std::copysign(a0, a1);
  }

} } }


#endif
