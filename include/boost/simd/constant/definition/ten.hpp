//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_TEN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_TEN_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct ten_ : boost::dispatch::constant_value_<ten_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,ten_,boost::dispatch::constant_value_<ten_>);
      BOOST_SIMD_REGISTER_CONSTANT(10, 0x41200000UL, 0x4024000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,ten_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::ten_,ten);
  }

  template<typename T> BOOST_FORCEINLINE auto Ten() BOOST_NOEXCEPT
  -> decltype(functional::ten( boost::dispatch::as_<T>{}))
  {
    return functional::ten( boost::dispatch::as_<T>{} );
  }
} }

#endif
