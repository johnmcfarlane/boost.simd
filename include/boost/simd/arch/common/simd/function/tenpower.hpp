//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TENPOWER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TENPOWER_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/exp10.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_odd.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>


namespace boost { namespace simd { namespace detail
{
 //================================================================================================
  // regular case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N>
  vtenpower_(pack<T,N> a, detail::case_<0> const&) BOOST_NOEXCEPT
  {
    // tenpower on real
    return exp10(a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  f_t<pack<T,N>>
  vtenpower_(pack<T,N> a, detail::case_<1> const&) BOOST_NOEXCEPT
  {
    // tenpower on signed integral values
    using p_t = pack<T,N>;
    using r_t = f_t<p_t>;

    r_t res = One<r_t>();
    r_t base = Ten<r_t>();
    p_t expo = bs::abs(a);
    while(any(expo))
    {
      res =  res * if_else(is_odd(expo), base, One<r_t>());
      expo =  shift_right(expo, 1);
      base = sqr(base);
    }
    return if_else(is_ltz(a), simd::rec(res), res);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  f_t<pack<T,N>>
  vtenpower_(pack<T,N> a0, detail::case_<2> const&) BOOST_NOEXCEPT
  {
    // tenpower on unsigned values is identity
    using p_t = pack<T,N>;
    using r_t = f_t<p_t>;

    r_t res = One<r_t>();
    r_t base = Ten<r_t>();
    p_t expo = bs::abs(a0);
    while(any(expo))
    {
      res =  res * if_else(is_odd(expo), base, One<r_t>());
      expo =  shift_right(expo, 1);
      base = sqr(base);
    }
    return res;
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE f_t<pack<T,N>>
  tenpower_(BOOST_SIMD_SUPPORTS(simd_)
           , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vtenpower_(a,fsu_picker<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE f_t<pack<T,N,simd_emulation_>>
  tenpower_ ( BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N,simd_emulation_> const& a
            ) BOOST_NOEXCEPT
  {
    return map_to(simd::tenpower, a);
  }

} } }


#endif

