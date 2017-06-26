//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MASK2LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MASK2LOGICAL_HPP_INCLUDED

#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
 BOOST_FORCEINLINE bool
   mask2logical_ ( BOOST_SIMD_SUPPORTS(cpu_)
                , bool a0
                ) BOOST_NOEXCEPT
   {
     return a0;
   }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_mask2logical_( T a0
                , std::true_type const &
                ) BOOST_NOEXCEPT
  {
    return  a0;
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_mask2logical_( T a0
                , std::false_type const &
                ) BOOST_NOEXCEPT
  {
    return is_nez(a0);
  }

  template <typename T
            , typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE logical<T>
  mask2logical_( BOOST_SIMD_SUPPORTS(cpu_)
            , T a0
            ) BOOST_NOEXCEPT
  {
    return s_mask2logical_(a0, std::is_floating_point<T>());
  }

} } }


#endif
