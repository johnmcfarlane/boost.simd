//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ALL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ALL_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-all all (function object)

   This function object returns @c true if all elements of the argument are
   non zero.

    @headerref{<boost/simd/function/all.hpp>}

    @par Description

      @code
      bool all(Value const &x);
      @endcode

    @see any, none, nbtrue

    @par Example:

      @snippet all.cpp all

    @par Possible output:

      @snippet all.txt all

  **/

#include <boost/simd/function/scalar/all.hpp>
#include <boost/simd/function/simd/all.hpp>

#endif
