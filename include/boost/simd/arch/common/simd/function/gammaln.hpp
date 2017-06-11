//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GAMMALN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GAMMALN_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/arch/common/detail/generic/gammaln_kernel.hpp>

#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/invpi.hpp>
#include <boost/simd/constant/logpi.hpp>
#include <boost/simd/constant/logsqrt2pi.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/zero.hpp>


#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/two.hpp>

#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <boost/simd/function/if_minus.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/if_plus.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_lez.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/function/sinpi.hpp>
#include <boost/simd/function/sqr.hpp>


#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  // pack double
  template<std::size_t N, typename X >
  pack<double,N,X> large_negative(const pack<double,N,X>& q) BOOST_NOEXCEPT
  {
    using p_t =  pack<double,N,X>;
    p_t w = gammaln(q);
    p_t p = bs::floor(q);
    p_t z = q - p;
    auto test2 = is_less(z, bs::Half<p_t>() );
    z = bs::if_dec(test2, z);
    z = q*bs::sinpi(z);
    z =  bs::abs(z);
    return Logpi<p_t>()-log(z)-w;
  }

  template<std::size_t N, typename X >
  pack<double,N,X> other(const pack<double,N,X>& xx) BOOST_NOEXCEPT
  {
    using p_t =  pack<double,N,X>;
    p_t x =  xx;
    auto test = is_less(x, p_t(13.0) );
    size_t nb = nbtrue(test);
    p_t r1 = Zero<p_t>();
    if (nb > 0)
    {
      p_t z = One<p_t>();
      p_t p = Zero<p_t>();
      p_t u = if_else_zero(test, x);
      auto test1 = is_greater_equal(u,Three<p_t>());
      while(bs::any(test1))
      {
        p = if_dec(test1, p);
        u = if_else(test1, x+p, u);
        z = if_else(test1, z*u, z);
        test1 = is_greater_equal(u,Three<p_t>());
      }
      //all u are less than 3
      auto test2 = is_less(u,Two<p_t>());

      while(bs::any(test2))
      {
        z = if_else(test2, z/u, z);
        p = if_inc(test2, p);
        u = if_else(test2, x+p, u);
        test2 = is_less(u,Two<p_t>());
      }
      z = bs::abs(z);
      x +=  p-Two<p_t>();
      r1 = x * detail::gammaln_kernel<p_t>::gammaln1(x)+bs::log(z);
      if (nb >= p_t::static_size) return r1;
    }
    p_t r2 = fma(xx-Half<p_t>(),bs::log(xx), Logsqrt2pi<p_t>()-xx);
    p_t p = rec(sqr(xx));
    r2 += detail::gammaln_kernel<p_t>::gammalnA(p)/xx;
    return if_else(test, r1, r2);
  }


  template<std::size_t N, typename X >
  pack<double,N,X> gammaln_(BOOST_SIMD_SUPPORTS(simd_)
                        , pack<double,N,X> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<double,N,X>;
    auto inf_result = logical_and(is_lez(a0), is_flint(a0));
    p_t x = if_nan_else(inf_result, a0);
    p_t q = bs::abs(x);
#ifndef BOOST_SIMD_NO_INFINITES
    inf_result = is_equal(q, Inf<p_t>());
#endif
    auto test = is_less(a0, p_t(-34.0));
    size_t nb = bs::nbtrue(test);
    p_t r =  Nan<p_t>();
    if(nb > 0)
    {
      //treat negative large with reflection
      r = large_negative(q);
      if (nb >= p_t::static_size)
        return bs::if_else(inf_result, Nan<p_t>(), r);
    }
    p_t r1 = other(a0);
    p_t r2 = if_else(test, r, r1);
    return bs::if_else(is_equal(a0, Minf<p_t>()),
                       Nan<p_t>(),
                       bs::if_else(inf_result, Inf<p_t>(), r2)
                      );
  }

  // pack float
  template<std::size_t N, typename X >
  pack<float,N,X>
  negative(const pack<float,N,X>& q,  const pack<float,N,X>& w) BOOST_NOEXCEPT
  {
    using p_t = pack<float,N,X>;
    p_t p = bs::floor(q);
    p_t z = q - p;
    auto test2 = is_less(z, bs::Half<p_t>() );
    z = bs::if_dec(test2, z);
    z = q*bs::sinpi(z);
    z =  bs::abs(z);
    return -log(Invpi<p_t>()*bs::abs(z))-w;
  }

  template<std::size_t N, typename X >
  BOOST_FORCEINLINE
  pack<float,N,X>
  other(const  pack<float,N,X> & x)
  {
    using p_t = pack<float,N,X>;
    auto xlt650 = is_less(x,p_t(6.50) );
    size_t nb = nbtrue(xlt650);
    p_t r0x = x;
    p_t r0z = x;
    p_t r0s = One<p_t>();
    p_t r1 = Zero<p_t>();
    p_t p =  Nan<p_t>();
    if (nb > 0)
    {
      auto kernelC = False<p_t>();
      p_t z = One<p_t>();
      p_t tx = if_else_zero(xlt650, x);
      p_t nx = Zero<p_t>();

      const p_t _075 = p_t(0.75);
      const p_t _150 = p_t(1.50);
      const p_t _125 = p_t(1.25);
      const p_t _250 = p_t(2.50);
      auto xge150 = is_greater_equal(x, _150);
      auto txgt250= is_greater(tx,_250);

      // x >= 1.5
      while (bs::any(logical_and(xge150, txgt250)))
      {
        nx = if_dec(txgt250, nx);
        tx = if_else(txgt250, x + nx, tx);
        z = if_else(txgt250, z*tx, z);
        txgt250= is_greater(tx,_250);
      }
      r0x = if_plus(xge150, x, nx - Two<p_t>());
      r0z = if_else(xge150, z, r0z);
      r0s = if_else(xge150,One<p_t>(), r0s);

      // x >= 1.25 && x < 1.5
      auto xge125 = is_greater_equal(x, _125);
      auto xge125t = logical_andnot(xge125, xge150);
      if (bs::any(xge125))
      {
        r0x =  if_else(xge125t, dec(x)    , r0x);
        r0z =  if_else(xge125t, z*x       , r0z);
        r0s =  if_else(xge125t, Mone<p_t>(), r0s);
      }
      // x >= 0.75&& x < 1.5
      auto xge075  = is_greater_equal(x, _075);
      auto xge075t = logical_andnot(xge075, xge125);
      if (bs::any(xge075t))
      {
        kernelC =  xge075t;
        r0x =  if_else(xge075t, dec(x)    , r0x);
        r0z =  if_else(xge075t, One<p_t>() , r0z);
        r0s =  if_else(xge075t, Mone<p_t>(), r0s);
        p = detail::gammaln_kernel<p_t>::gammalnC(r0x);
      }
      // tx < 1.5 && x < 0.75
      auto txlt150 = logical_andnot(is_less(tx,_150), xge075);
      if (bs::any(txlt150))
      {
        auto orig = txlt150;
        while( bs::any(txlt150) )
        {
          z  = if_else(txlt150, z*tx, z);
          nx = if_inc(txlt150, nx);
          tx = if_else(txlt150, x + nx, tx);
          txlt150= logical_andnot(is_less(tx,_150), xge075);
        }
        r0x =  if_plus(orig, r0x, nx - Two<p_t>());
        r0z =  if_else(orig,z         , r0z);
        r0s =  if_else(orig,Mone<p_t>(), r0s);
      }
      p =  if_else(kernelC, p, detail::gammaln_kernel<p_t>::gammalnB(r0x));
      if (nb >= p_t::static_size)
        return fma(r0x, p, r0s*bs::log(bs::abs(r0z)));
    }
    r0z = if_else(xlt650, bs::abs(r0z), x);
    p_t m = bs::log(r0z);
    r1 = fma(r0x, p, r0s*m);
    p_t r2 = fma(x-Half<p_t>(),m,Logsqrt2pi<p_t>()-x);
    r2 += detail::gammaln_kernel<p_t>::gammaln2(rec(sqr(x)))/x;
    return if_else(xlt650, r1, r2);
  }


  template<std::size_t N, typename X>
  pack<float,N,X> gammaln_(BOOST_SIMD_SUPPORTS(simd_)
                         , pack<float,N,X> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<float,N,X>;
    auto inf_result = logical_and(is_lez(a0), is_flint(a0));
    p_t x = if_nan_else(inf_result, a0);
    p_t q = bs::abs(x);
#ifndef BOOST_SIMD_NO_INFINITES
    inf_result = logical_or(is_equal(x, Inf<p_t>()), inf_result);
#endif
    auto ltza0 = is_ltz(a0);
    size_t nb = bs::nbtrue(ltza0);
    p_t r;
    p_t r1 =  other(q);
    if(nb > 0)
    {
      //treat negative
      r = bs::if_else(inf_result, Inf<p_t>(), negative(q, r1));
      if (nb >= p_t::static_size) return r;
    }
    p_t r2 = if_else(ltza0, r, r1);
    return bs::if_else(is_equal(a0, Minf<p_t>()),
                       Nan<p_t>(),
                       bs::if_else(inf_result, Inf<p_t>(), r2)
                      );
  }

  // Emulated implementation
  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N,simd_emulation_> gammaln_ ( BOOST_SIMD_SUPPORTS(simd_)
                                         , pack<double,N,simd_emulation_> const& a
                                         ) BOOST_NOEXCEPT
  {
    return map_to(simd::gammaln, a);
  }

  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N,simd_emulation_> gammaln_ ( BOOST_SIMD_SUPPORTS(simd_)
                                        , pack<float,N,simd_emulation_> const& a
                                        ) BOOST_NOEXCEPT
  {
    return map_to(simd::gammaln, a);
  }

  // std decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> gammaln_ ( BOOST_SIMD_SUPPORTS(simd_)
                    , std_tag const &
                    , pack<T,N> const& a
                    ) BOOST_NOEXCEPT
  {
    return map_to(std_(gammaln), a);
  }

} } }


#endif
