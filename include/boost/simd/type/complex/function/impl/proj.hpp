//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_PROJ_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_PROJ_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/type/complex/function/if_else.hpp>
#include <boost/simd/type/complex/function/is_inf.hpp>
#include <boost/simd/function/copysign.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/config.hpp>


template<typename T> inline std::string type_id( const T& )
{
  return type_id<T>();
}

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( proj_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      using value_t =  typename A0::value_type;
      return if_else(is_inf(a0), A0(Inf<value_t>(), copysign(Zero<value_t>(), a0.imag)), a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( proj_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          )
  {
    using result_t = cmplx::complex<A0>;
    BOOST_FORCEINLINE result_t operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      return { a0, Zero<A0>()};
    }
  };
} } }

#endif
