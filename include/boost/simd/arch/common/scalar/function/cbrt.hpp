//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CBRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CBRT_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/inf.hpp>
#endif
#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/twotomnmbo_3.hpp>
#include <boost/simd/constant/twotonmb.hpp>
#endif
#include <boost/simd/function/horn.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/third.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/negate.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <tuple>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  BOOST_FORCEINLINE
  double cbrt_(BOOST_SIMD_SUPPORTS(cpu_)
               , double a0) BOOST_NOEXCEPT
  {
    double z =  bs::abs(a0);
#ifndef BOOST_SIMD_NO_INFINITIES
    if (z == bs::Inf<double>() || (z == 0)) return a0;
#else
    if (z == 0) return a0;
#endif
#ifndef BOOST_SIMD_NO_DENORMALS
    double f = One<double>();
    if (z < Smallestposval<double>())
    {
      z *= Twotonmb<double>();
      f  = Twotomnmbo_3<double>();
    }
#endif
    const double CBRT2  = Constant< double, 0x3ff428a2f98d728bll> ();
    const double CBRT4  = Constant< double, 0x3ff965fea53d6e3dll> ();
    const double CBRT2I = Constant< double, 0x3fe965fea53d6e3dll> ();
    const double CBRT4I = Constant< double, 0x3fe428a2f98d728bll> ();
    using i_t = bd::as_integer_t<double, signed>;
    i_t e;
    double x;
    std::tie(x, e) = ifrexp(z);
    x = horn<double,
      0x3fd9c0c12122a4fell,
      0x3ff23d6ee505873all,
      0xbfee8a4ca3ba37b8ll,
      0x3fe17e1fc7e59d58ll,
      0xbfc13c93386fdff6ll
      > (x);
    const auto flag = is_gez(e);
    i_t e1 =  bs::abs(e);
    i_t rem = e1;
    e1 /= Three<i_t>();
    rem -= e1*Three<i_t>();
    e =  negate(e1, e);
    const double cbrt2 = flag ? CBRT2 : CBRT2I;
    const double cbrt4 = flag ? CBRT4 : CBRT4I;
    double fact = (rem == One<i_t>()) ? cbrt2: One<double>();
    fact = (rem == Two<i_t>() ? cbrt4 : fact);
    x = ldexp(x*fact, e);
    x -= (x-z/sqr(x))*Third<double>();
    x -= (x-z/sqr(x))*Third<double>(); //two newton passes
#ifndef BOOST_SIMD_NO_DENORMALS
    return bitwise_or(x, bitofsign(a0))*f;
#else
    return bitwise_or(x, bitofsign(a0));
#endif
  }

  BOOST_FORCEINLINE
  float cbrt_(BOOST_SIMD_SUPPORTS(cpu_)
             , float a0) BOOST_NOEXCEPT
  {
      float z =  bs::abs(a0);
    #ifndef BOOST_SIMD_NO_INFINITIES
      if (z == bs::Inf<float>() || (z == 0)) return a0;
    #else
      if  (z == 0) return a0;
    #endif
    #ifndef BOOST_SIMD_NO_DENORMALS
      float f = One<float>();
      if (z < Smallestposval<float>())
      {
        z *= Twotonmb<float>();
        f = Twotomnmbo_3<float>();
      }
    #endif
      const float CBRT2  = Constant< float, 0x3fa14518> ();
      const float CBRT4  = Constant< float, 0x3fcb2ff5> ();
      const float CBRT2I = Constant< float, 0x3f4b2ff5> ();
      const float CBRT4I = Constant< float, 0x3f214518> ();
      using i_t = bd::as_integer_t<float, signed>;
      i_t e;
      float x;
      std::tie(x, e)= ifrexp(z);
      x = horn<float,
               0x3ece0609,
               0x3f91eb77,
               0xbf745265,
               0x3f0bf0fe,
               0xbe09e49a
               > (x);
      const auto flag = is_gez(e);
      i_t e1 =  bs::abs(e);
      i_t rem = e1;
      e1 /= Three<i_t>();
      rem -= e1*Three<i_t>();
      e =  negate(e1, e);

      const float cbrt2 = flag ? CBRT2 : CBRT2I;
      const float cbrt4 = flag ? CBRT4 : CBRT4I;
      float fact = (rem ==  One<i_t>()) ? cbrt2 : One<float>();
      fact = (rem == Two<i_t>()) ? cbrt4 : fact;
      x = ldexp(x*fact, e);
      x -= (x-z/sqr(x))*Third<float>();
    #ifndef BOOST_SIMD_NO_DENORMALS
      return bitwise_or(x, bitofsign(a0))*f;
    #else
      return bitwise_or(x, bitofsign(a0));
    #endif
    }

  //================================================================================================
  // std_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T cbrt_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const&
         , T const& a) BOOST_NOEXCEPT
  {
    return std::cbrt(a);
  }

} } }

#endif
