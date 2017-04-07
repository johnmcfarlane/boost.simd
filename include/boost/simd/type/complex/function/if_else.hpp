//==================================================================================================
/*!
  @file
  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IF_ELSE_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-if_else if_else (function object)

    This function object conditionally returns @c t (respectively @c f) if @c c
    is @ref True (respectively  @ref False)


    @headerref{<boost/simd/type/complex/function/if_else.hpp>}

    @par Description

        @code
        IEEEValue if_else(Value const & c, complex<IEEEValue> const& t, complex<IEEEValue> const& f);
        @endcode

    @pre If both second and third parameters are pack, they must have same cardinal.

    @see ( %real ) [if_else](@ref  real-if_else)

    @par Example:

       @snippet c_if_else.cpp if_else

    @par Possible output:

       @snippet c_if_else.txt if_else

  **/
} } }

#endif

#include <boost/simd/function/if_else.hpp>
#include <boost/simd/type/complex/function/impl/if_else.hpp>

#endif
