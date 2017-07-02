//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CLZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CLZ_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/ffs.hpp>
#include <boost/simd/function/reversebits.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T,N>> clz_(BOOST_SIMD_SUPPORTS(simd_)
                      , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    using result_t = as_ui_t<pack<T,N>>;
    result_t t =  bitwise_cast<result_t>(a);
    BOOST_ASSERT_MSG( assert_all(t), "clz not defined for 0" );
    return bitwise_cast<result_t>(dec(bs::ffs(bs::reversebits(t))));
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T,N,simd_emulation_>> clz_ ( BOOST_SIMD_SUPPORTS(simd_)
                                       , pack<T,N,simd_emulation_> const& a
                                       ) BOOST_NOEXCEPT
  {
    return map_to(simd::clz, a);
  }


} } }


#endif

