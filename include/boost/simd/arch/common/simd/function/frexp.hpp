//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FREXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FREXP_HPP_INCLUDED


#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/pack_cast.hpp>

namespace boost { namespace simd { namespace detail
{
  template < typename T> using pair_t = std::pair<T, T>;

  //================================================================================================
  // regular case
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pair_t<pack < T, N>>
  frexp_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    auto r = ifrexp(a0);
    return {r.first, pack_cast<T>(r.second)};
  }

  //================================================================================================
  // pedantic case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pair_t<pack < T, N>>
  frexp_(BOOST_SIMD_SUPPORTS(simd_)
        , pedantic_tag const&
        , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    auto r = pedantic_(ifrexp)(a0);
    return {r.first, pack_cast<T>(r.second)};
  }


  //================================================================================================
  // raw case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pair_t<pack < T, N>>
  frexp_(BOOST_SIMD_SUPPORTS(simd_)
        , raw_tag const&
        , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    auto r = raw_(ifrexp)(a0);
    return {r.first, pack_cast<T>(r.second)};
  }

  //================================================================================================
  // std case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pair_t<pack < T, N>>
  frexp_(BOOST_SIMD_SUPPORTS(simd_)
        , std_tag const&
        , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    auto r = std_(ifrexp)(a0);
    return {r.first, pack_cast<T>(r.second)};
  }

} } }

#endif
