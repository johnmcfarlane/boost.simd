//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_PROJ_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_PROJ_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, proj_, boost::dispatch::elementwise_<proj_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, proj_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::proj_, proj);
} }

#include <boost/simd/type/complex/function/impl/proj.hpp>

#endif
