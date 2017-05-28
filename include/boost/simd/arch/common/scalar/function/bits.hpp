//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITS_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/bitinteger.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T> using bit_t =  boost::dispatch::as_integer_t<T, unsigned>;

  template<typename T >
  BOOST_FORCEINLINE
  bit_t<T> bits_( BOOST_SIMD_SUPPORTS(cpu_)
                , T a
                ) BOOST_NOEXCEPT
  {
    using result_t = bit_t<T>;
    return  bitwise_cast<result_t>(a);
  }

} } }


#endif
