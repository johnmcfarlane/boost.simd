//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITOFSIGN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITOFSIGN_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-bitofsign bitofsign (function object)

    This function object returns a value of the same type as
    the input with all bits set to zero
    except the sign bit which is preserved.
    This function object returns always @ref Zero for unsigned types

    @headerref{<boost/simd/function/bitofsign.hpp>}

    @par Description

      @code
      Value bitofsign(Value const& x);
      @endcode

    @par Example:

      @snippet bitofsign.cpp bitofsign

    @par Possible output:

      @snippet bitofsign.txt bitofsign

  **/

#include <boost/simd/function/scalar/bitofsign.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>

#endif
