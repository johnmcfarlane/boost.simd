//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASEC_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-asec asec (function object)

    This function object returns the inverse secant in radian: \f$\arccos(1/x)\f$.

    @headerref{<boost/simd/function/asec.hpp>}

    @par Description

      @code
      IEEEValue asec(IEEEValue const & x);
      @endcode

    @see ( %real ) [asecd](@ref real-asecd), [asecpi](@ref real-asecpi)

    @par Example:

      @snippet asec.cpp asec

    @par Possible output:

      @snippet asec.txt asec

  **/

#include <boost/simd/function/scalar/asec.hpp>
#include <boost/simd/function/simd/asec.hpp>

#endif
