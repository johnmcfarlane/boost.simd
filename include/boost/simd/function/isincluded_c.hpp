//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ISINCLUDED_C_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ISINCLUDED_C_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-isincluded_c isincluded_c (function object)

     This function object returns @c true is only if all bits set in @c x are
   not set in @c y

     The two arguments must share the same bit size.

    @headerref{<boost/simd/function/isincluded_c.hpp>}

    @par Description

      @code
      bool isincluded_c(Value const& x, Value const& y);
      @endcode

    @par Example:

      @snippet isincluded_c.cpp isincluded_c

    @par Possible output:

      @snippet isincluded_c.txt isincluded_c

  **/

#include <boost/simd/function/scalar/isincluded_c.hpp>
#include <boost/simd/function/simd/isincluded_c.hpp>

#endif
