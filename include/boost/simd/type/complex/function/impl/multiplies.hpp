//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_MULTIPLIES_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_finite.hpp>
#include <boost/simd/type/complex/function/mul_i.hpp>
#include <boost/simd/type/complex/function/is_finite.hpp>
#include <boost/simd/type/complex/function/is_real.hpp>
#include <boost/simd/type/complex/function/is_imag.hpp>
#include <boost/simd/meta/is_pack.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF( multiplies_
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
      auto a = a0.real;
      auto b = a0.imag;
      auto c = a1.real;
      auto d = a1.imag;
      return {fms(a,c,b*d), fma(a,d,b*c)};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( multiplies_
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
      return {a0.real*a1,a0.imag*a1};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( multiplies_
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
      return {a0*a1.real, a0*a1.imag};
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF( multiplies_
                            , (typename A0,typename A1)
                            , ( std::is_same< bd::value_of_t<typename A0::value_type>
                                            , bd::value_of_t<typename A1::value_type>
                                            >
                              )
                            , bd::cpu_
                            , bs::pedantic_tag
                            , bs::cmplx::complex_<A0>
                            , bs::cmplx::complex_<A1>
                            )
  {
    using value0_t  = typename A0::value_type;
    using value1_t  = typename A1::value_type;
    using base_t    = typename std::conditional<is_pack_t<value0_t>::value,value0_t,value1_t>::type;
    using result_t  = cmplx::complex<base_t>;

    BOOST_FORCEINLINE result_t operator()( pedantic_tag const &
                                         , A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      auto a = a0.real;
      auto b = a0.imag;
      auto c = a1.real;
      auto d = a1.imag;
      result_t r = {fms(a,c,b*d), fma(a,d,b*c)};
      auto test = is_finite(r);
      if (bs::all(test)) return r;
      auto cur  = bs::logical_andnot(is_real(a0), test);
      if (bs::any(cur))
      {
        r = if_else(cur, bs::multiplies(a, a1), r);
        test = logical_or(test, cur);
        if (bs::all(test)) return r;
      }
      cur = bs::logical_andnot(is_imag(a0), test);
      if (bs::any(cur))
      {
        r = if_else(cur, bs::mul_i(bs::multiplies(b, a1)), r);
        test = logical_or(test, cur);
        if (bs::all(test)) return r;
      }
      cur = bs::logical_andnot(is_real(a1), test);
      if (bs::any(cur))
      {
        r = if_else(cur, bs::multiplies(c, a0), r);
        test = logical_or(test, cur);
        if (bs::all(test)) return r;
      }
      cur = bs::logical_andnot(is_imag(a1), test);
      if (bs::any(cur))
      {
        r = if_else(cur, bs::mul_i(bs::multiplies(d, a0)), r);
        test = logical_or(test, cur);
        if (bs::all(test)) return r;
      }
      return r;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( multiplies_
                          , (typename A0,typename A1)
                          , bd::cpu_
                          , bs::pedantic_tag
                          , bs::cmplx::complex_<A0>
                          , bd::generic_< bd::arithmetic_<A1> >
                          )
  {
    using value_t   = typename A0::value_type;
    using base_t    = typename nsm::if_c<is_pack_t<A1>::value, A1, value_t>::type;
    using result_t  = cmplx::complex<base_t>;

    BOOST_FORCEINLINE result_t operator()( pedantic_tag const &
                                         , A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      return pedantic_(multiplies)(a1, a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( multiplies_
                          , (typename A0,typename A1)
                          , bd::cpu_
                          , bs::pedantic_tag
                          , bd::generic_< bd::arithmetic_<A0> >
                          , bs::cmplx::complex_<A1>
                          )
  {
    using value_t   = typename A1::value_type;
    using base_t    = typename nsm::if_c<is_pack_t<A0>::value, A0, value_t>::type;
    using result_t  = cmplx::complex<base_t>;

    BOOST_FORCEINLINE result_t operator()( pedantic_tag const &
                                         , A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      auto r = a0*a1.real;
      auto i = a0*a1.imag;
      auto is_real_a1 = is_real(a1);
      r = if_zero_else(logical_andnot(is_imag(a1), is_real_a1), r);
      i = if_zero_else(is_real_a1, i);
      return { r, i };
    }
  };


} } }

#endif
