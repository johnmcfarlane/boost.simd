//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MEMORY_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-api
    @defgroup api-memory Memory Management

    Classes, functions and macros for handling memory in a SIMD compatible way.
  **/
} }

#include <boost/simd/memory/aligned_delete.hpp>
#include <boost/simd/memory/aligned_object.hpp>
#include <boost/simd/memory/allocate.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/memory/deallocate.hpp>
#include <boost/simd/memory/is_aligned.hpp>
#include <boost/simd/memory/preferred_alignment.hpp>

#include <boost/simd/function/load.hpp>
#include <boost/simd/function/aligned_load.hpp>

#include <boost/simd/memory/mask.hpp>

#endif
