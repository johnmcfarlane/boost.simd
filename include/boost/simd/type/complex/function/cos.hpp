//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_COS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_COS_HPP_INCLUDED

  /*!
    @ingroup group-complex
    @defgroup complex-cos cos (function object, complex version)
    This function object, complex version returns the complex cosine of a complex value z.

    @headerref{<boost/simd/type/complex/function/cos.hpp>}

    @par Description

    @code
    complex<IEEEValue> cos(complex<IEEEValue> const& z);
    @endcode


    @par Notes

     - special cases are handled as if the operation is implemented by `bs::cosh(i*z)`,
       where i is the imaginary unit.

    @see ( %real ) [cos](@ref  real-cos)

    @par Example:

       @snippet c_cos.cpp cos

    @par Possible output:

       @snippet c_cos.txt cos

  **/


#include <boost/simd/function/cos.hpp>
#include <boost/simd/type/complex/function/impl/cos.hpp>

#endif
