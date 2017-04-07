//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOSPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOSPI_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-acospi acospi (function object)

    This function object returns the inverse cosine in \f$\pi\f$ multiples.

    @headerref{<boost/simd/function/acospi.hpp>}

    @par Description

      @code
      IEEEValue acospi(IEEEValue const & x);
      @endcode

    @par Decorators

       - pedantic_     is similar to Invpi<T>*pedantic_(acos)(x);

    @see ( %real ) [acos](@ref real-acos), [acospi](@ref real-acospi), [cosd](@ref real-cosd)

    @par Example:

      @snippet acospi.cpp acospi

    @par Possible output:

      @snippet acospi.txt acospi

  **/

#include <boost/simd/function/scalar/acospi.hpp>
#include <boost/simd/function/simd/acospi.hpp>

#endif
