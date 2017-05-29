//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ATANH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ATANH_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/log1p.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T atanh_(BOOST_SIMD_SUPPORTS(cpu_)
          , T const& a0) BOOST_NOEXCEPT
  {
    auto absa0 = bs::abs(a0);
    auto t =  absa0+absa0;
    auto z1 = oneminus(absa0);
    return bitwise_xor(bitofsign(a0),
                       Half(as(a0))*log1p((absa0 < Half(as(a0))
                                           ? fma(t, absa0/z1, t)
                                           : t/z1)
                                         )
                      );
  }

  //================================================================================================
  // raw_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T atanh_(BOOST_SIMD_SUPPORTS(cpu_)
          , raw_tag const&
          , T const& a0) BOOST_NOEXCEPT
  {
    return  Half(as(a0))*log(inc(a0)/oneminus(a0));
  }

  //================================================================================================
  // std_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T atanh_(BOOST_SIMD_SUPPORTS(cpu_)
          , std_tag const&
          , T const& a0) BOOST_NOEXCEPT
  {
    return std::atanh(a0);
  }

} } }


#endif
