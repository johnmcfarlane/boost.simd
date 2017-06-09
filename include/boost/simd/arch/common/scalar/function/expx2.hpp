//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPX2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPX2_HPP_INCLUDED

#include <boost/simd/detail/constant/expx2c1.hpp>
#include <boost/simd/detail/constant/expx2c2.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/detail/constant/maxlog.hpp>
#include <boost/simd/constant/real.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/signnz.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // one parameter
  template<typename T>
  BOOST_FORCEINLINE
  T expx2_(BOOST_SIMD_SUPPORTS(cpu_)
        , T a0) BOOST_NOEXCEPT
  {
    #ifndef BOOST_SIMD_NO_INFINITIES
    if (is_inf(a0)) return Inf<T>();
#endif
    T x =  bs::abs(a0);
    /* Represent x as an exact multiple of 1/32 plus a residual.  */
    T m = Expx2c1<T>() * bs::floor(fma(Expx2c2<T>(), x, Half<T>()));
    x -= m;
    /* x**2 = m**2 + 2mf + f**2 */
    T u = sqr(m);
    T u1 = fma(Two<T>() * m, x, sqr(x));
    if ((u+u1) > bs::Maxlog<T>()) return Inf<T>();
    /* u is exact, u1 is small.  */
    return exp(u)*exp(u1);
  }

  //================================================================================================
  // two parameter
  template<typename T>
  BOOST_FORCEINLINE
  T expx2_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , T s  ) BOOST_NOEXCEPT
  {
    T sgn =  signnz(s);
    T x =  a0*sgn;
#ifndef BOOST_SIMD_NO_INFINITIES
    if (bs::is_inf(a0)) return bs::Inf<T>();
#endif
    // Represent x as an exact multiple of 1/32 plus a residual.
    T m = Expx2c1<T>()*floor(fma(Expx2c2<T>(), x, Half<T>()));
    T f =  x-m;
    // x**2 = m**2 + 2mf + f**2
    T u = sgn*sqr(m);
    T u1 = sgn*fma(m+m,f,sqr(f));
    // u is exact, u1 is small.
    if (u+u1 > Maxlog<T>()) return bs::Inf<T>();
    return exp(u)*exp(u1);
  }

} } }


#endif
