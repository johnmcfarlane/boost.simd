//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_PLUS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_PLUS_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/meta/is_pack.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF( plus_
                            , (typename A0,typename A1)
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

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      return {a0.real+a1.real,a0.imag+a1.imag};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( plus_
                          , (typename A0,typename A1)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          , bd::generic_< bd::arithmetic_<A1> >
                          )
  {
    using value_t   = typename A0::value_type;
    using base_t    = typename nsm::if_c<is_pack_t<A1>::value, A1, value_t>::type;
    using result_t  = cmplx::complex<base_t>;

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      return {a0.real+a1,a0.imag};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( plus_
                          , (typename A0,typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          , bs::cmplx::complex_<A1>
                          )
  {
    using value_t   = typename A1::value_type;
    using base_t    = typename nsm::if_c<is_pack_t<A0>::value, A0, value_t>::type;
    using result_t  = cmplx::complex<base_t>;

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      return {a0+a1.real,a1.imag};
    }
  };
} } }

#endif
