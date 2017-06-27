//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NBTRUE_HPP_INCLUDED

#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/config.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace boost { namespace simd { namespace detail
{

  template<typename T>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_arithmetic<T>::value, std::size_t>::type
  nbtrue_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a0) BOOST_NOEXCEPT
  {
    return is_nez(a0) ? One<std::size_t>() : Zero< std::size_t>();
  }

  BOOST_FORCEINLINE
  typename  std::size_t
  nbtrue_(BOOST_SIMD_SUPPORTS(cpu_)
         , bool a0) BOOST_NOEXCEPT
  {
    return std::size_t(a0);
  }

} } }


#endif
