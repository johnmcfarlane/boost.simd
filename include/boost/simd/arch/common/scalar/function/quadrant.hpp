//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_QUADRANT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_QUADRANT_HPP_INCLUDED

#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

  template<typename T>
  BOOST_FORCEINLINE
  T squadrant_( T a0
              , std::true_type const &) BOOST_NOEXCEPT
  {
    return quadrant(si_t<T>(a0));
  }

  template<typename T>
  BOOST_FORCEINLINE
  T squadrant_( T a0
              , std::false_type const &) BOOST_NOEXCEPT
  {
    return a0&T(3);
  }

  template<typename T>
  BOOST_FORCEINLINE
  T quadrant_( BOOST_SIMD_SUPPORTS(cpu_)
             , T a0) BOOST_NOEXCEPT
  {
    return squadrant_(a0, std::is_floating_point<T>());
  }

} } }
#endif

