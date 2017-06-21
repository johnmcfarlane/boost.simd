//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TOINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TOINT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/modf.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular case
  template<typename T, std::size_t N> //floating
  BOOST_FORCEINLINE si_t<pack<T,N>>
  v_toint_(pack<T,N> a
       , detail::case_<0> const&) BOOST_NOEXCEPT
  {
    return map_to(simd::toint, a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  si_t<pack<T,N>>
  v_toint_(pack<T,N> a
          , detail::case_<1> const&) BOOST_NOEXCEPT
  {
    return a;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  si_t<pack<T,N>>
  v_toint_(pack<T,N> a
          , detail::case_<2> const&) BOOST_NOEXCEPT
  {
    using r_t =  si_t<pack<T,N>>;
    return bitwise_cast<r_t>(a);
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  si_t<pack<T,N>>
  toint_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return v_toint_(a,fsu_picker<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE si_t<pack<T,N,simd_emulation_>>
  toint_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT
  {
    return map_to(simd::toint, a);
  }

  //================================================================================================
  //pedantic_ decorator
  template<std::size_t N, typename X >
  BOOST_FORCEINLINE pack<int64_t,N,X>
  toint_(BOOST_SIMD_SUPPORTS(simd_)
        , pedantic_tag const &
        , pack<double,N,X> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<double,N,X>;
    using r_t = pack<int64_t,N,X>;
    const int32_t Vim32 = Valmin<int32_t>();
    const r_t Vim =  r_t(Vim32);
    const r_t Vax = -r_t(Vim32);
    constexpr int S = 32;
    p_t z = ldexp(a0, -S);
    p_t t1, t2;
    std::tie(t1, t2) =  modf(z);
    t1 = ldexp(t1, S); // abs(t1) < 2^32
    r_t z1 = toint(t1)+ ldexp(toint(t2), S);
    return if_else(logical_and(z1 == Vim, is_gtz(a0)), Vax, z1);
  }

  template<typename T, std::size_t N, typename X >
  BOOST_FORCEINLINE si_t<pack<T,N,X>>
  toint_(BOOST_SIMD_SUPPORTS(simd_)
        , pedantic_tag const &
        , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return toint(a);
  }


  //================================================================================================
  //saturated_ decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  si_t<pack<T,N>>
  vs_toint_(pack<T,N> a0
           , detail::case_<0> const&) BOOST_NOEXCEPT
  {
    using p_t  = pack<T,N>;
    using r_t  = si_t<pack<T,N>>;
    using sr_t = bd::scalar_of_t<r_t>;
    const p_t Vax(bs::Valmax<sr_t>());
    const p_t Vix(bs::Valmin<sr_t>());
#ifndef BOOST_SIMD_NO_NANS
    p_t aa0 = if_zero_else(is_nan(a0), a0);
    return if_else(bs::is_less_equal(aa0, Vix), Valmin<r_t>(),
                   if_else(bs::is_greater_equal(aa0, Vax), Valmax<r_t>(),
                           pedantic_(toint)(aa0)
                          )
                  );
#else
    return if_else(bs::is_less_equal(a0, Vix), Valmin<r_t>(),
                   if_else(bs::is_greater_equal(a0, Vax), Valmax<r_t>(),
                           pedantic_(toint)(a0)
                          )
                  );
#endif
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  si_t<pack<T,N>>
  vs_toint_(pack<T,N>a
           , detail::case_<1> const&) BOOST_NOEXCEPT
  {
    return a;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE si_t<pack<T,N>>
  vs_toint_(pack<T,N> a0
           , detail::case_<2> const&) BOOST_NOEXCEPT
  {
    using r_t = si_t<pack<T,N>>;
    return bitwise_cast<r_t>(saturate<r_t>(a0));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  si_t<pack<T,N>>
  toint_(BOOST_SIMD_SUPPORTS(simd_)
        , saturated_tag const &
        , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vs_toint_(a,fsu_picker<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE si_t<pack<T,N,simd_emulation_>>
  toint_ ( BOOST_SIMD_SUPPORTS(simd_)
         , saturated_tag const &
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT
  {
    return map_to(saturated_(simd::toint), a);
  }

} } }


#endif

