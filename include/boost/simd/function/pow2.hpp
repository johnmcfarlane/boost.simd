//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POW2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POW2_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-pow2 pow2 (function object)

    This function object returns \f$ x 2^y\f$.  (the result is undefined on overflow and
    the function asserts for invalid second parameter )

    @headerref{<boost/simd/function/pow2.hpp>}

    @par Description

      @code
      ///@{
      @endcode

    @par Note

   The first parameter default to @c One.

    @par Example:

      @snippet pow2.cpp pow2

    @par Possible output:

      @snippet pow2.txt pow2

  **/

#include <boost/simd/function/scalar/pow2.hpp>
#include <boost/simd/function/simd/pow2.hpp>

#endif
