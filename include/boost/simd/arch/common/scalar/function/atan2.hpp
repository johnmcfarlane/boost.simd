//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ATAN2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ATAN2_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/arch/common/detail/scalar/f_invtrig.hpp>
#include <boost/simd/arch/common/detail/scalar/d_invtrig.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/function/copysign.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/signnz.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/meta/is_pack.hpp>

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // Pedantic case
  template<typename T>
  BOOST_FORCEINLINE T
  atan2_(BOOST_SIMD_SUPPORTS(cpu_)
        ,  pedantic_tag const &
        , T a0
        , T a1) BOOST_NOEXCEPT
  {
#ifndef BOOST_SIMD_NO_NANS
    if (is_nan(a0) || is_nan(a1)) return Nan<T>();
#endif

#ifndef BOOST_SIMD_NO_INFINITIES
    if (is_inf(a0) && is_inf(a1))
    {
      a0 = copysign(One<T>(), a0);
      a1 = copysign(One<T>(), a1);
    }
#endif
    T q = bs::abs(a0/a1);
    T z = detail::invtrig_base<T,tag::radian_tag, is_pack_t<T>>::kernel_atan(q, rec(q));
    T sgn = signnz(a0);
    z = (is_positive(a1)? z: Pi<T>()-z)*sgn;
    return is_eqz(a0) ? if_else_zero(is_negative(a1), Pi<T>()*sgn) : z;
  }

  // -----------------------------------------------------------------------------------------------
  // std case
  template<typename T>
  BOOST_FORCEINLINE T
  atan2_(BOOST_SIMD_SUPPORTS(cpu_)
        ,  std_tag const &
        , T a0
        , T a1) BOOST_NOEXCEPT
  {
    return std::atan2(a0, a1);
  }

  // -----------------------------------------------------------------------------------------------
  // Regular case
  template<typename T>
  BOOST_FORCEINLINE T
  atan2_(BOOST_SIMD_SUPPORTS(cpu_)
        , T a0
        , T a1) BOOST_NOEXCEPT
  {
    T q = bs::abs(a0/a1);
    T z = detail::invtrig_base<T,tag::radian_tag, is_pack_t<T>>::kernel_atan(q, bs::rec(q));
    return (is_positive(a1)? z: Pi<T>()-z)*signnz(a0);
  }

} } }


#endif
