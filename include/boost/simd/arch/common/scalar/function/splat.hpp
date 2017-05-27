//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SPLAT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/as.hpp>

#ifdef BOOST_MSVC
# pragma warning(push)
# pragma warning(disable: 4244) // conversion loss of data
#endif

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename V>
  BOOST_FORCEINLINE T splat_(BOOST_SIMD_SUPPORTS(cpu_), as_<T> const&, V const& value) BOOST_NOEXCEPT
  {
    return static_cast<T>(value);
  }
} } }

#ifdef BOOST_MSVC
# pragma warning(pop)
#endif

#endif
