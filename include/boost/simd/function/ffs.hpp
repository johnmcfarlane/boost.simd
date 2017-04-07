//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FFS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FFS_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-ffs ffs (function object)

    This function object returns  the index
    of the first bit set (beginning with the least
    significant bit) in the parameter.

    @headerref{<boost/simd/function/ffs.hpp>}

    @par Description

      @code
      as_integer_t<Value> ffs(Value const& x);
      @endcode

    @see ( %real ) [firstbitset](@ref real-firstbitset), [firstbitunset](@ref real-firstbitunset)

    @par Example:

      @snippet ffs.cpp ffs

    @par Possible output:

      @snippet ffs.txt ffs

  **/

#include <boost/simd/function/scalar/ffs.hpp>
#include <boost/simd/function/simd/ffs.hpp>

#endif
