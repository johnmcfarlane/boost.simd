//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FMA_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/config.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/group.hpp>
#include <boost/simd/function/split.hpp>
#include <boost/simd/function/two_add.hpp>
#include <boost/simd/function/two_prod.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/pedantic.hpp>

#ifndef BOOST_SIMD_DONT_CARE_FMA_OVERFLOW
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/maxmag.hpp>
#include <boost/simd/function/minmag.hpp>
#endif

namespace boost { namespace simd { namespace detail
{
  //==========================================================================
  //regular (no decorator)
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N> const & a0
      , pack<T,N> const & a1
      , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    return a0*a1+a2;
  }

  //==========================================================================
  //emulation (no decorator)
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N,simd_emulation_> const & a0
      , pack<T,N,simd_emulation_> const & a1
      , pack<T,N,simd_emulation_> const & a2) BOOST_NOEXCEPT
  {
    return map_to(fma, a0, a1, a2);
  }
  //==========================================================================
  //pedantic_ decorator
  template<std::size_t N, typename X>
  BOOST_FORCEINLINE pack<float,N,X>
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , pack<float,N,X> const & a0
      , pack<float,N,X> const & a1
      , pack<float,N,X> const & a2) BOOST_NOEXCEPT
  {
    auto s0 = split(a0);
    auto s1 = split(a1);
    auto s2 = split(a2);
    return group(s0[0]*s1[0]+s2[0], s0[1]*s1[1]+s2[1]);
  }

  template<std::size_t N, typename X>
  BOOST_FORCEINLINE pack<double,N,X>
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , pack<double,N,X> const & a0
      , pack<double,N,X> const & a1
      , pack<double,N,X> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<double, N, X>;
    p_t p, rp, s, rs;
#ifndef BOOST_SIMD_DONT_CARE_FMA_OVERFLOW
    using ip_t = bd::as_integer_t<p_t>;
    p_t amax =  a0; maxmag(a0, a1);
    p_t amin =  a1; minmag(a0, a1);
    ip_t e0 = -shift_right(exponent(amax), 1);
    amax = pedantic_(ldexp)(amax, e0);
    p_t a02 = pedantic_(ldexp)(a2, e0);
    std::tie(p, rp) = two_prod(amax, amin);
    std::tie(s, rs) = two_add(p, a02);
    return pedantic_(ldexp)(s+(rp+rs), -e0);
#else
    std::tie(p, rp) = two_prod(a0, a1);
    std::tie(s, rs) = two_add(p, a2);
    return s+(rp+rs);
#endif
  }

  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE pack<T,N,X>
  pifma_( pack<T,N,X> const & a0
        , pack<T,N,X> const & a1
        , pack<T,N,X> const & a2
        , std::true_type const &) BOOST_NOEXCEPT
  {
    // correct fma has to ensure "no intermediate overflow".
    // This is done in the case of signed integers by transtyping to unsigned type
    // to perform the computations in a guaranteed 2-complement environment
    // since signed integer overflow in C++ produces "undefined results"
    using p_t =  pack<T,N,X>;
    using pu_t =  bd::as_integer_t<p_t, unsigned>;
    return bitwise_cast<p_t>(fma(bitwise_cast<pu_t>(a0), bitwise_cast<pu_t>(a1), bitwise_cast<pu_t>(a2)));
  }

  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE pack<T,N,X>
  pifma_( pack<T,N,X> const & a0
        , pack<T,N,X> const & a1
        , pack<T,N,X> const & a2
        , std::false_type const &) BOOST_NOEXCEPT
  {
    return a0*a1+a2;
  }

  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE pack<T,N,X>
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , pack<T,N,X> const & a0
      , pack<T,N,X> const & a1
      , pack<T,N,X> const & a2) BOOST_NOEXCEPT
  {
    return pifma_(a0, a1, a2, std::is_signed<T>());
  }

  //mixed calls two packs
  // no decorator
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value, pack<T,N>>::type
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , U a0
      , pack<T,N> const & a1
      , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(p_t(a0), a1, a2);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value, pack<T,N>>::type
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N> const & a0
      , U a1
      , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(a0, p_t(a1), a2);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N> const & a0
      , pack<T,N> const & a1
      , U a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(p_t(a0), a1, p_t(a2));
  }

  //mixed calls one packs
  // no decorator
  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value &&
                          std::is_convertible<V, T>::value, pack<T,N>>::type
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N> const & a0
      , U a1
      , V a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(p_t(a0), a1, a2);
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value&&
                          std::is_convertible<V, T>::value, pack<T,N>>::type
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , U a0
      , V a1
      , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(a0, p_t(a1), a2);
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value&&
                          std::is_convertible<V, T>::value, pack<T,N>>::type
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , U a0
      , pack<T,N> const & a1
      , V a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(p_t(a0), a1, p_t(a2));
  }

  //mixed calls two packs
  // pedantic_ decorator
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value, pack<T,N>>::type
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , U a0
      , pack<T,N> const & a1
      , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(p_t(a0), a1, a2);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value, pack<T,N>>::type
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , pack<T,N> const & a0
      , U a1
      , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(a0, p_t(a1), a2);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , pack<T,N> const & a0
      , pack<T,N> const & a1
      , U a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(p_t(a0), a1, p_t(a2));
  }

  //mixed calls one packs
  // pedantic_ decorator
  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value &&
                          std::is_convertible<V, T>::value, pack<T,N>>::type
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , pack<T,N> const & a0
      , U a1
      , V a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(p_t(a0), a1, a2);
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value&&
                          std::is_convertible<V, T>::value, pack<T,N>>::type
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , U a0
      , V a1
      , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(a0, p_t(a1), a2);
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value&&
                          std::is_convertible<V, T>::value, pack<T,N>>::type
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , U a0
      , pack<T,N> const & a1
      , V a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return fma(p_t(a0), a1, p_t(a2));
  }

  //==========================================================================
  //std decorator
  template<typename T
           , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE T
  fma_(BOOST_SIMD_SUPPORTS(simd_)
      , std_tag const&
      , T a0
      , T a1
      , T a2 ) BOOST_NOEXCEPT
  {
    return map_to(std_(fma), a0, a1, a2);
  }

} } }


#endif
