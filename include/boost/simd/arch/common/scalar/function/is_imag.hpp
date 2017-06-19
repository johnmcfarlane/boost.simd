//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_IMAG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_IMAG_HPP_INCLUDED

#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE bool
   is_imag_ ( BOOST_SIMD_SUPPORTS(cpu_)
                , bool a0
                ) BOOST_NOEXCEPT
   {
     return !a0;
   }

  template <typename T,
            typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE  as_logical_t<T>
  is_imag_( BOOST_SIMD_SUPPORTS(cpu_)
              , T a0
              ) BOOST_NOEXCEPT
  {
    return !a0;
  }

  template <typename T>
  BOOST_FORCEINLINE  as_logical_t<T>
  is_imag_( BOOST_SIMD_SUPPORTS(cpu_)
              , as_logical_t<T> const & a0
              ) BOOST_NOEXCEPT
  {
    return logical_not(a0);
  }

} } }


#endif
