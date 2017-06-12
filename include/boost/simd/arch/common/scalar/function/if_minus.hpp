//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_MINUS_HPP_INCLUDED

#include <boost/simd/function/is_nez.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename U, typename V,
           typename = typename std::enable_if<std::is_fundamental<T>::value&&
                                              std::is_fundamental<U>::value&&
                                              std::is_fundamental<V>::value>::type
  >
  BOOST_FORCEINLINE U if_minus_(BOOST_SIMD_SUPPORTS(cpu_)
                             , T  a0
                             , U  a1
                             , V  a2) BOOST_NOEXCEPT
  {
    return is_nez(a0) ? (a1-U(a2)) : a1;
  }

  template<typename T, typename U, typename V,
           typename = typename std::enable_if<std::is_fundamental<T>::value&&
                                              std::is_fundamental<U>::value&&
                                              std::is_fundamental<V>::value>::type
  >
  BOOST_FORCEINLINE U if_minus_(BOOST_SIMD_SUPPORTS(cpu_)
                             , logical<T> const& a0
                             , U  a1
                             , V  a2) BOOST_NOEXCEPT
  {
    return  a0 ? (a1-U(a2)) : a1;
  }

} } }


#endif
