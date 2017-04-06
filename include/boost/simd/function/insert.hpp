//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INSERT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INSERT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-insert insert (function object)

   Modify the value of the nth element of a mutable data.

    @headerref{<boost/simd/function/insert.hpp>}

    @par Description

      @code
      template<typename Value, typename Offset>
      @endcode

    @par Semantic

    Depending on the type of its arguments, insert exhibits different semantics.
    For any value @c v of type @c Value, @c d of type @c Data and @c o of
    type @c Offset:

    @code
    insert(d, o, v);
    @endcode

    is equivalent to:

    - If @c Type is a scalar type:

      @code
      d = v;
      @endcode

    - If @c Type is a SIMD type:

      @code
      d[o] = v;
      @endcode

  **/

#include <boost/simd/function/scalar/insert.hpp>
#include <boost/simd/function/simd/insert.hpp>

#endif
