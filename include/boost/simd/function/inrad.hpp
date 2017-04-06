//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INRAD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INRAD_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-inrad inrad (function object)

    This function object converts degree to radian.

    @headerref{<boost/simd/function/inrad.hpp>}

    @par Description

      @code
      IEEEValue inrad(IEEEValue const& x);
      @endcode

    @par Example:

      @snippet inrad.cpp inrad

    @par Possible output:

      @snippet inrad.txt inrad

  **/

#include <boost/simd/function/scalar/inrad.hpp>
#include <boost/simd/function/simd/inrad.hpp>

#endif
