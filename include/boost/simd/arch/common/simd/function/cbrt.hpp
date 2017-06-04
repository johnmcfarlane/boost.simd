//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CBRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CBRT_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>

#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/third.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/negate.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>

#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/twotomnmbo_3.hpp>
#include <boost/simd/constant/twotonmb.hpp>
#include <boost/simd/function/is_less.hpp>
#endif

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/logical_or.hpp>
#endif

namespace boost { namespace simd { namespace detail
{
  template<std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<float,N, X> cbrt_( BOOST_SIMD_SUPPORTS(simd_)
                        , pack<float,N, X> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<float, N>;
    p_t z =  bs::abs(a0);
    using int_type =  bd::as_integer_t<p_t, signed>;
#ifndef BOOST_SIMD_NO_DENORMALS
    auto denormal = is_less(z, Smallestposval<p_t>());
    z = if_else(denormal, z*Twotonmb<p_t>(), z);
    p_t f = if_else(denormal, Twotomnmbo_3<p_t>(), One<p_t>());
#endif
    const p_t CBRT2  = Constant< p_t, 0x3fa14518> ();
    const p_t CBRT4  = Constant< p_t, 0x3fcb2ff5> ();
    const p_t CBRT2I = Constant< p_t, 0x3f4b2ff5> ();
    const p_t CBRT4I = Constant< p_t, 0x3f214518> ();
    int_type e;
    p_t x; std::tie(x, e) = ifrexp(z);
    x = horn <p_t,
      0x3ece0609,
      0x3f91eb77,
      0xbf745265,
      0x3f0bf0fe,
      0xbe09e49a
      > (x);
    auto flag = is_gez(e);
    int_type e1 =  bs::abs(e);
    int_type rem = e1;
    e1 /= Three<int_type>();
    rem -= e1*Three<int_type>();
    e = negate(e1, e);
    const p_t cbrt2 = if_else(flag, CBRT2, CBRT2I);
    const p_t cbrt4 = if_else(flag, CBRT4, CBRT4I);
    p_t fact = if_else(is_equal(rem, One<int_type>()), cbrt2, One<p_t>());
    fact = if_else(is_equal(rem, Two<int_type>()), cbrt4, fact);
    x = ldexp(x*fact, e);
    x -= (x-z/sqr(x))*Third<p_t>();
#ifndef BOOST_SIMD_NO_DENORMALS
    x = bitwise_or(x, bitofsign(a0))*f;
#else
    x = bitwise_or(x, bitofsign(a0));
#endif
#ifndef BOOST_SIMD_NO_INFINITIES
    return if_else(logical_or(is_eqz(a0),is_inf(a0)), a0, x);
#else
    return if_else(is_eqz(a0), a0, x);
#endif
  }

  template<std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<double,N, X> cbrt_( BOOST_SIMD_SUPPORTS(simd_)
                         , pack<double,N, X> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<double, N>;
    using int_type =  bd::as_integer_t<p_t, signed>;
    p_t z =  bs::abs(a0);
#ifndef BOOST_SIMD_NO_DENORMALS
    auto denormal = is_less(z, Smallestposval<p_t>());
    z = if_else(denormal, z*Twotonmb<p_t>(), z);
    p_t f = if_else(denormal, Twotomnmbo_3<p_t>(), One<p_t>());
#endif
    const p_t CBRT2  = Constant< p_t, 0x3ff428a2f98d728bll> ();
    const p_t CBRT4  = Constant< p_t, 0x3ff965fea53d6e3dll> ();
    const p_t CBRT2I = Constant< p_t, 0x3fe965fea53d6e3dll> ();
    const p_t CBRT4I = Constant< p_t, 0x3fe428a2f98d728bll> ();
    int_type e;
    p_t x;
    std::tie(x, e) = ifrexp(z);
    x = horn <p_t,
      0x3fd9c0c12122a4fell,
      0x3ff23d6ee505873all,
      0xbfee8a4ca3ba37b8ll,
      0x3fe17e1fc7e59d58ll,
      0xbfc13c93386fdff6ll >  (x);
    auto flag = is_gez(e);
    int_type e1 =  bs::abs(e);
    int_type rem = e1;
    e1 /= Three<int_type>();
    rem -= e1*Three<int_type>();
    e =  negate(e1, e);
    const p_t cbrt2 = if_else(flag, CBRT2, CBRT2I);
    const p_t cbrt4 = if_else(flag, CBRT4, CBRT4I);
    p_t fact = if_else(is_equal(rem, One<int_type>()), cbrt2, One<p_t>());
    fact = if_else(is_equal(rem, Two<int_type>()), cbrt4, fact);
    x = ldexp(x*fact, e);
    x -= (x-z/sqr(x))*Third<p_t>();
    x -= (x-z/sqr(x))*Third<p_t>(); //two newton passes
#ifndef BOOST_SIMD_NO_DENORMALS
    x = bitwise_or(x, bitofsign(a0))*f;
#else
    x = bitwise_or(x, bitofsign(a0));
#endif
#ifndef BOOST_SIMD_NO_INFINITIES
    return if_else(logical_or(is_eqz(a0),is_inf(a0)), a0, x);
#else
    return if_else(is_eqz(a0), a0, x);
#endif
  }

  // Emulated implementation
  template< std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N,simd_emulation_> cbrt_ ( BOOST_SIMD_SUPPORTS(simd_)
                                       , pack<double,N,simd_emulation_> const& a
                                       ) BOOST_NOEXCEPT
  {
    return map_to(simd::cbrt, a);
  }
  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N,simd_emulation_> cbrt_ ( BOOST_SIMD_SUPPORTS(simd_)
                                      , pack<float,N,simd_emulation_> const& a
                                      ) BOOST_NOEXCEPT
  {
    return map_to(simd::cbrt, a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> cbrt_( BOOST_SIMD_SUPPORTS(simd_)
                   , std_tag const&
                   , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return map_to(std::cbrt, a);
  }

} } }

#endif
