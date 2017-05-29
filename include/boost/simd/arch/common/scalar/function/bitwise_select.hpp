//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_SELECT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_SELECT_HPP_INCLUDED

#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_andnot.hpp>
#include <boost/simd/function/bitwise_or.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename U>
  BOOST_FORCEINLINE U bitwise_select_(BOOST_SIMD_SUPPORTS(cpu_)
                                     , T a0
                                     , U a1
                                     , U a2) BOOST_NOEXCEPT
  {
    static_assert ( sizeof(T) == sizeof(U)
                  , "simd::bitwise_select - Arguments have incompatible size"
                  );

    return  bitwise_or(bitwise_and(a1, a0), bitwise_andnot(a2,a0));
  }

} } }


#endif
