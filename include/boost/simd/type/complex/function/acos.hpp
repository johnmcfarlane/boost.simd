//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ACOS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ACOS_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, cmplx_acos_, boost::dispatch::elementwise_<cmplx_acos_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cmplx_acos_)
  }

  namespace cmplx
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cmplx_acos_,acos);
  }
} }

#include <boost/simd/function/acos.hpp>
#include <boost/simd/type/complex/function/impl/acos.hpp>

#endif
