//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITFLOATING_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITFLOATING_HPP_INCLUDED

#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{


  template<typename T
           , typename = typename std::enable_if<std::is_integral<T>::value>::type
           , typename = typename std::enable_if<sizeof(T) >= 4>
  >
  BOOST_FORCEINLINE
  f_t<T> sbitfloating_(T const& a
                        , std::true_type const &
                        ) BOOST_NOEXCEPT
  {
    using result_t = bd::as_floating_t<T>;
    return a >= Zero<T>() ?
      bitwise_cast<result_t>(a) :
      bitwise_cast<result_t>(Signmask<T>()-a);
  }

  template<typename T
           , typename = typename std::enable_if<sizeof(T) >= 4>
>
  BOOST_FORCEINLINE
  f_t<T> sbitfloating_( T a
                        , std::false_type const &
                        ) BOOST_NOEXCEPT
  {
    using result_t = bd::as_floating_t<T>;
    return simd::bitwise_cast<result_t>(a);
  }

  template<typename T>
  BOOST_FORCEINLINE
  f_t<T> bitfloating_( BOOST_SIMD_SUPPORTS(cpu_)
                        , T a
                        ) BOOST_NOEXCEPT
  {
    return sbitfloating_(a, std::is_signed<T>());
  }

} } }


#endif
