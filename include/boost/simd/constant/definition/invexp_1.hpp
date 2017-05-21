//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_INVEXP_1_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_INVEXP_1_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(invexp_1_, invexp_1);

  template<typename T>
  BOOST_FORCEINLINE auto Invexp_1(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    invexp_1( tgt )
  )

  template<typename T> BOOST_FORCEINLINE auto Invexp_1() BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    invexp_1( boost::simd::as_<T>{} )
  )
} }

#endif
