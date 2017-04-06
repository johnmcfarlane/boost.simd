//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REPEAT_LOWER_HALF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REPEAT_LOWER_HALF_HPP_INCLUDED

  /*!
    @ingroup group-swar
    @defgroup real-repeat_lower_half repeat_lower_half (function object)

    Repeat the lower half of a vector

    @headerref{<boost/simd/function/repeat_lower_half.hpp>}

    @par Description

      @code
      Value repeat_lower_half(Value const& x);
      @endcode

    @par Semantic:

    For every parameter of type T

    @code
    T r = repeat_lower_half(x);
    @endcode

    is similar to:

    @code
      T r;
      const std::size_t  middle = meta::cardinal_of<A0>::value/2;
      for(std::size_t i=0;i<middle;++i)
      {
        r[i] = r[i+middle] = x[i];
      }
    @endcode

  **/

#include <boost/simd/function/simd/repeat_lower_half.hpp>

#endif
