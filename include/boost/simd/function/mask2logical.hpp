//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MASK2LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MASK2LOGICAL_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-mask2logical mask2logical (function object)

    This function object converts
    an arithmetic mask where each element is
    Zero or Allbits to a logical value.

    If it is not the case this function asserts.

    @headerref{<boost/simd/function/mask2logical.hpp>}

    @par Description

      @code
      as_logical_t<Value> mask2logical(Value const& x);
      @endcode

    @par Example:

      @snippet mask2logical.cpp mask2logical

    @par Possible output:

      @snippet mask2logical.txt mask2logical

  **/

#include <boost/simd/function/scalar/mask2logical.hpp>
#include <boost/simd/function/simd/mask2logical.hpp>

#endif
