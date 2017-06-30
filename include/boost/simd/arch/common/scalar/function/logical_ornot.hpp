//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOGICAL_ORNOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOGICAL_ORNOT_HPP_INCLUDED

#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/function/logical_not.hpp>
#include <boost/config.hpp>
// this is also the simd common version

namespace boost { namespace simd { namespace detail
{
  template< typename T1, typename T2, typename Arch >
  BOOST_FORCEINLINE as_logical_t<T1>
  logical_ornot_ ( BOOST_SIMD_SUPPORTS(Arch)
               , T1 const& a0
               , T2 const& a1
                 ) BOOST_NOEXCEPT
  {
    return logical_or(a0, logical_not(a1));
  }

} } }


#endif
