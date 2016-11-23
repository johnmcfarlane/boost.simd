//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_PACK_SUPPORT_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_PACK_SUPPORT_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/arch/common/simd/abi_of.hpp>

#define BOOST_SIMD_ENABLE_PACK_SUPPORT(Type, Size, Register, Ext)                                   \
namespace detail                                                                                    \
{                                                                                                   \
  BOOST_SIMD_DEFINE_PACK_TRAITS(Type, Size, Register);                                              \
}                                                                                                   \
namespace ext                                                                                       \
{                                                                                                   \
  template<typename Enable> struct abi_of<Type, Size,Enable> { using type = Ext; };                 \
}                                                                                                   \
/**/

#endif
