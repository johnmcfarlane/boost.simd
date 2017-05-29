//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_NOTOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_NOTOR_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/complement.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename U>
  BOOST_FORCEINLINE T bitwise_notor_(BOOST_SIMD_SUPPORTS(cpu_)
                                    , T a, U b) BOOST_NOEXCEPT
  {
    static_assert ( sizeof(T) == sizeof(U)
                  , "simd::bitwise_ornot - Arguments have incompatible size"
                  );

    return  bitwise_or(complement(a), b);
  }

  BOOST_FORCEINLINE bool bitwise_notor_(BOOST_SIMD_SUPPORTS(cpu_)
                                       , bool a, bool b) BOOST_NOEXCEPT
  {
    return !a | b;
  }

} } }


#endif
