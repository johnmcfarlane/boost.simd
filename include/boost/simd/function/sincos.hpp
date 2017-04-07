//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINCOS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINCOS_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-sincos sincos (function object)

    This function object computes simultaneouly
    and at lower cost the sine and cosine of the input

    @headerref{<boost/simd/function/sincos.hpp>}

    @par Description

      @code
      std::pair<IEEEValue, IEEEValue> sincos(IEEEValue const& x);
      @endcode

    @see ( %real ) [sincosd](@ref real-sincosd), [sincospi](@ref real-sincospi)

    @par Example:

      @snippet sincos.cpp sincos

    @par Possible output:

      @snippet sincos.txt sincos

  **/

#include <boost/simd/function/scalar/sincos.hpp>
#include <boost/simd/function/simd/sincos.hpp>

#endif
