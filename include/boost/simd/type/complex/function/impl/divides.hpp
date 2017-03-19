//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_DIVIDES_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>

#include <boost/simd/function/is_imag.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/function/copysign.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/type/complex/function/conj.hpp>
#include <boost/simd/type/complex/function/if_else.hpp>
#include <boost/simd/type/complex/function/is_inf.hpp>
#include <boost/simd/type/complex/function/is_finite.hpp>
#include <boost/simd/type/complex/function/ldexp.hpp>
#include <boost/simd/type/complex/function/sqr_abs.hpp>
#include <boost/simd/meta/is_pack.hpp>
#include <boost/config.hpp>
#include <boost/core/demangle.hpp>
#include <type_traits>

// template<typename T> inline std::string type_id()
// {
//   typedef std::is_const<typename std::remove_reference<T>::type>  const_t;
//   typedef std::is_lvalue_reference<T>                             lref_t;
//   typedef std::is_rvalue_reference<T>                             rref_t;
//   std::string s = boost::core::demangle(typeid(T).name());
//   s += const_t::value ? " const"  : "";
//   s += lref_t::value   ? "&"      : "";
//   s += rref_t::value   ? "&&"     : "";
//   return s;
// }
// template<typename T> inline std::string type_id( const T& )
// {
//   return type_id<T>();
// }
namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF( divides_
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
      auto rr =  bs::abs(a1.real);
      auto ii =  bs::abs(a1.imag);
      auto e =  -if_else((rr < ii), exponent(ii), exponent(rr));
      auto aa1(bs::ldexp(a1, e));
      auto denom =  sqr_abs(aa1);
      result_t num = bs::multiplies(a0, conj(aa1));
      result_t r =  ldexp(bs::divides(num, denom), e);
     return r;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( divides_
                          , (typename A0,typename A1)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          , bd::scalar_< bd::arithmetic_<A1> >
                          )
  {
    using value_t   = typename A0::value_type;
    using value1_t  = bd::scalar_of_t<value_t>;
    using base_t    = typename nsm::if_c<is_pack_t<A1>::value, A1, value_t>::type;
    using result_t  = cmplx::complex<base_t>;

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& a1) const BOOST_NOEXCEPT
    {
      return a0*rec(static_cast<value1_t>(a1));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( divides_
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
      return a0*rec(a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( divides_
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
      auto tmp = a0/sqr_abs(a1);
      return if_else(is_inf(a1), result_t(tmp), tmp*conj(a1));
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF( divides_
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
      auto rr =  bs::abs(a1.real);
      auto ii =  bs::abs(a1.imag);
      auto e =  -if_else((rr < ii), exponent(ii), exponent(rr));
      result_t aa1 =  bs::ldexp(a1, e);
      auto denom =  sqr_abs(aa1);
      result_t num = bs::multiplies(a0, conj(aa1));
      result_t r =  ldexp(bs::divides(num, denom), e);
      if (bs::all(is_finite(r))) return r;
      r = if_else(is_eqz(denom), bs::multiplies(a0, copysign(Inf<base_t>(), a1.real)), r);
      r = if_else(is_inf(a1),    bs::multiplies(a0, rec(copysign(denom, a1.real))), r);
      return r;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( divides_
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
      return pedantic_(divides(a1, a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( divides_
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
      return divides(a0, a1);
    }
  };


} } }

#endif
