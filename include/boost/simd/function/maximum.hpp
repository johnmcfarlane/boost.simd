//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAXIMUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAXIMUM_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-maximum maximum (function object)

   This function object returns the greatest element of the argument

    @headerref{<boost/simd/function/maximum.hpp>}

    @par Description

      @code
      scalar_of_t<Value> maximum(Value const& x);
      @endcode

    @see minimum

    @par Example:

      @snippet maximum.cpp maximum

    @par Possible output:

      @snippet maximum.txt maximum

  **/

#include <boost/simd/function/scalar/maximum.hpp>
#include <boost/simd/function/simd/maximum.hpp>

#endif
