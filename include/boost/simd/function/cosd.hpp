//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COSD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COSD_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-cosd cosd (function object)

    This function object returns the cosine of the input in degree:
    \f$\cos(\pi x/180)\f$.

    @headerref{<boost/simd/function/cosd.hpp>}

    @par Description

      @code
      IEEEValue cosd(IEEEValue const& x);
      @endcode

    @par Note

     - The semantics of the function are similar to @ref cos ones.

    @see sincosd, cos, cospi


    @par Example:

      @snippet cosd.cpp cosd

    @par Possible output:

      @snippet cosd.txt cosd

  **/

#include <boost/simd/function/scalar/cosd.hpp>
#include <boost/simd/function/simd/cosd.hpp>

#endif
