//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ROUND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ROUND_HPP_INCLUDED

#include <boost/simd/constant/half.hpp>
#include <boost/simd/detail/constant/maxflint.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/ceil.hpp>
#include <boost/simd/function/copysign.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/tenpower.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  namespace bs = boost::simd;
  //================================================================================================
  // one parameter round

  template < typename T >
  BOOST_FORCEINLINE
  T sround_(T a0, std::true_type) BOOST_NOEXCEPT
  {
    T v = bs::abs(a0);
    if (!(v <= Maxflint<T>())) return a0;
    T c =  bs::ceil(v);
    return bs::copysign(if_dec(c-Half<T>() > v, c), a0);
  }

  template < typename T >
  BOOST_FORCEINLINE
  T sround_(T a, std::false_type) BOOST_NOEXCEPT
  {
    return a;
  }

  template < typename T >
  BOOST_FORCEINLINE
  T round_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a) BOOST_NOEXCEPT
  {
    return sround_(a, std::is_floating_point<T>());
  }

  //std_ decorator
  template<typename T >
  BOOST_FORCEINLINE
  auto round_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const &
         , T a) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    std::round(a)
  )

  //================================================================================================
  // two parameters round

  template < typename T, typename iT>
  BOOST_FORCEINLINE
  T sround_(T a0, iT a1, std::true_type) BOOST_NOEXCEPT
  {
    using i_t = bd::as_integer_t<T>;
    T fac = tenpower(i_t(a1));
    T x = a0*fac;
    T z = bs::round(x)/fac;
    return is_ltz(a1) ? std::round(z) : z;
  }

  template < typename T, typename iT >
  BOOST_FORCEINLINE
  T sround_(T a0, iT a1, std::false_type) BOOST_NOEXCEPT
  {
    using i_t = bd::as_integer_t<T>;
    T fac = tenpower(i_t(a1));
    T x = a0*fac;
    return  bs::round(x)/fac;
  }

  template < typename T, typename iT
             , typename = typename std::enable_if<std::is_integral<iT>::value>::type
             >
  BOOST_FORCEINLINE
  T round_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0, iT a1) BOOST_NOEXCEPT
  {
    return sround_(a0, a1, std::is_signed<iT>());
  }

} } }

#endif
