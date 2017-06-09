//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPX2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPX2_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/constant/expx2c1.hpp>
#include <boost/simd/detail/constant/expx2c2.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/detail/constant/maxlog.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/signnz.hpp>
#include <boost/simd/function/sqr.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/function/is_equal.hpp>
#endif

namespace boost { namespace simd { namespace detail
{
 //================================================================================================
  // One parameter
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> expx2_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    p_t x =  bs::abs(a0);
    // Represent x as an exact multiple of 1/32 plus a residual.
    p_t m = Expx2c1<p_t>()*bs::floor(fma(Expx2c2<p_t>(), x, bs::Half<p_t>()));
    p_t f =  x-m;
    // x**2 = m**2 + 2mf + f**2
    p_t u = bs::sqr(m);
    p_t u1 = fma(m+m,f,sqr(f));
    // u is exact, u1 is small.
    p_t r = bs::if_else(bs::is_greater(u+u1, bs::Maxlog<p_t>()),
                       bs::Inf<p_t>(),
                       bs::exp(u)*bs::exp(u1));
#ifndef BOOST_SIMD_NO_INFINITIES
    r =  bs::if_else(is_equal(x, Inf<p_t>()), x, r);
#endif
    return r;
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> expx2_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::expx2, a);
  }


 //================================================================================================
  // Two parameters
  // Native implementation

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> expx2_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& a0
                  , pack<T,N> const& s) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    p_t sgn =  signnz(s);
    p_t x =  a0*sgn;
    // Represent x as an exact multiple of 1/32 plus a residual.
    p_t m = Expx2c1<p_t>()*bs::floor(fma(Expx2c2<p_t>(), x, bs::Half<p_t>()));
    p_t f =  x-m;
    // x**2 = m**2 + 2mf + f**2
    p_t u = sgn*bs::sqr(m);
    p_t u1 = sgn*fma(m+m,f,sqr(f));
    // u is exact, u1 is small.
    p_t r = bs::if_else(bs::is_greater(u+u1, bs::Maxlog<p_t>()),
                        bs::Inf<p_t>(),
                        bs::exp(u)*bs::exp(u1));
#ifndef BOOST_SIMD_NO_INFINITIES
    r =  bs::if_else(is_equal(x, Inf<p_t>()), x, r);
#endif
    return r;
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> expx2_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  , pack<T,N,simd_emulation_> const& s
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::expx2, a, s);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  expx2_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return expx2(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  expx2_(BOOST_SIMD_SUPPORTS(simd_)
          , T const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return expx2(p_t(a0), a1);
  }


} } }

#endif
