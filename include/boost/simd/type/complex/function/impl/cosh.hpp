//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_COSH_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_COSH_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/type/complex/function/if_else.hpp>
#include <boost/simd/type/complex/function/is_real.hpp>
#include <boost/simd/type/complex/function/is_imag.hpp>
#include <boost/simd/type/complex/function/is_invalid.hpp>
#include <boost/simd/function/sincos.hpp>
#include <boost/simd/function/sinhcosh.hpp>
#include <boost/simd/function/cosh.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/none.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/config.hpp>
#include <boost/core/demangle.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( cosh_
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

      rtype r = c*ch;
      rtype i = s*sh;
      i = if_zero_else(logical_or(is_imag(a0), is_real(a0)), i);
      A0 res = A0(r, i);
      if (bs::none(is_invalid(a0))) return res;
      res = if_else(logical_and(is_inf(a0.real), is_invalid(a0.imag)),
                    A0( bs::Inf<rtype>(), bs::Nan<rtype>()), res);
      res = if_else(logical_and(is_nan(a0.real), is_inf(a0.imag)),
                    A0( bs::Nan<rtype>(), bs::Nan<rtype>()), res);
      return res;
    }
  };

} } }

#endif
