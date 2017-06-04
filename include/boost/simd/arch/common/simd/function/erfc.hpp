//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ERFC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ERFC_HPP_INCLUDED

#include <boost/simd/arch/common/detail/generic/erf_kernel.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/zero.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/inf.hpp>
#endif
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template< std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<double,N,X> erfc_(BOOST_SIMD_SUPPORTS(simd_)
                        , pack<double,N,X> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<double,N,X>;
    p_t x =  bs::abs(a0);
    p_t xx =  bs::sqr(x);
    p_t lim1 = p_t(0.65);
    p_t lim2 = p_t(2.2);
    auto test0 = bs::is_ltz(a0);
    auto test1 = bs::is_less(x, lim1);
    p_t r1 = bs::Zero<p_t>();
    std::size_t nb = bs::nbtrue(test1);
    if(nb > 0)
    {
      r1 = bs::oneminus(x*detail::erf_kernel<p_t>::erf1(xx));
      if (nb >= p_t::static_size)
        return bs::if_else(test0, bs::Two<p_t>()-r1, r1);
    }
    auto test2 = bs::is_less(x, lim2);
    auto test3 = bs::logical_andnot(test2, test1);
    p_t ex = bs::exp(-xx);

    std::size_t nb1 = bs::nbtrue(test3);
    if(nb1 > 0)
    {
      p_t z = ex*detail::erf_kernel<p_t>::erfc2(x);
      r1 = bs::if_else(test1, r1, z);
      nb += nb1;
      if (nb >= p_t::static_size)
        return bs::if_else(test0, Two<p_t>()-r1, r1);
    }
    p_t z =  ex*detail::erf_kernel<p_t>::erfc3(x);
    r1 = bs::if_else(test2, r1, z);
#ifndef BOOST_SIMD_NO_INFINITIES
    r1 = if_zero_else( is_equal(x, Inf<p_t>()), r1);
#endif
    return  bs::if_else(test0, bs::Two<p_t>()-r1, r1);
  }

  template< std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<float,N,X> erfc_(BOOST_SIMD_SUPPORTS(simd_)
                       , pack<float,N,X> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<float,N,X>;
    p_t x =  bs::abs(a0);
    auto test0 = bs::is_ltz(a0);
    p_t r1 = bs::Zero<p_t>();
    auto test1 = bs::is_less(x, bs::Ratio<p_t, 2, 3>());
    p_t z = x/inc(x);

    std::size_t nb = bs::nbtrue(test1);
    if(nb > 0)
    {
      r1 = detail::erf_kernel<p_t>::erfc3(z);
      if (nb >= p_t::static_size)
        return bs::if_else(test0, bs::Two<p_t>()-r1, r1);
    }
    z -= p_t(0.4);
    p_t r2 = exp(-sqr(x))*detail::erf_kernel<p_t>::erfc2(z);
    r1 = if_else(test1, r1, r2);
#ifndef BOOST_SIMD_NO_INFINITIES
    r1 = if_zero_else( is_equal(x, Inf<p_t>()), r1);
#endif
    return bs::if_else(test0, bs::Two<p_t>()-r1, r1);
  }

  // Emulated implementation only double/float
  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N,simd_emulation_> erfc_ ( BOOST_SIMD_SUPPORTS(simd_)
                                       , pack<double,N,simd_emulation_> const& a
                                       ) BOOST_NOEXCEPT
  {
    return map_to(simd::erfc, a);
  }

  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N,simd_emulation_> erfc_ ( BOOST_SIMD_SUPPORTS(simd_)
                                      , pack<float,N,simd_emulation_> const& a
                                      ) BOOST_NOEXCEPT
  {
    return map_to(simd::erfc, a);
  }

  // std decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> erfc_ ( BOOST_SIMD_SUPPORTS(simd_)
                  , std_tag const&
                  , pack<T,N> const& a
                  ) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::erfc), a);
  }

} } }


#endif
