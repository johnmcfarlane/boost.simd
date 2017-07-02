//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LO_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LO_HPP_INCLUDED

#include <boost/simd/function/bitwise_and.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE as_ui_t<T> lo_( BOOST_SIMD_SUPPORTS(cpu_)
                               , T const& a) BOOST_NOEXCEPT
  {
    using r_t = as_ui_t<T>;
    r_t pattern((r_t(1) << sizeof(r_t)*(CHAR_BIT/2)) - 1);
    return bitwise_and(pattern, a);
  }

} } }


#endif
