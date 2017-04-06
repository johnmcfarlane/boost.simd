//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CONJ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CONJ_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-conj conj (function object)

    function object computes the complex conjugate of its parameter

    @headerref{<boost/simd/function/conj.hpp>}

    @par Description

      @code
      Value conj(Value const& x);
      @endcode

    @par Notes

    - for real entries it resumes to the identity

  **/

#include <boost/simd/function/scalar/conj.hpp>
#include <boost/simd/function/simd/conj.hpp>

#endif
