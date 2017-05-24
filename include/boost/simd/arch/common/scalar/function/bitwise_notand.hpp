//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_NOTAND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_NOTAND_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/complement.hpp>

namespace boost { namespace simd { namespace detail
{

  template<typename T, typename U>
  BOOST_FORCEINLINE T bitwise_notand_(BOOST_SIMD_SUPPORTS(cpu_), T a, U b) BOOST_NOEXCEPT
  {
    static_assert ( sizeof(T) == sizeof(U)
                  , "simd::bitwise_notand - Arguments have incompatible size"
                  );

    return  bitwise_and(complement(a), b);
  }
} } }

#endif
