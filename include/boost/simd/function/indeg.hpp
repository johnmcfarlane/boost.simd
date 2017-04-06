//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INDEG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INDEG_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-indeg indeg (function object)

    This function object converts radian to degree.

    @headerref{<boost/simd/function/indeg.hpp>}

    @par Description

      @code
      IEEEValue indeg(IEEEValue const& x);
      @endcode

    @par Example:

      @snippet indeg.cpp indeg

    @par Possible output:

      @snippet indeg.txt indeg

  **/

#include <boost/simd/function/scalar/indeg.hpp>
#include <boost/simd/function/simd/indeg.hpp>

#endif
