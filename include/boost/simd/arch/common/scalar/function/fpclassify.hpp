//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FPCLASSIFY_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FPCLASSIFY_HPP_INCLUDED

#include <boost/simd/function/std.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/config.hpp>
#include <type_traits>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  template<typename T
           , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE si_t<T>
  fpclassify_( BOOST_SIMD_SUPPORTS(cpu_)
             , T a
             ) BOOST_NOEXCEPT
   {
     return std::fpclassify(a);
   }

  template<typename T
           , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE si_t<T>
  fpclassify_( BOOST_SIMD_SUPPORTS(cpu_)
               std_tag const &
             , T a
             ) BOOST_NOEXCEPT
  {
    return std::fpclassify(a);
  }

} } }


#endif
