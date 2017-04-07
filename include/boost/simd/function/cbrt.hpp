//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CBRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CBRT_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-cbrt cbrt (function object)

    This function object returns the cubic root of its argument: \f$\sqrt[3]{x}\f$

    @headerref{<boost/simd/function/cbrt.hpp>}

    @par Description

      @code
      IEEEValue cbrt(IEEEValue const& x);
      @endcode

    @par Decorators

      - std_ for floating entries calls @c std::cbrt

    @see ( %real ) [pow](@ref real-pow), [sqrt](@ref real-sqrt)

    @par Example:

      @snippet cbrt.cpp cbrt

    @par Possible output:

      @snippet cbrt.txt cbrt

  **/

#include <boost/simd/function/scalar/cbrt.hpp>
#include <boost/simd/function/simd/cbrt.hpp>

#endif
