//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================

#ifndef BOOST_SIMD_FUNCTION_SIMD_FRAC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_FRAC_HPP_INCLUDED

#include <boost/simd/function/scalar/frac.hpp>
#include <boost/simd/arch/common/simd/function/frac.hpp>

#if defined(BOOST_HW_SIMD_X86_OR_AMD_AVAILABLE)
#  if BOOST_HW_SIMD_X86_AMD_XOP
#    include <boost/simd/arch/x86/xop/simd/function/frac.hpp>
#  endif
#endif

#endif
