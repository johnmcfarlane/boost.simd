//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_FALSE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_FALSE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(false_, false_);

  template<typename T> BOOST_FORCEINLINE
  as_logical_t<T> False(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return false_( as_<as_logical_t<T>>{} );
  }

  template<typename T> BOOST_FORCEINLINE as_logical_t<T> False() BOOST_NOEXCEPT
  {
    return false_( as_<as_logical_t<T>>{} );
  }
} }

#endif
