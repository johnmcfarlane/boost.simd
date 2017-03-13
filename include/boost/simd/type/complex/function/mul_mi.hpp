//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_MUL_MI_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_MUL_MI_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, mul_mi_, boost::dispatch::elementwise_<mul_mi_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, mul_mi_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mul_mi_, mul_mi);
} }

#include <boost/simd/type/complex/function/impl/mul_mi.hpp>

#endif
