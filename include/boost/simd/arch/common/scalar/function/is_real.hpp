//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_REAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_REAL_HPP_INCLUDED

#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/config.hpp>
#include <type_traits>
// this is also the common simd implementation

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE bool
   is_real_ ( BOOST_SIMD_SUPPORTS(cpu_)
                , bool
                ) BOOST_NOEXCEPT
   {
     return true;
   }

  template <typename T, typename Arch,
            typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE  as_logical_t<T>
  is_real_( BOOST_SIMD_SUPPORTS(Arch)
              , T
              ) BOOST_NOEXCEPT
  {
    return True<T>();
  }

  template <typename T, typename Arch>
  BOOST_FORCEINLINE  as_logical_t<T>
  is_real_( BOOST_SIMD_SUPPORTS(cpu_)
              , as_logical_t<T> const &
              ) BOOST_NOEXCEPT
  {
    return True<T>();
  }

} } }


#endif

