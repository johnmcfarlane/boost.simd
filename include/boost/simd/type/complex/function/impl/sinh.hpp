//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_SINH_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_SINH_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/type/complex/function/if_else.hpp>
#include <boost/simd/type/complex/function/is_real.hpp>
#include <boost/simd/type/complex/function/is_imag.hpp>
#include <boost/simd/type/complex/function/is_invalid.hpp>
#include <boost/simd/function/sincos.hpp>
#include <boost/simd/function/sinhcosh.hpp>
#include <boost/simd/function/sinh.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/none.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( sinh_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      using rtype = typename A0::value_type;
      rtype c, s, ch, sh;
      std::tie(s, c) = sincos(a0.imag);
      std::tie(sh, ch) = sinhcosh(a0.real);

      return {c*sh, s*ch};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( sinh_
                          , (typename A0)
                          , bd::cpu_
                          , bs::pedantic_tag
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(pedantic_tag const&
                                   , A0 const& a0) const BOOST_NOEXCEPT
    {
      using rtype = typename A0::value_type;
      rtype c, s, ch, sh;
      std::tie(s, c) = sincos(a0.imag);
      std::tie(sh, ch) = sinhcosh(a0.real);
      rtype r = c*sh;
      rtype i = s*ch;
      if (none(is_invalid(a0))) return {r, i};
      r = if_else(logical_and(is_inf(a0.real), is_invalid(a0.imag)), a0.real, r);
      i = if_else(logical_and(is_inf(a0.real), is_nan(a0.imag)), bs::Nan<rtype>(), i);
      r = if_else(is_nan(a0.real), a0.real, r);
      i = if_else(is_nan(a0.real), a0.real, i);
      i = if_zero_else(is_real(a0), i);
      r = if_zero_else(is_imag(a0), r);
      return { r, i};
    }
  };
} } }

#endif
