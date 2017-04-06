//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RAW_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RAW_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/decorator.hpp>
#include <boost/simd/detail/dispatch.hpp>

  /*!
    @ingroup group-decorator
    @defgroup real-raw raw (function object)

     grant access to low-level, low-accuracy intrinsics
     provided by some SIMD architectures.

    @headerref{<boost/simd/function/raw.hpp>}

    @par Description

      @code
      template<typename T> auto raw_(T const& x) {}
      @endcode

    @par Semantic

    @code
    T r = raw_(func)(< func parameters >);
    @endcode
  **/

namespace boost { namespace simd
{
  struct raw_tag : decorator_<raw_tag>
  {
    using parent = decorator_<raw_tag>;
  };

  const detail::decorator<raw_tag> raw_ = {};
} }

#endif
