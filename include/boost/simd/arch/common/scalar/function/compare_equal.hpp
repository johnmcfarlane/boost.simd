//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COMPARE_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COMPARE_EQUAL_HPP_INCLUDED

#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template< typename T>
  BOOST_FORCEINLINE bool compare_equal_ ( BOOST_SIMD_SUPPORTS(cpu_)
                                        , T const& a0
                                        , T const& a1
                                        ) BOOST_NOEXCEPT
  {
    return  a0 == a1;
  }

} } }


#endif
