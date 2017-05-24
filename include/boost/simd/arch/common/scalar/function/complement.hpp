//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COMPLEMENT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COMPLEMENT_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <type_traits>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE T scomplement_(T a, tt_::true_type ) BOOST_NOEXCEPT
  {
    using b_t = bd::as_integer_t<T, unsigned>;
    return bitwise_cast<T>(~bitwise_cast<b_t>(a));
  }

  template<typename T>
  BOOST_FORCEINLINE T scomplement_(T a, tt_::false_type ) BOOST_NOEXCEPT
  {
    return ~a;
  }

  template<typename T>
  BOOST_FORCEINLINE T complement_( BOOST_SIMD_SUPPORTS(cpu_), T const& a) BOOST_NOEXCEPT
  {
    return scomplement_(a, tt_::is_floating_point<T>{});
  }

} } }

#endif
