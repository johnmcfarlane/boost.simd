//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_LOG10_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_LOG10_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/type/complex/function/abs.hpp>
#include <boost/simd/type/complex/function/arg.hpp>
#include <boost/simd/type/complex/function/is_real.hpp>
#include <boost/simd/constant/log_10.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/log10.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( log10_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      using rtype = typename A0::value_type;
      rtype a = if_zero_else(logical_and(bs::is_real(a0), bs::is_nan(a0.imag))
                            , bs::arg(a0)) ;
      return {bs::log10(bs::abs(a0)), a/Log_10<rtype>()};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( cmplx_log10_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      return bs::log10(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( cmplx_log10_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    using result_t = cmplx::complex<A0>;
    BOOST_FORCEINLINE result_t operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      return { bs::log10(abs(a0)), if_zero_else(is_positive(a0), Pi<A0>()/Log_10<A0>())}; //TODO have a proper constant Pi_Log_10<A0>()
    }
  };
} } }

#endif
