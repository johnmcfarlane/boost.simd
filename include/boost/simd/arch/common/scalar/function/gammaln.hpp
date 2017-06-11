//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_GAMMALN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_GAMMALN_HPP_INCLUDED

#include <boost/simd/function/std.hpp>
#include <boost/simd/arch/common/detail/generic/gammaln_kernel.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/invpi.hpp>
#include <boost/simd/constant/logpi.hpp>
#include <boost/simd/constant/logsqrt2pi.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sinpi.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  //double
  double gammaln_pos(double x) BOOST_NOEXCEPT
  {
    if( x < 13.0 )
    {
      double z = One<double>();
      double p = Zero<double>();
      double u = x;
      while( u >= 3.0 )
      {
        p -= 1.0;
        u = x + p;
        z *= u;
      }
      while( u < 2.0 )
      {
        if( u == 0.0 )  return Inf<double>();
        z /= u;
        p += 1.0;
        u = x + p;
      }
      z = bs::abs(z);
      if( u == 2.0 ) return( bs::log(z) );
      p -= 2.0;
      x = x + p;
      p = x * detail::gammaln_kernel<double>::gammaln1(x);
      return bs::log(z) + p ;
    }
    double q = fma(( x - 0.5 ), bs::log(x), Logsqrt2pi<double>()-x);
    if( x > 1.0e8 ) return q;

    double p = rec(sqr(x));
    q += detail::gammaln_kernel<double>::gammalnA(p)/x;
    return q;
  }

  double gammaln_(BOOST_SIMD_SUPPORTS(cpu_)
                 , double  a0) BOOST_NOEXCEPT
  {
    double Maxgammaln = Constant<double, 0x7f574c5dd06d2516ULL>();
    if ((a0 == bs::Inf<double>()) || bs::is_eqz(a0) ) return bs::Inf<double>(); //2.556348e305
    double x = a0;
    double q = bs::abs(x);
    if(x > Maxgammaln) return Inf<double>();
    if( x < -34.0 )
    {
      if(q > Maxgammaln) return Nan<double>();
      double w = gammaln_pos(q);
      double p =  bs::floor(q);
      if (p == q) return bs::Inf<double>();
      double z = q - p;
      if( z > bs::Half<double>() )
      {
        p += bs::One<double>();
        z = p-q;
      }
      z = q*bs::sinpi(z);
      if( bs::is_eqz(z) ) return bs::Inf<double>();
      return Logpi<double>()-bs::log(z)-w;
    }
    else
    {
      return gammaln_pos(x);
    }
  }

  // float
  float gammaln_pos(float x) BOOST_NOEXCEPT
  {
    if( x < 6.5f )
    {
      float z = One<float>();
      float tx = x;
      float nx = Zero<float>();
      if( x >= 1.5f )
      {
        while( tx > 2.5f )
        {
          nx = dec(nx);
          tx = x + nx;
          z *=tx;
        }
        x += nx - Two<float>();
        float p = x * detail::gammaln_kernel<float>::gammalnB(x);
        return p+bs::log(z);

      }
      if( x >= 1.25f )
      {
        z *= x;
        x =  dec(x);
        float p = x *  detail::gammaln_kernel<float>::gammalnB(x);
        return p-bs::log(z);
      }
      if( x >= 0.75f )
      {
        x = dec(x); //-= 1.0f;
        return x * detail::gammaln_kernel<float>::gammalnC(x);
      }
      while( tx < 1.5f )
      {
        if(is_eqz(tx) ) return Inf<float>();
        z *=tx;
        nx = inc(nx);
        tx = x + nx;
      }
      x += nx - Two<float>();
      float p = x *  detail::gammaln_kernel<float>::gammalnB(x);
      return p-log(z);
    }
    float q = fma(( x - 0.5f ), bs::log(x), Logsqrt2pi<float>() - x);
    if( x <= 1.0e4f )
    {
      float z = rec(x);
      float p = sqr(z);
      q = fma(z, detail::gammaln_kernel<float>::gammaln2(p), q);
    }
    return q;
  }

  float gammaln_(BOOST_SIMD_SUPPORTS(cpu_)
                , float  a0) BOOST_NOEXCEPT
  {
    float Maxgammaln = Constant<float, 0x7bc3f8eaUL>(); //2.035093e36f
    if ((a0 > Maxgammaln) || bs::is_eqz(a0) ) return bs::Inf<float>();
    float x = a0;
    float q = bs::abs(x);
    if( x < 0.0f )
    {
      if(q > Maxgammaln) return Nan<float>();
      float w = gammaln_pos(q);
      float p =  bs::floor(q);
      if (p == q) return bs::Inf<float>();
      float z = q - p;
      if( z > bs::Half<float>() )
      {
        p += bs::One<float>();
        z = p-q;
      }
      z = q*bs::sinpi(z);
      if( bs::is_eqz(z) ) return bs::Inf<float>();
      return -bs::log(Invpi<float>()*bs::abs(z))-w;
    }
    else
    {
      return gammaln_pos(x);
    }
  }

  // std decorator
  template < typename T>
  BOOST_FORCEINLINE
  T gammaln_(BOOST_SIMD_SUPPORTS(cpu_)
             ,std_tag const &
             , T a) BOOST_NOEXCEPT
  {
    return std::lgamma(a);
  }

} } }


#endif
