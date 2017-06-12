//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_DEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_DEC_HPP_INCLUDED

#include <boost/simd/function/dec.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename U>
  BOOST_FORCEINLINE U if_dec_(BOOST_SIMD_SUPPORTS(cpu_)
                                      , T const& a0
                                      , U const& a1) BOOST_NOEXCEPT
  {
    return  is_nez(a0) ? dec(a1) : a1;
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE U if_dec_(BOOST_SIMD_SUPPORTS(cpu_)
                                      , logical<T> const& a0
                                      , U const& a1) BOOST_NOEXCEPT
  {
    return  a0 ? dec(a1) : a1;
  }

} } }


#endif
