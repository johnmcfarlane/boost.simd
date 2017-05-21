//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_SQRTVALMAX_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_SQRTVALMAX_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(sqrtvalmax_, sqrtvalmax);

  template<typename T>
  BOOST_FORCEINLINE T Sqrtvalmax(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return sqrtvalmax( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Sqrtvalmax() BOOST_NOEXCEPT
  {
    return sqrtvalmax( boost::simd::as_<T>{} );
  }
} }

#endif

