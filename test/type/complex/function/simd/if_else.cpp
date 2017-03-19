//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/if_else.hpp>
#include <boost/simd/type/complex/function/sqr_abs.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

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

namespace bs = boost::simd;

STF_CASE_TPL( "Addition with to complex<pack<T>>/complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r0{3,-2,0,1}, i0{0,5,-2,-5};
  p_t   r1{1,2,3,0}, i1{0,5,-2,-5};
  p_t   r2{3,-2, 3, 1}, i2{0,5,-2,-5};

  pc_t  c0(r0,i0), c1(r1,i1), c2(r2, i2);
  STF_EQUAL(bs::if_else(bs::sqr_abs(r0) >=  bs::sqr_abs(r1), c0, c1), c2);
}



