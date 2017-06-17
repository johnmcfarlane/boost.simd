//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SHIFT_LEFT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SHIFT_LEFT_HPP_INCLUDED

#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_integral<T>::value, T>::type
  shift_left_( BOOST_SIMD_SUPPORTS(boost::dispatch::cpu_)
                          , T v, int s
                          ) BOOST_NOEXCEPT
  {
//    BOOST_ASSERT_MSG(assert_good_shift<T>(s), "shift_left : shift is out of range");
    return v << s;
  }

  BOOST_FORCEINLINE double shift_left_ ( BOOST_SIMD_SUPPORTS(boost::dispatch::cpu_)
                                , double v, int s
                                ) BOOST_NOEXCEPT
  {
    return bitwise_cast<double>(shift_left( bitwise_cast<std::uint64_t>(v),s));
  }

  BOOST_FORCEINLINE float  shift_left_ ( BOOST_SIMD_SUPPORTS(boost::dispatch::cpu_)
                                , float v, int s
                                ) BOOST_NOEXCEPT
  {
    return bitwise_cast<float>(shift_left( bitwise_cast<std::uint32_t>(v),s));
  }

} } }

#endif
