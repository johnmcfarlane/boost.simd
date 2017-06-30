//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOGICAL_NOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOGICAL_NOT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/complement.hpp>
#include <boost/simd/function/mask2logical.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace boost { namespace simd { namespace detail
{
 // Native implementations
   template<typename T, std::size_t N>
   BOOST_FORCEINLINE as_logical_t<pack<T,N>>
   logical_not_ (BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a0) BOOST_NOEXCEPT
   {
     return  is_eqz(a0);
   }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto logical_not_ (BOOST_SIMD_SUPPORTS(simd_)
                   ,as_logical_t<pack<T,N>> const& a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    mask2logical(complement(a0))
  )

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_logical_t<pack<T,N,simd_emulation_>>
  logical_not_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N,simd_emulation_> const& a
               ) BOOST_NOEXCEPT
  {
    return map_to(simd::logical_not, a);
  }

} } }

#endif
