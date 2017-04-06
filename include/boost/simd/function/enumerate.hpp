//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ENUMERATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ENUMERATE_HPP_INCLUDED

namespace boost { namespace simd
{

  /*!
    @ingroup group-swar
    @defgroup real-enumerate enumerate (function object)

    Generates a value containing sequentially increasing elements, starting with @c seed and
    repetitively evaluating @c seed+=step.

    @headerref{<boost/simd/function/enumerate.hpp>}

    @par Description

      @code
      Value enumerate(const ScalarValue& seed = 0, const ScalarValue& step = 1);
      @endcode

    @par SIMD Semantic:
    For any type @c T and integral constant @c N, the following code:
    @code
    auto r = enumerate<boost::simd::pack<T,N>>(seed, step);
    @endcode
    is equivalent to:
    @code
    boost::simd::pack<T,N> r{seed, seed+step, ..., seed+(N-1)*step};
    @endcode

  **/

} }

#include <boost/simd/function/scalar/enumerate.hpp>
#include <boost/simd/function/simd/enumerate.hpp>

#endif
