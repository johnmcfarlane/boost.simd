//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_COSH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_COSH_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup group-complex-cosh  Complex cosh
    This function object returns the complex hyperbolic cosine of a complex value z.

    `complex<IEEEValue> cosh(complex<IEEEValue> const& z);`

    @par Header <boost/simd/type/complex/function/cosh.hpp>

    @par Notes

    - `cosh(bs::conj(z))` is always equal to `conj(bs::cosh(z))`
    - `cosh(-z)` is always equal to `cosh(z)`

    - we always have:

        - If {{tt|z}} is {{tt|(+0,+0)}}, the result is {{tt|(1,+0)}}
        - If {{tt|z}} is {{tt|(+0,+$B!g(B)}}, the result is {{tt|(NaN,±0)}} (the sign of the imaginary part is unspecified) and {{lc|FE_INVALID}} is raised
        - If {{tt|z}} is {{tt|(+0,NaN)}}, the result is {{tt|(NaN,±0)}} (the sign of the imaginary part is unspecified)
        - If {{tt|z}} is {{tt|(x,+$B!g(B)}} (for any finite non-zero x), the result is {{tt|(NaN,NaN)}} and {{lc|FE_INVALID}} is raised
        - If {{tt|z}} is {{tt|(x,NaN)}} (for any finite non-zero x), the result is {{tt|(NaN,NaN)}} and {{lc|FE_INVALID}} may be raised
        - If {{tt|z}} is {{tt|(+$B!g(B,+0)}}, the result is {{tt|(+$B!g(B,+0)}}
        - If {{tt|z}} is {{tt|(+$B!g(B,y)}} (for any finite non-zero y), the result is {{tt|(+$B!g(B,cis(y))}}
        - If {{tt|z}} is {{tt|(+$B!g(B,+$B!g(B)}}, the result is {{tt|(±$B!g(B,NaN)}} (the sign of the real part is unspecified) and {{lc|FE_INVALID}} is raised
        - If {{tt|z}} is {{tt|(+$B!g(B,NaN)}}, the result is {{tt|(+$B!g(B,NaN)}}
        - If {{tt|z}} is {{tt|(NaN,+0)}}, the result is {{tt|(NaN,±0)}} (the sign of the imaginary part is unspecified)
        - If {{tt|z}} is {{tt|(NaN,+y)}} (for any finite non-zero y), the result is {{tt|(NaN,NaN)}} and {{lc|FE_INVALID}} may be raised
        - If {{tt|z}} is {{tt|(NaN,NaN)}}, the result is {{tt|(NaN,NaN)}}

    @par Example:

       @snippet c_cosh.cpp cosh

    @par Possible output:

       @snippet c_cosh.txt cosh

  **/
  complex<IEEEValue> cos(complex<IEEEValue> const& z);
} }

#endif
namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, cosh_, boost::dispatch::elementwise_<cosh_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cosh_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cosh_,cosh);


} }

#endif
