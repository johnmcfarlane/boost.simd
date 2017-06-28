//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NTHROOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NTHROOT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_even.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/pow_abs.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/if_plus.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  // Regular (no decorator
  // Native implementation
  template<typename T, std::size_t N, typename U
           , typename =  typename std::enable_if<std::is_integral<U>::value &&
                                                 (sizeof(T) == sizeof(U))>
  >
  BOOST_FORCEINLINE
  pack<T,N>
  nthroot_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const& a0
          , pack<U,N> const& a1
          ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    p_t x =  bs::abs(a0);
    p_t aa1 = bs::tofloat(a1);
    p_t y = bs::raw_(bs::pow_abs)(x,rec(aa1));
    auto nul_a1 =  bs::is_eqz(bitwise_cast<p_t>(a1));
    auto is_ltza0 = is_ltz(a0);
    auto is_odda1 = is_odd(a1);
    p_t p = raw_(bs::pow_abs)(y, aa1);
    y = bs::if_plus( bs::logical_or(bs::is_nez(y), nul_a1)
                   , y
                   , -(p - x)/(aa1*p/y)
                   );
    // Correct numerical errors (since, e.g., 64^(1/3) is not exactly 4)
    // by one iteration of Newton's method
    auto test =  logical_andnot(is_ltza0, is_odda1);
    auto done =  test;
    y = if_nan_else(test, y);  // a0 < O and a1 is not odd
    auto newtest =  is_equal(x, One<p_t>());
    test  = logical_andnot(newtest, done);
    done  = logical_or(done, newtest);
    y = if_else(test, a0, y); // 1^a1 or (-1)^a1
    newtest =  nul_a1;
    test  = logical_andnot(newtest, done);
    done  = logical_or(done, newtest);
    y =  if_else(test,
                 if_zero_else(is_less(x, One<p_t>()),
                              sign(a0)*Inf<p_t>()
                             ),
                 y);
    newtest =  is_eqz(a0);
    test  = logical_andnot(newtest, done);
    done  = logical_or(done, newtest);
    y =  if_zero_else(test, y);
#ifndef BOOST_SIMD_NO_INFINITIES
    newtest =  is_inf(a0);
    test  = logical_andnot(newtest, done);
    done  = logical_or(done, newtest);
    y =  if_else(test, if_else(is_nez(a1), a0, One<p_t>()), y);
#endif
    return bs::bitwise_or(y, bs::bitofsign(a0));
  }

  // Emulated implementation
  template<typename T, std::size_t N, typename U
           , typename =  typename std::enable_if<std::is_integral<U>::value && sizeof(T) == sizeof(U)>
  >
 BOOST_FORCEINLINE
  pack<T,N,simd_emulation_>
  nthroot_ ( BOOST_SIMD_SUPPORTS(simd_)
           , pack<T,N,simd_emulation_> const& a0
           , pack<U,N,simd_emulation_> const& a1
           ) BOOST_NOEXCEPT
  {
    return map_to(simd::nthroot, a0, a1);
  }

  //==============================================================================
  // mixed calls
  // regular
  template<typename T, std::size_t N,  typename U
           , typename = typename std::enable_if<std::is_integral<U>::value &&
  (sizeof(T) == sizeof(U))>
  >
  BOOST_FORCEINLINE
  pack<T,N> nthroot_(BOOST_SIMD_SUPPORTS(simd_)
                    ,  pack<T,N> const & a0
                    , U a1
                    ) BOOST_NOEXCEPT
  {
    using pi_t = pack<i_t<U>,N>;
    return  nthroot(a0, pi_t(a1));
  }

  template<typename T, std::size_t N,  typename U
         , typename = typename std::enable_if<std::is_integral<U>::value &&
                                                (sizeof(T) == sizeof(U))>
  >
  BOOST_FORCEINLINE
  pack<T,N> nthroot_(BOOST_SIMD_SUPPORTS(simd_)
                    , T a0
                   , pack<U,N> const & a1
                   ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return  nthroot(p_t(a0), a1);
  }


  //////////////////////////////////////////////////////////////////////////////////
  // Raw decorator
  // Native implementation
  template<typename T, std::size_t N, typename U
           , typename = typename std::enable_if<std::is_integral<U>::value &&
           (sizeof(T) == sizeof(U))>
  >
  BOOST_FORCEINLINE  pack<T,N>
  nthroot_(BOOST_SIMD_SUPPORTS(simd_)
          , raw_tag const &
          , pack<T,N> const& a0
          , pack<U,N> const& a1
          ) BOOST_NOEXCEPT
  {
    auto aa1 = simd::abs(a1);
    auto aa0 = simd::abs(a0);
    auto y = sign(a0)*bs::exp(bs::log(aa0)/tofloat(aa1));
    auto l =  is_ltz(aa1);
    y =  if_nan_else(logical_and(l, is_even(a1)), y);
    return if_else(is_ltz(a1), rec(y), y);
  }

  // Emulated implementation
  template<typename T, std::size_t N, typename U
            , typename = typename std::enable_if<std::is_integral<U>::value &&
                                                (sizeof(T) == sizeof(U))>
  >
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_>
  nthroot_ ( BOOST_SIMD_SUPPORTS(simd_)
           , raw_tag const &
           , pack<T,N,simd_emulation_> const& a0
           , pack<U,N,simd_emulation_> const& a1
           ) BOOST_NOEXCEPT
  {
    return map_to(raw_(simd::nthroot), a0, a1);
  }

   //==================================================================================
  // mixed calls
  // raw
  template<typename T, std::size_t N,  typename U
           , typename = typename  std::enable_if<std::is_integral<U>::value && sizeof(T) == sizeof(U)>
  >
  BOOST_FORCEINLINE
  pack<T,N> nthroot_( BOOST_SIMD_SUPPORTS(simd_)
                    , raw_tag const &
                    , pack<T,N> const & a0
                    , U a1
                    ) BOOST_NOEXCEPT
  {
    using pi_t = pack<i_t<U>,N>;
    return  raw_(nthroot)(a0, pi_t(a1));
  }

  template<typename T, std::size_t N,  typename U
           , typename = typename std::enable_if<std::is_integral<U>::value && sizeof(T) == sizeof(U)>
  >
  BOOST_FORCEINLINE
  pack<T,N> nthroot_( BOOST_SIMD_SUPPORTS(simd_)
                    , raw_tag const &
                    , T a0
                    , pack<U,N> const & a1
                    ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return  raw_(nthroot)(p_t(a0), a1);
  }

} } }

#endif
