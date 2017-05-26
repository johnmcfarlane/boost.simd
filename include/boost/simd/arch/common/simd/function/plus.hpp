//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_PLUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_PLUS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitwise_ornot.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/detail/function/map_to.hpp>
#include <boost/simd/detail/meta/pick.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // regular cases
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE pack<T,N,X> plus_ ( BOOST_SIMD_SUPPORTS(simd_)
                                      , pack<T,N,X> const& a
                                      , pack<T,N,X> const& b
                                      ) BOOST_NOEXCEPT
  {
    return map_to(simd::plus, a, b);
  }

  // -----------------------------------------------------------------------------------------------
  // saturated cases
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> splus_( pack<T,N> const& a, pack<T,N> const& b
                                    , case_<0> const& // IEEE saturated plus
                                    ) BOOST_NOEXCEPT
  {
    return a + b;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> splus_( pack<T,N> const& a, pack<T,N> const& b
                                    , case_<1> const& // signed integers saturated plus
                                    ) BOOST_NOEXCEPT
  {
    using type = pack<T, N>;
    using utype = pack< typename tt_::make_unsigned<T>::type, N>;
    enum sizee { value = sizeof(T)*CHAR_BIT-1 };

    auto ux = bitwise_cast<utype>(a);
    auto uy = bitwise_cast<utype>(b);
    auto res = ux + uy;

    ux = shr(ux, sizee::value) + utype(Valmax<T>());
    auto t = is_gez(bitwise_cast<type>(bitwise_ornot(ux ^ uy, uy ^ res )));

    return bitwise_cast<type>(if_else(t, ux, res));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> splus_( pack<T,N> const& a, pack<T,N> const& b
                                    , case_<2> const& // unsigned integers saturated plus
                                    ) BOOST_NOEXCEPT
  {
    auto s = a + b;
    return s | genmask(s < a);
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> plus_ ( BOOST_SIMD_SUPPORTS(simd_)
                                    , saturated_tag const&, pack<T,N> const& a, pack<T,N> const& b
                                    ) BOOST_NOEXCEPT
  {
    return splus_ ( a, b
                  , typename detail::pick < T , tt_::is_floating_point
                                              , tt_::is_signed
                                              , tt_::is_unsigned
                                          >::type{}
                  );
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> plus_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                    , saturated_tag const&
                                                    , pack<T,N,simd_emulation_> const& a
                                                    , pack<T,N,simd_emulation_> const& b
                                                    ) BOOST_NOEXCEPT
  {
    return map_to( saturated_(simd::plus), a, b);
  }

  //================================================================================================
  // mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T2,M> plus_ ( BOOST_SIMD_SUPPORTS(simd_)
                   , T1 a
                   , pack<T2,M> const& b
                   ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return simd::plus(p_t(a), b);
  }

  // mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
    , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T1,N> plus_ ( BOOST_SIMD_SUPPORTS(simd_)
                   , pack<T1,N> const& a
                   , T2 b
                   ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return simd::plus(a, p_t(b));
  }

  // saturated mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T2, M> plus_ ( BOOST_SIMD_SUPPORTS(simd_)
                    , saturated_tag const&
                    , T1 a
                    , pack<T2,M> const& b
                    ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return simd::plus(p_t(a), b);
  }

  // saturated mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
    , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T1,N> plus_ ( BOOST_SIMD_SUPPORTS(simd_)
                   , saturated_tag const&
                   , pack<T1,N> const& a
                   , T2 b
                   ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return simd::plus(a, p_t(b));
  }


} } }

#endif
