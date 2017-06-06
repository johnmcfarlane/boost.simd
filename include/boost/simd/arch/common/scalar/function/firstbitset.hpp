//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FIRSTBITSET_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FIRSTBITSET_HPP_INCLUDED

#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T >
  BOOST_FORCEINLINE
  ui_t<T> sfirstbitset_( T a0
           , std::false_type) BOOST_NOEXCEPT
  {
    using result_t = ui_t<T>;
    return a0 & (~a0+One<result_t>());
  }

  template<typename T>
  BOOST_FORCEINLINE
  ui_t<T> sfirstbitset_( T a0
           , std::true_type const &) BOOST_NOEXCEPT
  {
    using result_t = ui_t<T>;
    return sfirstbitset_(bitwise_cast<result_t>(a0) , std::false_type());
  }

  template<typename T>
  BOOST_FORCEINLINE
  ui_t<T> firstbitset_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a) BOOST_NOEXCEPT
  {
    return sfirstbitset_(a, std::is_floating_point<T>());
  }

} } }


#endif
