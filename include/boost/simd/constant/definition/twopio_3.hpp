//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_TWOPIO_3_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_TWOPIO_3_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(twopio_3_, twopio_3);

  template<typename T>
  BOOST_FORCEINLINE T Twopio_3(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return twopio_3( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Twopio_3() BOOST_NOEXCEPT
  {
    return twopio_3( boost::simd::as_<T>{} );
  }
} }

#endif
