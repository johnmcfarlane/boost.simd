//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINUS_HPP_INCLUDED

  /*!
    @ingroup group-operator
    @defgroup real-minus minus (function object)

    This function object computes the difference of two parameters of the same type.

    Infix notation can be used with operator '-',

    @headerref{<boost/simd/function/minus.hpp>}

    @par Description

      @code
      Value minus(Value const& x, Value const& y);
      @endcode

    @par Decorators

     - `saturated_` (See @ref group-decorator) computes the saturated difference.

    @see plus, divides, multiplies

    @par Example:

      @snippet minus.cpp minus

    @par Possible output:

      @snippet minus.txt minus

  **/

#include <boost/simd/function/scalar/minus.hpp>
#include <boost/simd/function/simd/minus.hpp>

#endif
