//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_EXP_1_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_EXP_1_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(exp_1_, exp_1);

  template<typename T>
  BOOST_FORCEINLINE T Exp_1(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return exp_1( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Exp_1() BOOST_NOEXCEPT
  {
    return exp_1( boost::simd::as_<T>{} );
  }
} }

#endif
