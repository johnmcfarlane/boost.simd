//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NLEZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NLEZ_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_nlez is_nlez (function object)

    This function object returns @ref True if x is not less or equal to @ref Zero else returns @ref False.

    @headerref{<boost/simd/function/is_nlez.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_nlez(Value const& x);
      @endcode

    @par Note

     Using `is_nlez(x)` is similar to: `!(x <= 0)`

    @par Example:

      @snippet is_nlez.cpp is_nlez

    @par Possible output:

      @snippet is_nlez.txt is_nlez

  **/

#include <boost/simd/function/scalar/is_nlez.hpp>
#include <boost/simd/function/simd/is_nlez.hpp>

#endif
