//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MEMORY_IS_ALIGNED_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_IS_ALIGNED_HPP_INCLUDED

#include <boost/simd/memory/preferred_alignment.hpp>
#include <boost/simd/detail/is_aligned.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd
{

  /*!
    @ingroup api-memory
    @defgroup memory-is_aligned is_aligned (function template)

    Checks if a pointer is aligned within a given SIMD alignment constraints.

    @headerref{<boost/simd/memory/is_aligned.hpp>}

    @par Description

    1.  @code
        template<typename T>
        bool is_aligned(T const* ptr) noexcept
        @endcode

    2.  @code
        template<typename T, typename Arch>
        bool is_aligned(T const* ptr, Arch const& arch) noexcept
        @endcode

    1.  Checks if a pointer is aligned within current architecture's constraints.

    2.  Checks if a pointer is aligned withing a given architecture's constraints.

    @par Parameters

    | Name                | Description                         |
    |--------------------:|:------------------------------------|
    | **ptr**             | the pointer to check alignment of   |
    | **arch**            | an SIMD instructions set tag value  |

    @par Return Value
    1.  Returns @c true if **ptr** is aligned on current architecture's constraints.
    1.  Returns @c true if **ptr** is aligned on **arch**'s constraints.

    @par Example
    @snippet is_aligned.cpp is_aligned

    Possible output

    @snippet is_aligned.txt is_aligned
  **/

  template<typename T>
  BOOST_FORCEINLINE bool is_aligned(T const* ptr) BOOST_NOEXCEPT
  {
    return ::boost::simd::detail::is_aligned(ptr, preferred_alignment<T>::value );
  }

  template<typename T, typename Arch>
  BOOST_FORCEINLINE bool is_aligned(T const* ptr, Arch const&) BOOST_NOEXCEPT
  {
    return ::boost::simd::detail::is_aligned(ptr, limits<Arch>::bytes );
  }
} }

#endif
