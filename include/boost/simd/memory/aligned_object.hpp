//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MEMORY_ALIGNED_OBJECT_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_ALIGNED_OBJECT_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/align/aligned_alloc.hpp>

/*!
    @ingroup api-memory
    @defgroup memory-aligned_object BOOST_SIMD_ALIGNED_OBJECT (macro function)

    Adapt use-defined types to be dynamically allocated while respecting alignment constraints.

    @headerref{<boost/simd/memory/aligned_object.hpp>}

    @par Description

    @code
    #define BOOST_SIMD_ALIGNED_OBJECT(TYPE) // implementation defined
    @endcode

    Injects the required code to make sure that current user-defined @c TYPE will be dynamically
    allocated while respecting its alignment constraints.

    @par Type Parameters

    | Name     | Description                    |
    |---------:|:-------------------------------|
    | **TYPE** | Name of the type being adapted |

    @par Example
    @snippet aligned_object.cpp aligned_object

    Possible output

    @snippet aligned_object.txt aligned_object
**/

#define BOOST_SIMD_ALIGNED_OBJECT(Type)                                                             \
static void* operator new(std::size_t sz)                                                           \
{                                                                                                   \
  return boost::alignment::aligned_alloc(alignof(Type), sz);                                        \
}                                                                                                   \
                                                                                                    \
static void operator delete(void* ptr) BOOST_NOEXCEPT                                               \
{                                                                                                   \
  boost::alignment::aligned_free(ptr);                                                              \
}                                                                                                   \
                                                                                                    \
static void* operator new[](std::size_t sz)                                                         \
{                                                                                                   \
  return boost::alignment::aligned_alloc(alignof(Type), sz);                                        \
}                                                                                                   \
                                                                                                    \
static void operator delete[](void* ptr) BOOST_NOEXCEPT                                             \
{                                                                                                   \
  boost::alignment::aligned_free(ptr);                                                              \
}                                                                                                   \
/**/

#endif
