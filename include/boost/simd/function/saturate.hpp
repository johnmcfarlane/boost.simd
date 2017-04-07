//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SATURATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SATURATE_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-saturate saturate (function object)

    This function object returns the saturated value of the first input in the template
    parameter type, but in the same type as the  argument.

    @headerref{<boost/simd/function/saturate.hpp>}

    @par Description

      @code
      template <typename Target> Value saturate(Value const & x);
      @endcode

    @par Semantic:


    For every parameter of type @c T and type @c Target

    @code
    T r = saturate<Target>(x)
    @endcode

    is similar to:

    @code
    if (x >  Inf<Target>()) r =  T(Inf<Target>());
    else if  (x <  Minf<Target>()) r =  T(Minf<Target>());
    else r = x;
    @endcode

    @see ( %real ) [Minf](@ref constant-Minf), [Inf](@ref constant-Inf), [Valmax](@ref constant-Valmax), [Valmin](@ref constant-Valmin)

    @par Note

    Let us recall that  [Valmin](@ref constant-Valmin) and  [Minf](@ref constant-Minf) (resp.  [Valmax](@ref constant-Valmax) and  [Inf](@ref constant-Inf))
    are identical if Target is  an integer type.


    @see Minf, Inf, Valmax, Valmin

    @par Example:

      @snippet saturate.cpp saturate

    @par Possible output:

      @snippet saturate.txt saturate

  **/

#include <boost/simd/function/scalar/saturate.hpp>
#include <boost/simd/function/simd/saturate.hpp>

#endif
