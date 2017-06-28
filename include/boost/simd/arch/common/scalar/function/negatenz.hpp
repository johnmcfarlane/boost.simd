//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEGATENZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEGATENZ_HPP_INCLUDED

#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/signnz.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // regular cases
  template<typename T>
  BOOST_FORCEINLINE T s_negatenz_( T a0
                                 , T a1
                                 , detail::case_<0> const&) BOOST_NOEXCEPT
  {
    return bitwise_xor(bitofsign(a1), a0);
  }

  template<typename T>
  BOOST_FORCEINLINE T s_negatenz_( T a0
                                 , T a1
                                 , detail::case_<1> const&) BOOST_NOEXCEPT
  {
    return a0*signnz(a1);
  }

  template<typename T>
  BOOST_FORCEINLINE T s_negatenz_( T a0
                                 , T
                                 , detail::case_<2> const&) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T>
  BOOST_FORCEINLINE T negatenz_(BOOST_SIMD_SUPPORTS(cpu_)
                               , T a0
                               , T a1
                               ) BOOST_NOEXCEPT
  {
    return s_negatenz_(a0, a1, fsu_picker<T>{});
  }

} } }


#endif
