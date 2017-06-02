//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COTH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COTH_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/arch/common/detail/generic/tanh_kernel.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/coth.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> coth_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    //////////////////////////////////////////////////////////////////////////////
    // if x = abs(a0) is less than 5/8 sinh is computed using a polynomial(float)
    // (respectively rational(double)) approx inspirated from cephes.
    // else
    // coth(a0) is  sign(a0)*(1 + 2/(exp(2*x)-1))
    //////////////////////////////////////////////////////////////////////////////
    using p_t = pack<T,N>;
    p_t x = bs::abs(a0);
    auto test0= is_less(x, Ratio<p_t, 5, 8>());
    p_t bts = bitofsign(a0);
    std::size_t nb = nbtrue(test0);
    p_t z = One<p_t>();
    if(nb> 0)
    {
      z = detail::tanh_kernel<p_t>::coth(x, sqr(x));
      if(nb >= p_t::static_size) return  bitwise_xor(z, bts);
    }
    p_t r = fma(Two<p_t>(), rec(dec(exp(x+x))), One<p_t>());
    return bitwise_xor(if_else(test0, z, r), bts);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> coth_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pack<T,N,simd_emulation_> const& a
                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::coth, a);
  }

} } }

#endif
