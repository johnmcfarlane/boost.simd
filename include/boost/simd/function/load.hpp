//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOAD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOAD_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup api-memory
    @defgroup memory-load load (function template)

    @brief Load data from a memory location.

    @headerref{<boost/simd/function/load.hpp>}

    @par Description

    1.  @code
        template<typename Value, typename Iterator>
        Value load(Iterator ptr);
        @endcode

    2.  @code
        template<typename Value, typename Iterator>
        Value load(Iterator ptr, std::ptrdiff_t offset);
        @endcode

    3.  @code
        template<typename Value, typename Iterator>
        Value load(Iterator first, Iterator last);
        @endcode

    4.  @code
        template<typename Value, typename MaskedPtr>
        Value load(MaskedPtr m);
        @endcode

    1.  Obtains the value pointed to by `ptr`.
    2.  Obtains the value pointed to by the combination of `ptr` and `offset`.
    3.  Obtains the value contained in the range @range{first, last}.
    4.  Conditionally obtains the value pointed to by the [masked pointer](@ref memory-mask) `m`.

    @par Parameters

    | Name                | Description                                     |
    |--------------------:|:------------------------------------------------|
    | **ptr**             | Iterator to the data to be obtained             |
    | **first**,**last**  | Iterator to the range of data to be obtained    |
    | **offset**          | offset to be applied to `ptr`                   |
    | **m**               | [A logically-masked pointer](@ref memory-mask)  |

    @par Return Value

    1. A Value that contains the data obtained from `ptr`.
    2. A Value that contains the data obtained from the combination of `ptr` and `offset`. If
       `offset` is a Vectorizable integral value, this is equivalent to `load<Value>(ptr+offset)`.
       If `offset` is a Vectorized integral value of cardinal `N`, this is equivalent to
       `Value r{ *(ptr+offset[0]), ..., *(ptr+offset[N-1])}`, which is also
       known as [a gather operation](http://insidehpc.com/2015/05/gather-scatter-operations/).
    3. A Value that contains the data obtained from the range @range{first, last}.
    4. A Value that contains the data obtained from the [A logically-masked pointer](@ref memory-mask)
       whenever the associated logical mask evaluates to `true`.

    @par Complexity

    1. If `ptr` models ContiguousIterator, a single read is performed. Otherwise, at most
       `cardinal_of<Value>::value` reads are performed.
    2. If `offset` is a Vectorizable integral value, the complexity is equivalent to case 1.
       If `offset` is a Vectorized integral value, at most`cardinal_of<Value>::value` reads are
       performed unless a native SIMD intrinsic is available on current architecture.

    3. Exactly `std::distance(first,last)` reads are performed.
    4. At most`cardinal_of<Value>::value` reads are performed unless a native SIMD intrinsic is
       available on current architecture to handle masked load. The actual number of memory read
       performed is equal to the number of mask element that evaluates to `true`.

    @par Related components
      - @ref memory-mask
      - @ref memory-aligned_load

    @par Example
    @snippet load.cpp load

    Possible output

    @snippet load.txt load
  **/
} }

#include <boost/simd/function/scalar/load.hpp>
#include <boost/simd/function/simd/load.hpp>

#endif
