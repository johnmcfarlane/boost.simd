//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_NEG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_NEG_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_neg if_neg (function object)

    This function object conditionally returns  -x if c is  [True](@ref constant-True) and x otherwise.

    @headerref{<boost/simd/function/if_neg.hpp>}

    @par Description

      @code
      Value1 if_neg(Value0 const& c, Value1 const& x);
      @endcode

    @par Example:

      @snippet negif.cpp negif

    @par Possible output:

      @snippet negif.txt negif

  **/

#include <boost/simd/function/scalar/if_neg.hpp>
#include <boost/simd/function/simd/if_neg.hpp>

#endif
