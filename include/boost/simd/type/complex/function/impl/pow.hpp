//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_POW_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_POW_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/type/complex/function/abs.hpp>
#include <boost/simd/type/complex/function/arg.hpp>
#include <boost/simd/type/complex/function/exp.hpp>
#include <boost/simd/type/complex/function/exp_i.hpp>
#include <boost/simd/type/complex/function/exp_ipi.hpp>
#include <boost/simd/type/complex/function/if_else.hpp>
#include <boost/simd/type/complex/function/log.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF ( pow_
                             , (typename A0, typename A1)
                             , ( std::is_same< bd::value_of_t<typename A0::value_type>
                               , bd::value_of_t<typename A1::value_type>
                                 >
                             )
                             , bd::cpu_
                             , bs::cmplx::complex_<A0>
                             , bs::cmplx::complex_<A1>
                          )
  {
    using value0_t  = typename A0::value_type;
    using value1_t  = typename A1::value_type;
    using base_t    = typename std::conditional<is_pack_t<value0_t>::value,value0_t,value1_t>::type;
    using result_t  = cmplx::complex<base_t>;

    BOOST_FORCEINLINE A0 operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      return bs::exp(a1*bs::cmplx::log(a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( cmplx_pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          , bs::cmplx::complex_<A1>
                          )
  {
    BOOST_FORCEINLINE auto operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT_DECLTYPE_BODY
      (
        bs::pow(a0, a1)
      )
   };


  BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          , bd::generic_< bd::floating_<A1> >
                          )
  {
    using value_t   = typename A0::value_type;
    using base_t    = typename nsm::if_c<is_pack_t<A1>::value, A1, value_t>::type;
    using result_t  = cmplx::complex<base_t>;
    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      base_t t = bs::arg(a0);
      base_t a = bs::abs(a0);
      return bs::pow(a, a1)*bs::exp_i(t*a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( cmplx_pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          , bd::generic_< bd::floating_<A1> >
                          )
   {
     BOOST_FORCEINLINE auto operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT_DECLTYPE_BODY
       (
         bs::pow(a0, a1)
       )
   };

  BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bs::cmplx::complex_<A1>
                          )
  {
    using value_t   = typename A1::value_type;
    using base_t    = typename nsm::if_c<is_pack_t<A0>::value, A0, value_t>::type;
    using result_t  = cmplx::complex<base_t>;
    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      return bs::exp(a1*bs::cmplx::log(a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( cmplx_pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bs::cmplx::complex_<A1>
                          )
  {
    BOOST_FORCEINLINE auto operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT_DECLTYPE_BODY
      (
        bs::pow(a0, a1)
      )
  };

  BOOST_DISPATCH_OVERLOAD ( cmplx_pow_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A1> >
                          )
  {
    using base_t    = typename nsm::if_c<is_pack_t<A0>::value, A0, A1>::type;
    using result_t  = cmplx::complex<base_t>;
    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      result_t z = if_else(is_positive(a0), result_t(One<base_t>()), bs::exp_ipi(a1));
      return bs::exp(a1*bs::log(bs::abs(a0)))*z;

    }
  };

} } }

#endif
