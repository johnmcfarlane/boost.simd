//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGATE_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-negate negate (function object)

    This function object returns  the first element multiplied by 1,  0 or -1 depending
    on the fact its second argument is greater,  equal or lesser than zero.

    @headerref{<boost/simd/function/negate.hpp>}

    @par Description

      @code
      Value negate(Value const& x, Value const& y);
      @endcode

    @par Note
    If y is @ref Zero the result is zero. This can be avoided using @ref negatenz or @ref copysign.

    @see sign, negatenz, copysign,  Mzero,  is_positive, is_negative


    @par Example:

      @snippet negate.cpp negate

    @par Possible output:

      @snippet negate.txt negate

  **/

#include <boost/simd/function/scalar/negate.hpp>
#include <boost/simd/function/simd/negate.hpp>

#endif
