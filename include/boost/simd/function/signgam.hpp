//==================================================================================================
/*!
  @file
    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIGNGAM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIGNGAM_HPP_INCLUDED

  /*!
    @ingroup group-euler
    @defgroup real-signgam signgam (function object)

    This function object computes the sign of gamma function without explicitly computing
    the costly gamma function.

    @headerref{<boost/simd/function/signgam.hpp>}

    @par Description

      @code
      IEEEValue signgam(IEEEValue const& x);
      @endcode

    @see ( %real ) [gamma](@ref real-gamma), [gammaln](@ref real-gammaln)

    @par Example:

      @snippet stirling.cpp stirling

    @par Possible output:

      @snippet stirling.txt stirling
  **/

#include <boost/simd/function/scalar/signgam.hpp>
#include <boost/simd/function/simd/signgam.hpp>

#endif
