//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SHR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SHR_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE T shr_( BOOST_SIMD_SUPPORTS(boost::dispatch::cpu_)
                          , T v, int s
                          ) BOOST_NOEXCEPT
  {
    using type = typename std::make_unsigned<T>::type;
    BOOST_ASSERT_MSG(assert_good_shift<T>(s), "shr : shift is out of range");
    return type(v) >> s;
  }

  BOOST_FORCEINLINE double shr_ ( BOOST_SIMD_SUPPORTS(boost::dispatch::cpu_)
                                , double v, int s
                                ) BOOST_NOEXCEPT
  {
    return bitwise_cast<double>(shr( bitwise_cast<std::uint64_t>(v),s));
  }

  BOOST_FORCEINLINE float  shr_ ( BOOST_SIMD_SUPPORTS(boost::dispatch::cpu_)
                                , float v, int s
                                ) BOOST_NOEXCEPT
  {
    return bitwise_cast<float>(shr( bitwise_cast<std::uint32_t>(v),s));
  }
} } }

#endif
