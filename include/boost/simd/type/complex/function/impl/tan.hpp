//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_TAN_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_TAN_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/type/complex/function/is_real.hpp>
#include <boost/simd/type/complex/function/is_imag.hpp>
#include <boost/simd/function/sincos.hpp>
#include <boost/simd/function/sinhcosh.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/config.hpp>

//tan ( x + iy ) = tan ( x ) + i . tan ( y ) 1 + i . tan ( x ) tan ( y ) .

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( tan_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      using rtype = typename A0::value_type;
      A0 aa0 =  a0+a0;
      rtype c, s, ch, sh;
      std::tie(s, c) = sincos(aa0.real);
      std::tie(sh, ch) = sinhcosh(aa0.imag);
      rtype tmp = c+ch;
      rtype r_part = if_zero_else(is_imag(a0),s/tmp);
      rtype i_part = if_zero_else(is_real(a0),sh/tmp);
      return {r_part, i_part};
    }
  };

} } }

#endif
