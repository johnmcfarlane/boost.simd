//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_GREATER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_GREATER_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-compare_greater compare_greater (function object)

    This function object returns the return a @c bool that is the result of the
    lexicographic test for > on all elements of the entries

    It is probably not what you wish. Have a look to  [is_greater](@ref real-is_greater)

    @headerref{<boost/simd/function/compare_greater.hpp>}

    @par Description

      @code
      bool compare_greater(Value const& x, Value const& y);
      @endcode

    @par Example:

      @snippet compare_greater.cpp compare_greater

    @par Possible output:

      @snippet compare_greater.txt compare_greater

  **/

#include <boost/simd/function/scalar/compare_greater.hpp>
#include <boost/simd/function/simd/compare_greater.hpp>

#endif
