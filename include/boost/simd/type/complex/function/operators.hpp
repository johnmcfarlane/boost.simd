//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_OPERATORS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_OPERATORS_HPP_INCLUDED

#include <boost/simd/type/complex/function/divides.hpp>
#include <boost/simd/type/complex/function/is_equal.hpp>
#include <boost/simd/type/complex/function/is_not_equal.hpp>
#include <boost/simd/type/complex/function/minus.hpp>
#include <boost/simd/type/complex/function/multiplies.hpp>
#include <boost/simd/type/complex/function/plus.hpp>
#include <boost/simd/type/complex/function/unary_minus.hpp>
#include <boost/simd/type/complex/function/unary_plus.hpp>

#define BOOST_SIMD_UNARY_COMPLEX_OP(op,func)                                                        \
template<typename Type> auto op (complex<Type> const& z) BOOST_NOEXCEPT_DECLTYPE_BODY(func(z))      \
/**/

#define BOOST_SIMD_BINARY_COMPLEX_OP(op,func)                                                       \
template<typename Z1, typename Z2> auto op (complex<Z1> const& z1,complex<Z2> const& z2)            \
BOOST_NOEXCEPT_DECLTYPE_BODY(func(z1,z2))                                                           \
                                                                                                    \
template<typename Type, typename Real>                                                              \
auto op (complex<Type> const& z1, Real const& z2)                                                   \
BOOST_NOEXCEPT_DECLTYPE_BODY(func(z1,z2))                                                           \
                                                                                                    \
template<typename Type, typename Real>                                                              \
auto op (Real const& z1, complex<Type> const& z2)                                                   \
BOOST_NOEXCEPT_DECLTYPE_BODY(func(z1,z2))                                                           \
/**/

namespace boost { namespace simd { namespace cmplx
{
  // Arithmetic operators
  BOOST_SIMD_BINARY_COMPLEX_OP(operator+,bs::plus)
  BOOST_SIMD_BINARY_COMPLEX_OP(operator-,bs::minus)
  BOOST_SIMD_BINARY_COMPLEX_OP(operator*,bs::multiplies)
  BOOST_SIMD_BINARY_COMPLEX_OP(operator/,bs::divides)
  BOOST_SIMD_UNARY_COMPLEX_OP(operator-,bs::unary_minus)
  BOOST_SIMD_UNARY_COMPLEX_OP(operator+,bs::unary_plus)

  // Logical operators
  BOOST_SIMD_BINARY_COMPLEX_OP(operator==,bs::is_equal)
  BOOST_SIMD_BINARY_COMPLEX_OP(operator!=,bs::is_not_equal)
} } }

#undef BOOST_SIMD_UNARY_COMPLEX_OP
#undef BOOST_SIMD_BINARY_COMPLEX_OP

#endif
