//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CSC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CSC_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-csc csc (function object)

    This function object returns the cosecante of the input in radian : \f$1/\sin(x)\f$.

    @headerref{<boost/simd/function/csc.hpp>}

    @par Description

      @code
      IEEEValue csc(IEEEValue const& x);
      @endcode

    @par Note

      As most other trigonometric function csc can be called
      with a second optional parameter  which is a tag on
      speed and accuracy (see @ref cos for further details)

    @see cscd, cscpi,


    @par Example:

      @snippet csc.cpp csc

    @par Possible output:

      @snippet csc.txt csc

  **/

#include <boost/simd/function/scalar/csc.hpp>
#include <boost/simd/function/simd/csc.hpp>

#endif
