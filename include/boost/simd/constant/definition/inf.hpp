//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_INF_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_INF_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(inf_, inf);

  template<typename T>
  BOOST_FORCEINLINE T Inf(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return inf( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Inf() BOOST_NOEXCEPT
  {
    return inf( boost::simd::as_<T>{} );
  }
} }

#endif
