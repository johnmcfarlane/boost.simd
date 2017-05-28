//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITOFSIGN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITOFSIGN_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vbitofsign_( pack<T,N> const& a, std::true_type const &) BOOST_NOEXCEPT
  {
    return bitwise_and(a, Signmask<pack<T,N>>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vbitofsign_( pack<T,N> const& , std::false_type const &) BOOST_NOEXCEPT
  {
    return Zero<pack<T,N>>();
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> bitofsign_(BOOST_SIMD_SUPPORTS(simd_)
              , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vbitofsign_(a, std::is_signed<T>()); ;
  }

 // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> bitofsign_(BOOST_SIMD_SUPPORTS(simd_)
                                      , pack<T,N,simd_emulation_> const& a) BOOST_NOEXCEPT
  {
    return map_to(simd::bitofsign, a);
  }

} } }

#endif

