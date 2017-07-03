//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_IF_NAN_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_IF_NAN_ELSE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/function/definition/if_allbits_else.hpp>

namespace boost { namespace simd
{
  auto  if_nan_else = if_allbits_else;
} }

#endif
