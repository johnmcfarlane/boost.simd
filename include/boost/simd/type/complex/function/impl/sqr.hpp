//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_SQR_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_SQR_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( sqr_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      using rtype =  typename A0::value_type;
      rtype x = sqr(a0.real) - sqr(a0.imag);
      rtype y = Two<rtype>()*a0.real*a0.imag;
      return {x, y};
    }
  };


  BOOST_DISPATCH_OVERLOAD ( sqr_
                          , (typename A0)
                          , bd::cpu_
                          , bs::pedantic_tag
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      using rtype =  typename A0::value_type;
      rtype x = sqr(a0.real) - sqr(a0.imag);
      rtype y = Two<rtype>()*a0.real*a0.imag;
      A0 r = A0(x, y);
      if (bs::any(logical_or(is_invalid(x), is_invalid(y))))
      {
        auto test = is_real(a0);
        r = if_else(test, A0(sqr(a0.real)), r);
        test = logical_andnot(is_imag(a0), test);
        r = if_else(test, A0(-sqr(a0.imag)), r);
      }
      return r;
    }
  };

} } }

#endif
