//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_NOPE_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_NOPE_HPP_INCLUDED

#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename N> BOOST_FORCEINLINE T nope() { return 0; }
} } }

#endif
