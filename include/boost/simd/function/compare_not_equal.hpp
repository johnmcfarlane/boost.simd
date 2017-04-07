//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_NOT_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_NOT_EQUAL_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-compare_not_equal compare_not_equal (function object)

    This function object returns @c true if and only if two corresponding entries
    elements are not equal.

    It is probably not what you wish. Have a look to  [is_not_equal](@ref real-is_not_equal)

    @headerref{<boost/simd/function/compare_not_equal.hpp>}

    @par Description

      @code
      bool compare_not_equal(Value const& x, Value const& y);
      @endcode

    @par Example:

      @snippet compare_not_equal.cpp compare_not_equal

    @par Possible output:

      @snippet compare_not_equal.txt compare_not_equal

  **/

#include <boost/simd/function/scalar/compare_not_equal.hpp>
#include <boost/simd/function/simd/compare_not_equal.hpp>

#endif
