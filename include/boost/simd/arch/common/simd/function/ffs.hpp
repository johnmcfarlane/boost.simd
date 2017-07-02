//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FFS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FFS_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/firstbitset.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/detail/meta/size_picker.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T,N>> vffs_(pack<T,N> const& a0
                       , detail::case_<0> const&) BOOST_NOEXCEPT // 64bits

  {
    return map_to(simd::ffs, a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T,N>> vffs_(pack<T,N> const& a0
                       , detail::case_<1> const&) BOOST_NOEXCEPT // 32bits

  {
    using result_t = as_ui_t<pack<T,N>>;
    result_t v =  bitwise_cast<result_t>(firstbitset(a0));
    return  bitwise_and(genmask(v)
                       ,inc(bitwise_or(
                              bitwise_or(
                                bitwise_or(
                                  bitwise_or(
                                    (-( genmask(bitwise_and(v,result_t(0xAAAAAAAA)))))
                                    ,shift_left(-(genmask(bitwise_and(v,result_t(0xCCCCCCCC)))),1))
                                  , shift_left(-(genmask(bitwise_and(v,result_t(0xF0F0F0F0)))),2))
                                , shift_left(-(genmask(bitwise_and(v,result_t(0xFF00FF00)))), 3))
                              , shift_left(-(genmask(bitwise_and(v,result_t(0xFFFF0000)))),4))));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T,N>> vffs_(pack<T,N> const& a0
                       , detail::case_<2> const&) BOOST_NOEXCEPT // 16bits

  {
    using result_t = as_ui_t<pack<T,N>>;
    result_t v = bitwise_cast<result_t>( firstbitset(a0));
    return  bitwise_and(genmask(v)
                       ,inc(bitwise_or(
                              bitwise_or(
                                bitwise_or(
                                  (-( genmask(bitwise_and(v, result_t(0xAAAA)))))
                                  ,shift_left(-( genmask(bitwise_and(v,result_t(0xCCCC)))),1))
                                ,shift_left(-( genmask(bitwise_and(v,result_t(0xF0F0)))),2))
                              ,shift_left(-( genmask(bitwise_and(v,result_t(0xFF00)))),3))));

  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T,N>> vffs_(pack<T,N> const& a0
                       , detail::case_<3> const&) BOOST_NOEXCEPT // 8bits

  {
    using result_t = as_ui_t<pack<T,N>>;
    result_t v = bitwise_cast<result_t>(firstbitset(a0));
    return  bitwise_and(genmask(v)
                       ,inc(bitwise_or(
                              bitwise_or(
                                (-( genmask(bitwise_and(v,result_t(0xAA)))))
                                , shift_left(-(genmask(bitwise_and(v, result_t(0xCC)))),1))
                              , shift_left(-(genmask(bitwise_and(v, result_t(0xF0)))),2))));

  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_ui_t<pack<T,N>> ffs_ ( BOOST_SIMD_SUPPORTS(simd_)
                                         , pack<T,N> const& a
                                         ) BOOST_NOEXCEPT
  {
    return vffs_( a, size_picker<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_ui_t<pack<T,N,simd_emulation_>> ffs_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                         , pack<T,N,simd_emulation_> const& a
                                                         ) BOOST_NOEXCEPT
  {
    return map_to(simd::ffs, a);
  }

} } }

#endif
