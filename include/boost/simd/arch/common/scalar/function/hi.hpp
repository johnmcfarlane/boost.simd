//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_HI_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_HI_HPP_INCLUDED

#include <boost/simd/function/lo.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE as_ui_t<T> hi_( BOOST_SIMD_SUPPORTS(cpu_)
                               , T const& a) BOOST_NOEXCEPT
  {
    return lo( shr(a, sizeof( as_ui_t<T>)*(CHAR_BIT/2)));
  }

} } }


#endif
