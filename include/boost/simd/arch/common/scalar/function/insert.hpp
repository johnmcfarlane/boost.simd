//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_INSERT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_INSERT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename P, typename I, typename V>
  BOOST_FORCEINLINE void insert_( BOOST_SIMD_SUPPORTS(cpu_)
                                , P& dst, I const &, V const & value
                                ) BOOST_NOEXCEPT
  {
    dst = value;
  }
} } }

#endif
