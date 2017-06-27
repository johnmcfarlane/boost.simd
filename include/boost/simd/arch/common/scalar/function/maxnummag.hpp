//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MAXNUMMAG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MAXNUMMAG_HPP_INCLUDED

#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/maxmag.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  ///////////////////////////////////////////////////////////////////////
  // regular
  template<typename T>
  BOOST_FORCEINLINE T
  s_maxnummag_( T a0
              , T a1
              , std::true_type const &
              ) BOOST_NOEXCEPT
  {
    return (is_nan(a0)) ? a1 : maxmag(a0, a1);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  s_maxnummag_( T a0
              , T a1
              , std::false_type const &
              ) BOOST_NOEXCEPT
  {
    return maxmag(a0, a1);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  maxnummag_(BOOST_SIMD_SUPPORTS(cpu_)
            , T a0
            , T a1) BOOST_NOEXCEPT
  {
    return s_maxnummag_(a0, a1, std::is_floating_point<T>());
  }

} } }

#endif
