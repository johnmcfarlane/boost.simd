//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_LOG10_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_LOG10_HPP_INCLUDED
#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, cmplx_log10_, boost::dispatch::elementwise_<cmplx_log10_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cmplx_log10_)
  }

  namespace cmplx
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cmplx_log10_,log10);
  }
} }

#include <boost/simd/function/log10.hpp>
#include <boost/simd/type/complex/function/impl/log10.hpp>

#endif
