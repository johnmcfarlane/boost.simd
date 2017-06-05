//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPM1_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPM1_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/detail/pack.hpp>
#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/function/is_nan.hpp>
#endif
#include <boost/simd/arch/common/detail/generic/expm1_kernel.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/logeps.hpp>
#include <boost/simd/detail/constant/maxlog.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/meta/is_pack.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T expm1_(BOOST_SIMD_SUPPORTS(cpu_)
        , T a0) BOOST_NOEXCEPT
  {
#ifndef BOOST_SIMD_NO_INVALIDS
    if(is_nan(a0)) return Nan<T>();
#endif
    if((a0 < Logeps<T>())) return Mone<T>();
    if((a0 > Maxlog<T>())) return  Inf<T>();
    return detail::expm1_kernel<T, T>::expm1(a0);
  }

  //================================================================================================
  // std_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T expm1_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const&
         , T a) BOOST_NOEXCEPT
  {
    return std::expm1(a);
  }

} } }


#endif
