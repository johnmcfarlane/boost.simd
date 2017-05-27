//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ASINH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ASINH_HPP_INCLUDED

#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/oneosqrteps.hpp>
#include <boost/simd/constant/sqrteps.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/hypot.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/log1p.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  BOOST_FORCEINLINE
  double asinh_(BOOST_SIMD_SUPPORTS(cpu_)
              , double a) BOOST_NOEXCEPT
  {
    double x = bs::abs(a);
    if  (BOOST_UNLIKELY(x < bs::Sqrteps<double>() ))
    {
      return a;
    }
    else
    {
      double z;
      if (x < 0.5)
      {
        double invx = bs::rec(x);
        z = bs::log1p(x + x/(invx + bs::sqrt(fma(invx, invx, bs::One<double>()))));
      }
      else if (BOOST_UNLIKELY(x > Oneosqrteps<double>()))
      {
        z = log(x)+Log_2<double>();
      }
      else
      {
        z =  log(x+hypot(One<double>(), x));
      }
      return bitwise_xor(z, bitofsign(a));
    }
  }

  BOOST_FORCEINLINE
  float asinh_(BOOST_SIMD_SUPPORTS(cpu_)
             , float a) BOOST_NOEXCEPT
  {
    // Exhaustive test for: boost::dispatch::functor<bs::tag::asinh_, boost::simd::tag::sse4_2_>
    //              versus:  float(boost::math::asinh(double)
    //              With T: float
    //            in range: [-3.40282e+38, 3.40282e+38]
    // 4278190078 values computed.
    // 3628470338 values (84.81%)  within 0.0 ULPs
    //  649693884 values (15.19%)  within 0.5 ULPs
    //      25856 values ( 0.00%)  within 1.0 ULPs
    float x = bs::abs(a);
    float x2 = bs::sqr(x);
    float z = Zero<float>();

    if( x < 0.5f)
    {
      z = horn<float
        , 0x3f800000
        , 0xbe2aa9ad
        , 0x3d9949b1
        , 0xbd2ee581
        , 0x3ca4d6e6
        > (x2)*x;
    }
    else if (BOOST_UNLIKELY(x > Oneosqrteps<float>()))
    {
      z = log(x)+Log_2<float>();
    }
    else
    {
      z =  log(x+hypot(One<float>(), x));
    }
    return bitwise_xor(z, bitofsign(a));
  }

  //================================================================================================
  // std_ decorator
  template < typename T>
  BOOST_FORCEINLINE
  T asinh_(BOOST_SIMD_SUPPORTS(cpu_)
          , std_tag const &
          , T const& a) BOOST_NOEXCEPT
  {
    return std::asinh(a);
  }

} } }


#endif
