//==================================================================================================
/**
  Copyright 201 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_INSERT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_INSERT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(insert_,insert_);

  template<typename P, typename I, typename V>
  BOOST_FORCEINLINE void insert(P& a, I const & i, V const & v) BOOST_NOEXCEPT
  {
    insert_(a, i, v);
  }

  template<size_t N, typename P, typename V>
  BOOST_FORCEINLINE void insert(P & a,  V const & v) BOOST_NOEXCEPT
  {
    insert_(a, nsm::size_t<N>(), v);
  }
} }

#endif
