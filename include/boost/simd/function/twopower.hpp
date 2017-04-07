//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TWOPOWER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TWOPOWER_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-twopower twopower (function object)

    This function object returns \f$2^n\f$ (or 0 if n is less than zero)

    @headerref{<boost/simd/function/twopower.hpp>}

    @par Description

      @code
      IntegerValue twopower(IntegerValue const& x);
      @endcode

    @par Note:

    This function is not defined for floating entries

    @see ( %real ) [ilog2](@ref real-ilog2)

    @par Example:

      @snippet twopower.cpp twopower

    @par Possible output:

      @snippet twopower.txt twopower

  **/

#include <boost/simd/function/scalar/twopower.hpp>
#include <boost/simd/function/simd/twopower.hpp>

#endif
