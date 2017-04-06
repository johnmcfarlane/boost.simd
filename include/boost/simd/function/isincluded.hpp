//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ISINCLUDED_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ISINCLUDED_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-isincluded isincluded (function object)

    This function object returns @c true is only if all bits set in @c x are
  also set in @c y

    The two arguments must share the same bit size.

    @headerref{<boost/simd/function/isincluded.hpp>}

    @par Description

      @code
      bool isincluded(Value const& x, Value const& y);
      @endcode

    @par Example:

      @snippet isincluded.cpp isincluded

    @par Possible output:

      @snippet isincluded.txt isincluded

  **/

#include <boost/simd/function/scalar/isincluded.hpp>
#include <boost/simd/function/simd/isincluded.hpp>

#endif
