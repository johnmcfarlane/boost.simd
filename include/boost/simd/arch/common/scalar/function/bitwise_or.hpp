//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_OR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_OR_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace detail
{
  namespace bd = boost::dispatch;

  template<typename T>
  BOOST_FORCEINLINE T bor_(T a, T b, tt_::false_type ) BOOST_NOEXCEPT
  {
    // same type, T is not IEEE
    return a | b;
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T bor_(T a, U b, tt_::false_type ) BOOST_NOEXCEPT
  {
    // different type, T is not IEEE
    return a | bitwise_cast<T>(b);
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T bor_(T a, U b, tt_::true_type ) BOOST_NOEXCEPT
  {
    // different type, T is IEEE
    using b_t = bd::as_integer_t<T, unsigned>;
    return bitwise_cast<T>(b_t(bitwise_cast<b_t>(a) | bitwise_cast<b_t>(b)));
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T bitwise_or_(BOOST_SIMD_SUPPORTS(cpu_), T a, U b) BOOST_NOEXCEPT
  {
    static_assert ( sizeof(T) == sizeof(U)
                  , "simd::bitwise_or - Arguments have incompatible size"
                  );

    return bor_(a ,b, tt_::is_floating_point<T>{});
  }
} } }

#endif
