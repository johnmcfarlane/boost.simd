//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_INRAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_INRAD_HPP_INCLUDED

#include <boost/simd/constant/deginrad.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T,
           typename =  typename std::enable_if<is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE T inrad_(BOOST_SIMD_SUPPORTS(cpu_)
                            , T a) BOOST_NOEXCEPT
  {
     return a*Deginrad<T>();
  }

} } }


#endif
