//==================================================================================================
/**

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ASINH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ASINH_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/oneosqrteps.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/average.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/hypot.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/sqr.hpp>
#include <type_traits>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/is_equal.hpp>
#endif

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vasinh_( pack<T,N> const& a, std::true_type const&) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    // Exhaustive test for: boost::dispatch::functor<bs::tag::asinh_, bs::tag::sse4_2_>
    //              versus: float(boost::math::asinh(double)
    //              With T: bs::native<float, bs::tag::sse_, void>
    //            in range: [-3.40282e+38, 3.40282e+38]
    // 4278190076 values computed.
    // 3619320676 values (84.60%)  within 0.0 ULPs
    //  658843138 values (15.40%)  within 0.5 ULPs
    //      26262 values ( 0.00%)  within 1.0 ULPs
    p_t x = bs::abs(a);
    bs::as_logical_t<p_t> lthalf = is_less(x,Half<p_t>());
    p_t x2 = bs::sqr(x);
    p_t z = Zero<p_t>();
    std::size_t nb = nbtrue(lthalf);
    p_t bts = bitofsign(a);
    if(nb > 0)
    {
      z = horn<p_t
        , 0x3f800000
        , 0xbe2aa9ad
        , 0x3d9949b1
        , 0xbd2ee581
        , 0x3ca4d6e6
        > (x2)*x;

      if(nb >= p_t::static_size) return  bitwise_xor(z, bts);
    }
    p_t tmp =  if_else(is_greater(x, Oneosqrteps<p_t>()),
                     x, average(x, hypot(One<p_t>(), x)));
#ifndef  BOOST_SIMD_NO_NANS
    return if_nan_else(is_nan(a), bitwise_xor(if_else(lthalf, z, log(tmp)+Log_2<p_t>()), bts));
#else
    return bitwise_xor(if_else(lthalf, z, log(tmp)+Log_2<p_t>()), bts);
#endif
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vasinh_( pack<T,N> const& a, std::false_type const&) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    p_t x =  bs::abs(a);
    auto test = is_greater(x,Oneosqrteps<p_t>());
    p_t z = if_else(test,dec(x), x+sqr(x)/bs::inc(hypot(One<p_t>(), x)));
#ifndef BOOST_SIMD_NO_INFINITIES
    z = if_else(is_equal(x, Inf<p_t>()),x, z);
#endif
    z =  if_plus(test, log1p(z), Log_2<p_t>());
    return bitwise_xor(bitofsign(a), z);
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> asinh_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vasinh_(a, std::is_same<T, float>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> asinh_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pack<T,N,simd_emulation_> const& a
                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::asinh, a);
  }


  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> asinh_( BOOST_SIMD_SUPPORTS(simd_)
                    , std_tag const&
                    , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::asinh), a);
  }


} } }

#endif
