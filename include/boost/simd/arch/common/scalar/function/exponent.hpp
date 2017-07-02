//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPONENT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPONENT_HPP_INCLUDED

#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  as_si_t<T> sexponent_( T a0
           , std::true_type const &) BOOST_NOEXCEPT
  {
    using r_t = as_si_t<T>;
    if (is_invalid(a0) || is_eqz(a0)) return r_t(0);
    const int nmb = int(Nbmantissabits<T>());
    auto exponentbits = bitwise_and((2*Maxexponent<T>()+1)<<Nbmantissabits<T>(), a0);
    const r_t x = shr(exponentbits, nmb);
    return x-if_else_zero(a0, Maxexponent<T>());
  }

  template<typename T >
  BOOST_FORCEINLINE
  as_si_t<T> sexponent_( T
                    , std::false_type) BOOST_NOEXCEPT
  {
    return Zero<as_si_t<T>>();
  }

  template<typename T>
  BOOST_FORCEINLINE
  as_si_t<T> exponent_(BOOST_SIMD_SUPPORTS(cpu_)
                   , T a) BOOST_NOEXCEPT
  {
    return sexponent_(a, std::is_floating_point<T>());
  }

 //================================================================================================
  // std_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  as_si_t<T> exponent_(BOOST_SIMD_SUPPORTS(cpu_)
                   , std_tag const&
                   , T a) BOOST_NOEXCEPT
  {
    return  std::ilogb(a);
  }

} } }

#endif
