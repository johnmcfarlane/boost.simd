//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITINTEGER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITINTEGER_HPP_INCLUDED

#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>
#include <type_traits>


namespace boost { namespace simd { namespace detail
{

  template<typename T> using btg_t =  boost::dispatch::as_integer_t<T>;

  template<typename T
           , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE
  btg_t<T> bitinteger_( BOOST_SIMD_SUPPORTS(cpu_)
                      , T a
                      ) BOOST_NOEXCEPT
  {
    using result_t = btg_t<T>;
    return is_positive(a) ?
      bitwise_cast<result_t>(a) :
      Signmask<result_t>()-bitwise_cast<result_t>(a);
  }

} } }


#endif
