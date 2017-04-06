//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LDEXP_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-ldexp ldexp (function object)

    This function object returns  \f$x\f$ multiplied by
    by \f$2^{n}\f$

    @headerref{<boost/simd/function/ldexp.hpp>}

    @par Description

      @code
      Value0 ldexp(Value0 const& x, Value1 const& n);
      @endcode

    @par Decorators

     - pedantic_ By default @c ldexp does not take care of denormal or limiting values.
       Use the @c pedantic_ decorator if these are to be properly computed.

     - std_ give access to std::ldexp

    @par Note

     If @c n is not of integral type it is truncated:
     `ldexp(x,n)` is similar to: `x*pow(2, trunc(n))`

    @par Example:

      @snippet ldexp.cpp ldexp

    @par Possible output:

      @snippet ldexp.txt ldexp

  **/

#include <boost/simd/function/scalar/ldexp.hpp>
#include <boost/simd/function/simd/ldexp.hpp>

#endif
