//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ALLBITS_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ALLBITS_ELSE_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_allbits_else if_allbits_else (function object)

    This function object  returns @ref [Allbits](@ref constant-Allbits) if  @c c is @ref [True](@ref constant-True) else returns @c f

    @headerref{<boost/simd/function/if_allbits_else.hpp>}

    @par Description

      @code
      Value1 if_allbits_else(Value0 const& c, Value1 const& f);
      @endcode

    @see ( %real ) [genmask](@ref real-genmask), [Allbits](@ref constant-Allbits), [Nan](@ref constant-Nan)

    @par Example:

      @snippet if_allbits_else.cpp if_allbits_else

    @par Possible output:

      @snippet if_allbits_else.txt if_allbits_else

    @par Alias:
    @c if_nan_else,

    @see genmask, Allbits, Nan

  **/

#include <boost/simd/function/scalar/if_allbits_else.hpp>
#include <boost/simd/function/simd/if_allbits_else.hpp>

#endif
