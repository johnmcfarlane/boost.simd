//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REPEAT_UPPER_HALF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REPEAT_UPPER_HALF_HPP_INCLUDED

  /*!
    @ingroup group-swar
    @defgroup real-repeat_upper_half repeat_upper_half (function object)

    Function object implementing repeat_upper_half capabilities

        Repeat upper half of a vector

    @headerref{<boost/simd/function/repeat_upper_half.hpp>}

    @par Description

      @code
      Value repeat_upper_half(Value const& x);
      @endcode

    @par Semantic:

    For every parameter of type T

    @code
    T r = repeat_upper_half(x);
    @endcode

    is similar to:

    @code
      T r;
      const std::size_t       n = meta::cardinal_of<T>::value;
      const std::size_t  middle = meta::cardinal_of<T>::value/2;
      for(std::size_t i=middle;i<n;++i)
      {
        r[i] = r[i-middle] = x[i];
      }
    @endcode

  **/

#include <boost/simd/function/simd/repeat_upper_half.hpp>

#endif
