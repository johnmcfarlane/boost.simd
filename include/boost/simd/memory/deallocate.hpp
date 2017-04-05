//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MEMORY_DEALLOCATE_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_DEALLOCATE_HPP_INCLUDED

#include <boost/align/aligned_alloc.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup api-memory
    @defgroup memory-deallocate deallocate (function template)

    Deallocate aligned memory blocks.

    @headerref{<boost/simd/memory/deallocate.hpp>}

    @par Description

    @code
    template<typename Type>
    void deallocate(Type* ptr)
    @endcode

    Deallocates space from a memory block of allocated by
    [boost::simd::allocate](@ref memory-allocate).

    @par Parameters

    | Name                | Description                       |
    |--------------------:|:----------------------------------|
    | **ptr**             | pointer to the data to deallocate |

    @par Return Value
    (none)

    @par Requirements
    - @c Type must model Vectorizable

    @par Related components
      - @ref memory-allocate

    @par Example
    @snippet allocate.cpp allocate

    Possible output

    @snippet allocate.txt allocate
  **/
  template<typename T> void deallocate(T* ptr)
  {
    return boost::alignment::aligned_free(ptr);
  }
} }

#endif
