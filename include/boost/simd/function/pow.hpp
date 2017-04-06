//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POW_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POW_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-pow pow (function object)

    This function object computes \f$x^y\f$

    @headerref{<boost/simd/function/pow.hpp>}

    @par Description

      @code
      ///@{
      @endcode

    @par Decorators
      - std_ decorator calls @c std:pow

      - raw_ decorator almost nearly uses the naive formula (\f$e^{y\log x}\f$)
         and so does not care for limits and leads to lower accuracy


    @par Example:

      @snippet pow.cpp pow

    @par Possible output:

      @snippet pow.txt pow

  **/

#include <boost/simd/function/scalar/pow.hpp>
#include <boost/simd/function/simd/pow.hpp>

#endif
