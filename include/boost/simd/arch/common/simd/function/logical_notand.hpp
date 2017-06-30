//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOGICAL_NOTAND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOGICAL_NOTAND_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/function/mask2logical.hpp>
#include <boost/simd/function/bitwise_notand.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // Native implementation
  template< typename T1, std::size_t N, typename T2 >
  BOOST_FORCEINLINE as_logical_t<pack<T1,N>>
  logical_notand_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T1,N> const& a0
               , pack<T2,N> const& a1
               ) BOOST_NOEXCEPT
  {
    return mask2logical(bitwise_notand(genmask(is_nez(a0)) , genmask(is_nez(a1))));
  }

  template< typename T1, std::size_t N, typename T2 >
  BOOST_FORCEINLINE as_logical_t<pack<T1,N>>
  logical_notand_ ( BOOST_SIMD_SUPPORTS(simd_)
               , as_logical_t<pack<T1,N>> const& a0
               , as_logical_t<pack<T2,N>> const& a1
               ) BOOST_NOEXCEPT
  {
    return mask2logical(bitwise_notand(genmask(a0), genmask(a1)));
  }

  template< typename T1, std::size_t N, typename T2 >
  BOOST_FORCEINLINE as_logical_t<pack<T1,N>>
  logical_notand_ ( BOOST_SIMD_SUPPORTS(simd_)
               , as_logical_t<pack<T1,N>> const& a0
               , pack<T2,N> const& a1
               ) BOOST_NOEXCEPT
  {
    return mask2logical(bitwise_notand(genmask(a0), genmask(is_nez(a1))));
  }

  template< typename T1, std::size_t N, typename T2 >
  BOOST_FORCEINLINE as_logical_t<pack<T1,N>>
  logical_notand_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T1,N> const& a0
               , as_logical_t<pack<T2,N>> const& a1
               ) BOOST_NOEXCEPT
  {
    return mask2logical(bitwise_notand(genmask(is_nez(a0)), genmask(a1)));
  }

  template< typename T1, std::size_t N, typename T2 >
  BOOST_FORCEINLINE as_logical_t<pack<T1,N, simd_emulation_>>
  logical_notand_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T1,N,simd_emulation_> const& a0
               , pack<T2,N,simd_emulation_> const& a1
               ) BOOST_NOEXCEPT
  {
    return map_to(logical_notand, a0, a1);
  }


  //================================================================================================
  // mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  as_logical_t<pack<T2,M>>
  logical_notand_ ( BOOST_SIMD_SUPPORTS(simd_)
               , T1 a
               , pack<T2,M> const& b
               ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return simd::logical_notand(p_t(a), b);
  }

  // mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
           , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  as_logical_t<pack<T1,N>>
  logical_notand_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T1,N> const& a
               , T2 b
               ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return simd::logical_notand(a, p_t(b));
  }

} } }

#endif
