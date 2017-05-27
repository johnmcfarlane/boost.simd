//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/insert.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/as.hpp>
#include <initializer_list>

namespace boost { namespace simd { namespace detail
{
  template<typename Pack, typename... N, typename... Values>
  BOOST_FORCEINLINE void make_impl(Pack& p, nsm::list<N...> const&, Values const&... values)
  {
    (void)std::initializer_list<bool>{ (simd::insert<N::value>(p, values),true)... };
  }

  //------------------------------------------------------------------------------------------------
  // Arithmetic common make
  template< typename T, std::size_t N, typename X
          , typename... Values
          >
  BOOST_FORCEINLINE pack<T,N,X> make_ ( BOOST_SIMD_SUPPORTS(simd_)
                                      , as_<pack<T,N,X>> const&, Values const&... values
                                      ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == N
                  , "simd::make - Invalid number of arguments"
                  );

    pack<T,N,X> that;
    make_impl(that, nsm::range<int, 0, N>{}, values...);
    return that;
  }

  //------------------------------------------------------------------------------------------------
  // Logical common make
  template< typename T, std::size_t N, typename X
          , typename... Values
          >
  BOOST_FORCEINLINE pack<logical<T>,N,X> make_( BOOST_SIMD_SUPPORTS(simd_)
                                              , as_<pack<logical<T>,N,X>> const&
                                              , Values const&... values
                                              ) BOOST_NOEXCEPT
  {
    static_assert ( sizeof...(Values) == N
                  , "simd::make - Invalid number of arguments"
                  );

  pack<T,N,X> that;
  make_impl(that, nsm::range<int, 0, N>{}, simd::genmask<T>(values)...);
  return simd::bitwise_cast<pack<logical<T>,N,X>>(that);
  }
} } }

#endif
