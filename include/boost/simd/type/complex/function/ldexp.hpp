//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_LDEXP_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-ldexp ldexp (function object)

    This function object returns ldexp aplied to both real and imaginary parts of the first input.

    @headerref{<boost/simd/type/complex/function/ldexp.hpp>}

    @par Description

    @code
    as_logical<IEEEValue> ldexp(complex<IEEEValue> const& z, Value const & e);
    @endcode


    @see ( %real ) [ldexp](@ref  real-ldexp)

    @par Example:

       @snippet c_ldexp.cpp ldexp

    @par Possible output:

       @snippet c_ldexp.txt ldexp

  **/
} }
#endif
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/type/complex/function/impl/ldexp.hpp>

#endif
