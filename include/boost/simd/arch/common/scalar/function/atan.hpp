//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ATAN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ATAN_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/arch/common/detail/scalar/f_invtrig.hpp>
#include <boost/simd/arch/common/detail/scalar/d_invtrig.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T atan_(BOOST_SIMD_SUPPORTS(cpu_)
         , T const& a) BOOST_NOEXCEPT
  {
    return detail::invtrig_base<T,tag::radian_tag,tag::not_simd_type>::atan(a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T atan_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const&
         , T const& a) BOOST_NOEXCEPT
  {
    return std::atan(a);
  }

} } }


#endif
