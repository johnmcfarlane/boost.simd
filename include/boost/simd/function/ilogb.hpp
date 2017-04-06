//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ILOGB_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ILOGB_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-ilogb ilogb (function object)

    This function object Extracts the value of the unbiased exponent from
    the floating-point argument x, and returns it as a signed integer value.

    @headerref{<boost/simd/function/ilogb.hpp>}

    @par Description

      @code
      as_integer_t<Value> ilogb(Value const& x);
      @endcode

     @par Decorators

       - std_ provides access to std::ilogb

       - pedantic_ return FP_ILOGB0 and FP_ILOGBNAN for 0 and nan respectively,
         but the return type is as in the regular call.

    @par Note:

      - Formally, the unbiased exponent is the integral part of \f$\log_r|x|\f$
      as a signed integral value, for non-zero x, where r is
      std::numeric_limits<T>::radix and T is the floating-point type of arg.

      - In practice r = 2 for all supported platforms

      - boost::simd::ilogb differ from std::ilogb in the return type that is always the
        integer type associated to the input type and the limiting values (zero return zero
        and the result is always greater than zero)

      - for floating inputs nan and zero returns zero and +-inf return Valmax

    @par Example:

      @snippet ilogb.cpp ilogb

    @par Possible output:

      @snippet ilogb.txt ilogb

  **/

#include <boost/simd/function/scalar/ilogb.hpp>
#include <boost/simd/function/simd/ilogb.hpp>

#endif
