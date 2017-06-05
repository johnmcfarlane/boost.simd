//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPRECNEGC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPRECNEGC_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/expm1.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> exprecnegc_(BOOST_SIMD_SUPPORTS(simd_)
                       , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return -expm1(-rec(a));
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> exprecnegc_ ( BOOST_SIMD_SUPPORTS(simd_)
                                        , pedantic_tag const&
                                        , pack<T,N,simd_emulation_> const& a
                                        ) BOOST_NOEXCEPT
  {
    return map_to(simd::exprecnegc, a);
  }

} } }


#endif
