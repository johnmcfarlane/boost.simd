//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CLAMP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CLAMP_HPP_INCLUDED

#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/assert.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE T clamp_(BOOST_SIMD_SUPPORTS(cpu_)
                            , T const& v
                            , T const& lo
                            , T const& hi
                            ) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(lo <= hi, "lo is not less or equal to hi");
    return (v < lo) ? lo : (hi < v) ? hi : v;
  }
  template<typename T>
  BOOST_FORCEINLINE T clamp_(BOOST_SIMD_SUPPORTS(cpu_)
                            , pedantic_tag const &
                            , T const& v
                            , T const& lo
                            , T const& hi
                            ) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(lo <= hi, "lo is not less or equal to hi");
    return (v < lo) ? lo : (hi < v) ? hi : v;
  }

} } }


#endif
