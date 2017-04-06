//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_REAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_REAL_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_real is_real (function object)

    This function object returns @ref True or @ref False according x is real or not.
    For non complex numbers this is always true.

    @headerref{<boost/simd/function/is_real.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_real(Value const& x);
      @endcode

    @par Note

     Using `is_real(x)` is similar to: `True` for real inputs.

    @par Example:

      @snippet is_real.cpp is_real

    @par Possible output:

      @snippet is_real.txt is_real

  **/

#include <boost/simd/function/scalar/is_real.hpp>
#include <boost/simd/function/scalar/is_real.hpp>
#include <boost/simd/function/simd/is_real.hpp>

#endif
