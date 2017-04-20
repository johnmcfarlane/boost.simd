//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_ONE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_ONE_HPP_INCLUDED

#include <boost/simd/as.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename Type, typename Arch>
  BOOST_FORCEINLINE Type one_( BOOST_SIMD_SUPPORTS(Arch), as_<Type> const&) BOOST_NOEXCEPT
  {
    return Type(1);
  }
} } }

#endif
