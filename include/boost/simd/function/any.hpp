//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ANY_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ANY_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-any any (function object)

   This function object returns @c true if at least one element of the
   argument is non zero.

    @headerref{<boost/simd/function/any.hpp>}

    @par Description

      @code
      bool any(Value const &x);
      @endcode

    @see all, none, nbtrue

    @par Example:

      @snippet any.cpp any

    @par Possible output:

      @snippet any.txt any

  **/

#include <boost/simd/function/scalar/any.hpp>
#include <boost/simd/function/simd/any.hpp>

#endif
