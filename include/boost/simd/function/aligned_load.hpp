//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup api-memory
    @defgroup memory-aligned_load aligned_load (function template)

    @brief Load data from an aligned memory location.

    @headerref{<boost/simd/function/aligned_load.hpp>}

    @par Description

    1.  @code
        template<typename Value, typename Iterator>
        Value aligned_load(Iterator ptr);
        @endcode

    2.  @code
        template<std::ptrdiff_t Offset, typename Value, typename Vectorizable>
        Value aligned_load(Vectorizable const* ptr);
        @endcode

    3.  @code
        template<typename Value, typename Vectorizable, typename IntegerValue>
        Value aligned_load(Vectorizable const* ptr, IntegerValue offset);
        @endcode

    4.  @code
        template<typename Value, typename MaskedPtr>
        Value aligned_load(MaskedPtr m);
        @endcode

    1.  Obtains the value pointed to by `ptr`.
    2.  Obtains the value pointed to by the combination of `ptr` and `Offset`.
    3.  Obtains the value pointed to by the combination of `ptr` and `offset`.
    4.  Conditionally obtains the value pointed to by the [masked pointer](@ref memory-mask) `m`.

    @par Parameters

    | Name                | Description                                     |
    |--------------------:|:------------------------------------------------|
    | **ptr**             | Iterator to the data to be obtained             |
    | **first**,**last**  | Iterator to the range of data to be obtained    |
    | **offset**          | offset to be applied to `ptr`                   |
    | **m**               | [A logically-masked pointer](@ref memory-mask)  |

    @par Requirements

    1. `std::addressof(*ptr) % alignof(Value) == 0` evaluates to `true`.
    2. `(ptr+Offset) % alignof(Value) == 0` evaluates to `true`.
    3. `(ptr+offset) % alignof(Value) == 0` evaluates to `true`.
    4. `ptr.get() % alignof(Value) == 0` evaluates to `true`.

    @par Return Value

    1. A Value that contains the data obtained from `ptr`.
    2. A Value that contains the data obtained from `ptr + Offset`.
    3. A Value that contains the data obtained from the combination of `ptr + offset`.
    4. A Value that contains the data obtained from the [A logically-masked pointer](@ref memory-mask)
       whenever the associated logical mask evaluates to `true`.

    @par Complexity

    1. If `ptr` models ContiguousIterator, a single read is performed. Otherwise, at most
       `cardinal_of<Value>::value` reads are performed.
    2. If `Value` is Vectorizable, a single read is performed. Otherwise, at most two reads are
       performed in order to reconstruct the misaligned value unless a native SIMD intrinsic is
       available to perform a single optimized read.
    3. If `ptr` models ContiguousIterator, a single read is performed. Otherwise, at most
       `cardinal_of<Value>::value` reads are performed.
    4. At most`cardinal_of<Value>::value` reads are performed unless a native SIMD intrinsic is
       available on current architecture to handle masked aligned_load. The actual number of memory read
       performed is equal to the number of mask element that evaluates to `true`.

    @par Related components
      - @ref memory-mask
      - @ref memory-load

    @par Example
    @snippet aligned_load.cpp aligned_load

    Possible output

    @snippet aligned_load.txt aligned_load
  **/
} }
#include <boost/simd/function/scalar/aligned_load.hpp>
#include <boost/simd/function/simd/aligned_load.hpp>

#endif
