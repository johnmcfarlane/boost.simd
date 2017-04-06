//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NONE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NONE_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-none none (function object)

     This function object returns @c true if all elements of the argument are zero.

    @headerref{<boost/simd/function/none.hpp>}

    @par Description

      @code
      bool none(Value const& x);
      @endcode

    @par Example:

      @snippet none.cpp none

    @par Possible output:

      @snippet none.txt none

  **/

#include <boost/simd/function/scalar/none.hpp>
#include <boost/simd/function/simd/none.hpp>

#endif
