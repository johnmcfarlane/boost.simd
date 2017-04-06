//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINCOSD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINCOSD_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-sincosd sincosd (function object)

    This function object computes simultaneously and
    at lower cost the sind and cosd of the input

    @headerref{<boost/simd/function/sincosd.hpp>}

    @par Description

      @code
      std::pair<IEEEValue, IEEEValue> sincosd(IEEEValue const& x);
      @endcode

    @see sincos, sincospi

    @par Example:

      @snippet sincosd.cpp sincosd

    @par Possible output:

      @snippet sincosd.txt sincosd

  **/

#include <boost/simd/function/scalar/sincosd.hpp>
#include <boost/simd/function/simd/sincosd.hpp>

#endif
