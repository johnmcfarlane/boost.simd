//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLAT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/insert.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/as.hpp>
#include <initializer_list>

#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4244) // conversion and loss of data
#endif

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-braces"
#endif

namespace boost { namespace simd { namespace detail
{
  template<typename Pack, typename... N, typename Value>
  BOOST_FORCEINLINE void splat_unroll(Pack& p, nsm::list<N...> const&, Value const& v)
  {
    (void)std::initializer_list<bool>{ (simd::insert<N::value>(p, v),true)... };
  }

  //------------------------------------------------------------------------------------------------
  // Arithmetic common splat
  template<typename T, std::size_t N, typename X, typename Value>
  BOOST_FORCEINLINE pack<T,N,X>
  splat_impl(as_<pack<T,N,X>> const&,aggregate_storage const&, Value const& v) BOOST_NOEXCEPT
  {
    typename pack<T,N,X>::storage_type::value_type s(v);
    return simd::combine(s,s);
  }

  template<typename T, std::size_t N, typename X, typename K, typename Value>
  BOOST_FORCEINLINE pack<T,N,X>
  splat_impl(as_<pack<T,N,X>> const&,K const&, Value const& v) BOOST_NOEXCEPT
  {
    pack<T,N,X> that;
    splat_unroll(that, nsm::range<int, 0, N>{}, v);
    return that;
  }

  template<typename T, std::size_t N, typename X, typename Value>
  BOOST_FORCEINLINE pack<T,N,X> splat_( BOOST_SIMD_SUPPORTS(simd_)
                                      , as_<pack<T,N,X>> const& t, Value const& v
                                      ) BOOST_NOEXCEPT
  {
    return splat_impl(t, typename pack<T,N,X>::storage_kind{}, v);
  }

  //------------------------------------------------------------------------------------------------
  // Logical common splat
  template<typename T, std::size_t N, typename X, typename Value>
  BOOST_FORCEINLINE pack<logical<T>,N,X> splat_impl ( as_<pack<logical<T>,N,X>> const&
                                                    , aggregate_storage const&, Value const& v
                                                    ) BOOST_NOEXCEPT
  {
    typename pack<logical<T>,N,X>::storage_type::value_type s(!!v);
    return simd::combine(s,s);
  }

  template<typename K, typename T, std::size_t N, typename X, typename Value>
  BOOST_FORCEINLINE pack<logical<T>,N,X>
  splat_impl( as_<pack<logical<T>,N,X>> const&, K const&, Value const& v) BOOST_NOEXCEPT
  {
    pack<T,N,X> that;
    splat_unroll(that, nsm::range<int, 0, N>{}, detail::genmask(v, as_<T>()) );
    return simd::bitwise_cast<pack<logical<T>,N,X>>( that );
  }

  template<typename T, std::size_t N, typename X, typename Value>
  BOOST_FORCEINLINE pack<logical<T>,N,X> splat_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                , as_<pack<logical<T>,N,X>> const& t, Value const& v
                                                ) BOOST_NOEXCEPT
  {
    return splat_impl(t, typename pack<T,N,X>::storage_kind{}, v);
  }
} } }

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

#endif
