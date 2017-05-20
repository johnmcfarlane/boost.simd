//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_THOUSAND_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_THOUSAND_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(thousand_, thousand);

  template<typename T>
  BOOST_FORCEINLINE T Thousand(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return thousand( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Thousand() BOOST_NOEXCEPT
  {
    return thousand( boost::simd::as_<T>{} );
  }
} }

#endif
