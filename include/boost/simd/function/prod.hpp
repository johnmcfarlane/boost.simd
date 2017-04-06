//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_PROD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_PROD_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-prod prod (function object)

   This function object returns the product of the elements of the argument

    @headerref{<boost/simd/function/prod.hpp>}

    @par Description

      @code
      scalar_of_t<Value> prod(Value const& x);
      @endcode

    @see sum


    @par Example:

      @snippet prod.cpp prod

    @par Possible output:

      @snippet prod.txt prod

  **/

#include <boost/simd/function/scalar/prod.hpp>
#include <boost/simd/function/simd/prod.hpp>

#endif
