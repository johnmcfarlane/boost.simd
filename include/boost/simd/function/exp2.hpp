//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXP2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXP2_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-exp2 exp2 (function object)

    This function object returns the base two exponential of its argument: \f$2^{x}\f$

    @headerref{<boost/simd/function/exp2.hpp>}

    @par Description

      @code
      IEEEValue exp2(IEEEValue const& x);
      @endcode

    @par Decorators

      - std_ for floating entries calls @c std::exp2

    @par Note:

    - provisions are made to obtain a flint result from a flint argument

    @see ( %real ) [exp](@ref real-exp), [exp10](@ref real-exp10), [pow](@ref real-pow), [pow2](@ref real-pow2)

    @par Example:

      @snippet exp2.cpp exp2

    @par Possible output:

      @snippet exp2.txt exp2

  **/

#include <boost/simd/function/scalar/exp2.hpp>
#include <boost/simd/function/simd/exp2.hpp>

#endif
