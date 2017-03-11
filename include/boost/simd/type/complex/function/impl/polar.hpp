//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_POLAR_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_POLAR_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/sincos.hpp>
#include <boost/simd/meta/is_pack.hpp>
#include <boost/config.hpp>


namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF ( polar_
                             , (typename A0, typename A1)
                             , ( std::is_same< bd::value_of_t<A0>
                                             , bd::value_of_t<A1>
                                 >
                              )
                             , bd::cpu_
                             , bd::generic_<bd::floating_<A0>>
                             , bd::generic_<bd::floating_<A1>>
                             )
  {
    using base_t    = typename std::conditional<is_pack_t<A0>::value,A0,A1>::type;
    using result_t  = cmplx::complex<base_t>;

    BOOST_FORCEINLINE result_t
      operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      A1 s, c;
      std::tie(s, c) = bs::sincos(a1);
      return a0*result_t(c, s);
    }
  };

  BOOST_DISPATCH_OVERLOAD( polar_
                         , (typename A0, typename A1, typename X)
                         , bd::cpu_
                         , bs::pack_<bd::floating_<A0>, X>
                         , bd::scalar_<bd::arithmetic_<A1>>
                         )
  {
    using base_t    = typename A0::value_type;
    using result_t  = cmplx::complex<A0>;

    BOOST_FORCEINLINE result_t
      operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      base_t s, c;
      std::tie(s, c) = bs::sincos(static_cast<base_t>(a1));
      return result_t(a0*c, a0*s);
    }
  };

  BOOST_DISPATCH_OVERLOAD( polar_
                         , (typename A0, typename A1, typename X)
                         , bd::cpu_
                         , bd::scalar_<bd::arithmetic_<A0>>
                         , bs::pack_<bd::floating_<A1>, X>
                         )
  {
    using result_t  = cmplx::complex<A1>;

    BOOST_FORCEINLINE result_t
      operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      A1 s, c;
      std::tie(s, c) = bs::sincos(a1);
      return a0*result_t(c, s);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( polar_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
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
