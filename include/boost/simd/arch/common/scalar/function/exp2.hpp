//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXP2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXP2_HPP_INCLUDED

#include <boost/simd/function/std.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/arch/common/detail/scalar/exponential.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T exp2_(BOOST_SIMD_SUPPORTS(cpu_)
        , T a) BOOST_NOEXCEPT
  {
    return detail::exponential<T,bs::tag::exp2_,is_pack_t<T>>::expa(a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T exp2_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const&
         , T a) BOOST_NOEXCEPT
  {
    return std::exp2(a);
  }

} } }

#endif
