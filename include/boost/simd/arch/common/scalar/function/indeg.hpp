//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_INDEG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_INDEG_HPP_INCLUDED

#include <boost/simd/constant/radindeg.hpp>
#include <boost/simd/detail/constant/radindegr.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T,
           typename =  typename std::enable_if<is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE T indeg_(BOOST_SIMD_SUPPORTS(cpu_)
                            , T a) BOOST_NOEXCEPT
  {
    return fms(a, Radindeg<T>(), a*Radindegr<T>());
  }

} } }

#endif
