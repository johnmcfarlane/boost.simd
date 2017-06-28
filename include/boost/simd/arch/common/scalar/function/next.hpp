//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXT_HPP_INCLUDED

#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/successor.hpp>
#include <boost/config.hpp>


namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T s_next_( T a
           , std::true_type const &) BOOST_NOEXCEPT
  {
    return (a == Inf<T>()) ? a : successor(a);
  }

  template<typename T >
  BOOST_FORCEINLINE
  T s_next_( T a
           , std::false_type) BOOST_NOEXCEPT
  {
    return inc(a);
  }

  template<typename T>
  BOOST_FORCEINLINE
  T next_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a) BOOST_NOEXCEPT
  {
    return s_next_(a, std::is_floating_point<T>());
  }

} } }


#endif
