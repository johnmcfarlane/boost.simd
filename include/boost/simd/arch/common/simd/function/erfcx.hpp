//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ERFCX_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ERFCX_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/arch/common/detail/generic/erf_kernel.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/erfc.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/sign.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template< std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<double,N,X> erfcx_(BOOST_SIMD_SUPPORTS(simd_)
                         , pack<double,N,X> const& x) BOOST_NOEXCEPT
  {
    using p_t = pack<double,N,X>;
    p_t y =  bs::abs(x);
    p_t lim1 = Ratio<p_t, 15, 32>();
    p_t lim2 = p_t(4);
    p_t res1(0), res2(0);
    auto test1 = (y <=lim1);
    std::size_t nb = bs::nbtrue(test1);
    if(nb > 0)
    {
      p_t ysq;
      p_t tmp = detail::erf_kernel1<p_t>::erf1(x, y, ysq);
      res1 = oneminus(tmp)*exp(ysq);
      if (nb >= p_t::static_size)
        return res1;
    }
    auto test2 = bs::is_less(x, lim2);
    auto test3 = bs::logical_andnot(test2, test1);
    std::size_t nb1 = bs::nbtrue(test3);
    if(nb1 > 0)
    {
      res2  = detail::erf_kernel1<p_t>::erf2(x, y);
      p_t resb = res2;
      detail::erf_kernel1<p_t>::finalize3(resb, x);
      res2 = if_else(is_ltz(x), resb, res2);
      nb += nb1;
      res2 = bs::if_else(test1, res1, res2);
      if (nb >= p_t::static_size)
        return res2;
    }
    else
    {
      res2 =  res1;
    }
    auto test4 = logical_not(logical_or(test1, test2));
    p_t res3 = detail::erf_kernel1<p_t>::erf3(x, y);
    p_t res3b = res3;
    detail::erf_kernel1<p_t>::finalize3(res3b, x);
    res3 =  if_else (is_ltz(x), res3b, res3);
    return if_nan_else(is_nan(x), if_else(test4, res3, res2));
  }

  template< std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<float,N,X> erfcx_(BOOST_SIMD_SUPPORTS(simd_)
                        , pack<float,N,X> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<float,N,X>;
    auto test1 = bs::is_less(a0,  Ratio<p_t, 2, 3>());
    std::size_t nb = bs::nbtrue(test1);
    p_t r2 = Zero<p_t>(), r1 = Zero<p_t>();
    if(nb > 0)
    {
      r1 = expx2(a0)*erfc(a0);
    }
    if(nb < p_t::static_size)
    {
      p_t z =  a0/inc(a0) - Ratio<p_t, 2, 5>();
      r2 = detail::erf_kernel<p_t>::erfc2(z);
      r2 = if_else(is_ltz(r2), bs::rsqrt(bs::Pi<p_t>())/a0, r2);
#ifndef BOOST_SIMD_NO_INFINITIES
      r2 = if_else(is_nan(a0), a0, if_zero_else(a0 == Inf<p_t>(), r2));
#endif
    }
    return if_else(test1, r1, r2);
  }

  // Emulated implementation only double/float
  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N,simd_emulation_> erfcx_ ( BOOST_SIMD_SUPPORTS(simd_)
                                        , pack<double,N,simd_emulation_> const& a
                                        ) BOOST_NOEXCEPT
  {
    return map_to(simd::erfcx, a);
  }

  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N,simd_emulation_> erfcx_ ( BOOST_SIMD_SUPPORTS(simd_)
                                       , pack<float,N,simd_emulation_> const& a
                                       ) BOOST_NOEXCEPT
  {
    return map_to(simd::erfcx, a);
  }

} } }


#endif
