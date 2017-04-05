//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MEMORY_ALIGNED_DELETE_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_ALIGNED_DELETE_HPP_INCLUDED

#include <boost/align/aligned_delete.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup api-memory
    @defgroup memory-aligned_delete aligned_delete (alias template)

    Standard compliant deleter that handles pointer to aligned memory.

    @par Description

    @code
    using aligned_delete = implementation-defined
    @endcode

    Convenience alias defining a standard compliant deleter that handles pointer to aligned memory.

    @par Example

    @snippet aligned_delete.cpp aligned_delete

    Possible output

    @snippet aligned_delete.txt aligned_delete
  **/
  using aligned_delete = boost::alignment::aligned_delete;
} }

#endif
