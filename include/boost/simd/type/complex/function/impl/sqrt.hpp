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
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/if_neg.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/type/complex/function/conj.hpp>
#include <boost/simd/type/complex/function/if_else.hpp>
#include <boost/simd/type/complex/function/is_finite.hpp>
#include <boost/simd/type/complex/function/is_nan.hpp>
#include <boost/simd/type/complex/function/is_real.hpp>
#include <boost/config.hpp>

// #include <boost/core/demangle.hpp>
// #include <type_traits>

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

 BOOST_DISPATCH_OVERLOAD ( cmplx_sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      //always compute the sqroot of the complex with positive bs::imag part
      //then conjugate if necessary
      using rtype = typename A0::value_type;
      auto ia0 = a0.imag;
      auto negimag = is_ltz(ia0);
      rtype x = bs::abs(a0.real);
      rtype y = bs::abs(ia0);
      rtype iaa0 = if_neg(negimag, ia0); // always >= 0 or -Nan
      auto gtxy = (x > y);
      auto gezra0 = is_gez(a0.real);
      rtype r = if_else(gtxy, y/x, x/y);
      rtype rr= bs::sqrt(inc(sqr(r)));
      rtype sqrtx = bs::sqrt(x);
      rtype w = if_else(gtxy,
                        sqrtx*sqrt(Half<rtype>()*inc(rr)),
                        bs::sqrt(y)*bs::sqrt(Half<rtype>()*(r+rr)));
       auto is_real_a0 = is_real(a0);
       A0 z = A0(if_else(is_real_a0, sqrtx, w), if_zero_else(is_real_a0, iaa0*Half<rtype>()/w));
       z = if_else(gezra0, z, A0(z.imag, z.real));
       return if_else(negimag, conj(z), z);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( cmplx_sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    using result_t = cmplx::complex<A0>;
    BOOST_FORCEINLINE result_t operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      auto root = bs::sqrt(abs(a0));
      return { if_else_zero(a0>0,root), if_zero_else(a0>0,root)};
    }
  };


   BOOST_DISPATCH_OVERLOAD ( cmplx_sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , bs::pedantic_tag
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(pedantic_tag const&
                                   , A0 const& a0) const BOOST_NOEXCEPT
    {
      //always compute the sqroot of the complex with positive bs::imag part
      //then conjugate if necessary
      using rtype = typename A0::value_type;
      auto ia0 = a0.imag;
      auto negimag = is_ltz(ia0);
      rtype x = bs::abs(a0.real);
      rtype y = bs::abs(ia0);
      rtype iaa0 = if_neg(negimag, ia0); // always >= 0 or Nan
      auto gtxy = (x > y);
      auto gezra0 = is_gez(a0.real);
      rtype r = if_else(gtxy, y/x, x/y);
      rtype rr= bs::sqrt(inc(sqr(r)));
      rtype sqrtx = bs::sqrt(x);
      rtype w = if_else(gtxy,
                        sqrtx*sqrt(Half<rtype>()*inc(rr)),
                        bs::sqrt(y)*bs::sqrt(Half<rtype>()*(r+rr)));
       auto is_real_a0 = is_real(a0);
//       std::cout << type_id(is_real_a0) <<  std::endl;
       A0 z = A0(if_else(is_real_a0, sqrtx, w), if_zero_else(is_real_a0, iaa0*Half<rtype>()/w));
       z = if_else(gezra0, z, A0(z.imag, z.real));
       if (bs::all(bs::is_finite(z))) return if_else(negimag, conj(z), z);
       //pedantic nécessite z le retour de regular avant conjugaison  + iaa0 +ia0 pe factoriser +tard

       z = if_else(iaa0 == Inf<rtype>(),
                   A0(Inf<rtype>(), Inf<rtype>()),
                   z);
       z = if_else(logical_andnot(a0.real ==  Minf<rtype>(), is_nan(iaa0)),
                   A0(if_else_zero(iaa0 == Inf<rtype>(), iaa0), Inf<rtype>()),
                   z);
       z = if_else(logical_and(is_real(a0), is_nan(a0)), a0, z);
       z = if_else(logical_or(is_nan(a0.real), is_nan(ia0)), A0(Nan<rtype>(), Nan<rtype>()), z);
       z = if_else(logical_and(is_real(a0), is_gez(a0.real)), A0(z.real), z);
       return if_else(negimag, conj(z), z);
    }
  };
} } }

#endif
