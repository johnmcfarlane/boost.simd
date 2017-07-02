//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_HMSB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_HMSB_HPP_INCLUDED

#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/bitset.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE simd::bitset<1> hmsb_(BOOST_SIMD_SUPPORTS(cpu_)
                                         , T const& a0) BOOST_NOEXCEPT
  {
    return {bitwise_and(Signmask<as_i_t<T>>(), a0) != 0};
  }

} } }

#endif
