//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_ONE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_ONE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(one_, one);

  template<typename T>
  BOOST_FORCEINLINE T One(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return one( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T One() BOOST_NOEXCEPT
  {
    return one( boost::simd::as_<T>{} );
  }
} }

#endif
