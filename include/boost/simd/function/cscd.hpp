//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CSCD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CSCD_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-cscd cscd (function object)

    This function object returns the cosecant in degree: \f$1/\sin(180/(\pi x))\f$.

    @headerref{<boost/simd/function/cscd.hpp>}

    @par Description

      @code
      IEEEValue cscd(IEEEValue const& x);
      @endcode

    @par Note

     As most other trigonometric function cscd can be called with a
     second optional parameter  which is a tag on speed and accuracy
     (see @ref cos for further details)


    @see csc, cscpi


    @par Example:

      @snippet cscd.cpp cscd

    @par Possible output:

      @snippet cscd.txt cscd

  **/

#include <boost/simd/function/scalar/cscd.hpp>
#include <boost/simd/function/simd/cscd.hpp>

#endif
