//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPRECNEGC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPRECNEGC_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-exprecnegc exprecnegc (function object)

    This function object computes: \f$1-e^{-\frac1x}\f$

    @headerref{<boost/simd/function/exprecnegc.hpp>}

    @par Description

      @code
      IEEEValue exprecnegc(IEEEValue const& x);
      @endcode

    @par Notes

    - result is accurate even for large @c x

    @par Example:

      @snippet exprecnegc.cpp exprecnegc

    @par Possible output:

      @snippet exprecnegc.txt exprecnegc

  **/

#include <boost/simd/function/scalar/exprecnegc.hpp>
#include <boost/simd/function/simd/exprecnegc.hpp>

#endif
