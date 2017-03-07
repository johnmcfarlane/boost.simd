//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_SQRT_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_SQRT_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( cmplx_sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      // TODO
      return a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( cmplx_sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          )
  {
    using result_t = cmplx::complex<A0>;
    BOOST_FORCEINLINE result_t operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      return { if_else_zero(a0>0,bs::sqrt(a0)), if_zero_else(a0>0,bs::sqrt(-a0))};
    }
  };
} } }

#endif
