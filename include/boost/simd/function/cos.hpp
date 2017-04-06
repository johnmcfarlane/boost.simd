//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COS_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-cos cos (function object)

    This function object returns the cosine of the input in radians.

    @headerref{<boost/simd/function/cos.hpp>}

    @par Description

      @code
      IEEEValue cos(IEEEValue const& x);
      @endcode

    @par Decorators

       - std_ provides access to std::cos

       - restricted_ is equivalent to the clipped_very_small_ tag

    @par Notes
      The regular call to this functor is `cos(x)`,  but
    @see  sincos, cosd, cospi

    @par Example:

      @snippet cos.cpp cos

    @par Possible output:

      @snippet cos.txt cos

  **/

#include <boost/simd/function/scalar/cos.hpp>
#include <boost/simd/function/simd/cos.hpp>

#endif
