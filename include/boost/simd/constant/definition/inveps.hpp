//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_INVEPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_INVEPS_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(inveps_, inveps);

  template<typename T>
  BOOST_FORCEINLINE T Inveps(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return inveps( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Inveps() BOOST_NOEXCEPT
  {
    return inveps( boost::simd::as_<T>{} );
  }
} }

#endif
