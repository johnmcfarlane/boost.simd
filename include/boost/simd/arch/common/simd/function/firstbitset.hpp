//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FIRSTBITSET_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FIRSTBITSET_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/complement.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
 // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T,N>> firstbitset_(BOOST_SIMD_SUPPORTS(simd_)
                              , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    using result_t = as_ui_t<pack<T,N>>;
    return bitwise_and(inc(complement(bitwise_cast<result_t>(a0))), a0);
  }

//   // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T,N,simd_emulation_>> firstbitset_ ( BOOST_SIMD_SUPPORTS(simd_)
                                              , pack<T,N,simd_emulation_> const& a
                                              ) BOOST_NOEXCEPT
  {
    return map_to(simd::firstbitset, a);
  }

} } }


#endif

