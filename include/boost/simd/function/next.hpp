//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEXT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEXT_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-next next (function object)

    This function object returns the smallest representable value
    strictly greater than the parameter except:

    - for entries of floating types

       - next(Valmax) is Inf

       - next(-Inf) is Valmin

       - next(Inf) is Inf

       - next(Nan) is Nan

    - for entries of integral type

      - next(Valmax) is Valmin

    @headerref{<boost/simd/function/next.hpp>}

    @par Description

      @code
      Value next(Value const& x);
      @endcode

    @see ( %real ) [nextafter](@ref real-nextafter), [prev](@ref real-prev), [successor](@ref real-successor), [predecessor](@ref real-predecessor)

    @par Example:

      @snippet next.cpp next

    @par Possible output:

      @snippet next.txt next

  **/

#include <boost/simd/function/scalar/next.hpp>
#include <boost/simd/function/simd/next.hpp>

#endif
