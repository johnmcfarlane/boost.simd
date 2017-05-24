//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_CONSTANT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_CONSTANT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/as.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(constant_, constant);

  template<typename Type, detail::bits_t<dispatch::scalar_of_t<Type>> Bits>
  BOOST_FORCEINLINE Type Constant()
  {
    using cst_t = typename detail::constantify<boost::dispatch::scalar_of_t<Type>,Bits>::type;
    return constant( cst_t{}, boost::simd::as_<Type>{} );
  }
} }

#endif
