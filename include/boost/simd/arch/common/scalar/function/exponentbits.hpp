//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPONENTBITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPONENTBITS_HPP_INCLUDED

#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T
           , typename =  std::enable_if<std::is_floating_point<T>>
           >
  BOOST_FORCEINLINE
  si_t<T> sexponent_(BOOST_SIMD_SUPPORTS(cpu_)
                    ,  T a0) BOOST_NOEXCEPT
  {
    return bitwise_and((2*simd::Maxexponent<T>()+1)<<Nbmantissabits<T>(), a0);
  }

} } }


#endif
