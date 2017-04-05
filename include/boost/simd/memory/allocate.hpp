//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MEMORY_ALLOCATE_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_ALLOCATE_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/align/aligned_alloc.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup api-memory
    @defgroup memory-allocate allocate (function template)

    Allocate memory suitable for storing data with a SIMD compatible alignment

    @headerref{<boost/simd/memory/allocate.hpp>}

    @par Description

    1.  @code
        template<typename Type>
        Type* allocate(std::size_t size)
        @endcode

    2.  @code
        template<typename Type, typename Arch>
        Type* allocate(std::size_t size, Arch const& arch)
        @endcode

    1.  Allocates space for a memory block of  @c size elements of type @c Type with an alignment
        compatible with the current SIMD instructions set.

    2.  Allocates space for a memory block of  @c size elements of type @c Type with an alignment
        compatible with the selected SIMD instructions set @c arch.

    @par Parameters

    | Name                | Description                                       |
    |--------------------:|:--------------------------------------------------|
    | **size**            | the number of element of type @c Type to allocate |
    | **arch**            | an SIMD instructions set tag value                |

    @par Return Value
    A pointer to the allocated space.

    @par Requirements
    - @c Type must model Vectorizable

    @par Related components
      - @ref memory-deallocate

    @par Example
    @snippet allocate.cpp allocate

    Possible output

    @snippet allocate.txt allocate
  **/

  template<typename T> T* allocate(std::size_t size)
  {
    return reinterpret_cast<T*>(boost::alignment::aligned_alloc(pack<T>::alignment,size*sizeof(T)));
  }

  template<typename T, typename Arch> T* allocate(std::size_t size, Arch const&)
  {
    return reinterpret_cast<T*>(boost::alignment::aligned_alloc(limits<Arch>::bytes,size*sizeof(T)));
  }
} }

#endif
