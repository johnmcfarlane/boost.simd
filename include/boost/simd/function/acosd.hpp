//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOSD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOSD_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-acosd acosd (function object)

    This function object returns the inverse cosine in degree.

    @headerref{<boost/simd/function/acosd.hpp>}

    @par Description

      @code
      IEEEValue acosd(IEEEValue const & x);
      @endcode

    @par Decorators

       - pedantic_     is similar to indeg(pedantic_)(acos(x));

    @see ( %real ) [acos](@ref real-acos), [acospi](@ref real-acospi), [cosd](@ref real-cosd), [indeg](@ref real-indeg)

    @par Example:

      @snippet acosd.cpp acosd

    @par Possible output:

      @snippet acosd.txt acosd

  **/

#include <boost/simd/function/scalar/acosd.hpp>
#include <boost/simd/function/simd/acosd.hpp>

#endif
