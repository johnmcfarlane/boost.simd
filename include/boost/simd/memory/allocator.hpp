//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MEMORY_ALLOCATOR_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_ALLOCATOR_HPP_INCLUDED

#include <boost/align/aligned_allocator.hpp>
#include <boost/simd/memory/preferred_alignment.hpp>
#include <boost/simd/pack.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup api-memory
    @defgroup memory-allocator allocator (alias template)

    Standard compliant allocator with alignment compatible with SIMD constraint.

    @par Description

    1.  @code
        template<typename Type, std::size_t Cardinal>
        using allocator = implementation-defined
        @endcode

    2.  @code
        template<typename Type>
        using allocator = implementation-defined
        @endcode

    1.  Convenience alias defining a standard compliant allocator returning memory which alignment
        is compatible with the storage of boost::simd::pack<Type,Cardinal> if @c Type models
        Vectorizable or with @c alignof(Type) otherwise.

    2.  Convenience alias defining a standard compliant allocator returning memory which alignment
        is compatible with the storage of boost::simd::pack<Type> if @c Type models Vectorizable
        or with @c alignof(Type) otherwise.

    @par Type Parameters

    | Name         | Description                                  |
    |-------------:|:---------------------------------------------|
    | **Type**     | Type of the data to allocate                 |
    | **Cardinal** | Cardinal of the Vectorized type to allocate  |

    @par Type Requirements
    - If specified, **Cardinal** must be a non-zero power of two.


    @par Example

    @snippet allocator.cpp allocator

    Possible output

    @snippet allocator.txt allocator
  **/
  template<typename T, std::size_t Cardinal = 0ULL>
  using allocator = boost::alignment::aligned_allocator<T,preferred_alignment<T,Cardinal>::value>;
} }

#endif
