//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_PREV_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_PREV_HPP_INCLUDED

#include <boost/simd/constant/minf.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/predecessor.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T s_prev_( T a
           , std::true_type const &) BOOST_NOEXCEPT
  {
    return (a == Minf<T>()) ? a : predecessor(a);
  }

  template<typename T >
  BOOST_FORCEINLINE
  T s_prev_( T a
           , std::false_type) BOOST_NOEXCEPT
  {
    return dec(a);
  }

  template<typename T>
  BOOST_FORCEINLINE
  T prev_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a) BOOST_NOEXCEPT
  {
    return s_prev_(a, std::is_floating_point<T>());
  }

} } }


#endif
