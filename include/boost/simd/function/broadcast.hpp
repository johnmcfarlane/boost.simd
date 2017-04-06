//==================================================================================================
/*!
  @file
    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BROADCAST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BROADCAST_HPP_INCLUDED

  /*!
    @ingroup group-swar
    @defgroup real-broadcast broadcast (function object)

    Returns a boost::simd::pack filled with the value of the @c N th value of its argument.

    @headerref{<boost/simd/function/broadcast.hpp>}

    @par Description

      @code
      template<std::size_t Index, typename Value> Value broadcast(Value const& v);
      @endcode

    @par Scalar Semantic:
    For any value @c v of type @c T and any integral constant @c I, the following code:

    @code
    T r = boost::simd::broadcast<I>(v);
    @endcode

    is equivalent to:

    @code
    T r = I == 0 ? static_cast<T>(v) : T{0};
    @endcode

    @par SIMD Semantic:
    For any type @c T and any integral constants @c N and @c I, the following code:

    @code
    pack<T,N> r = boost::simd::broadcast<I>(v);
    @endcode

    is equivalent to:

    @code
    pack<T,N> r{ ((I < N) || (I>=0)) ? v[I] : 0};
    @endcode

    The extraction of the value is done using the optimal intrinsics if available or will proceed to
    a memory read-back. See boost::simd::extract for more informations.

    @tparam Index index of the value to broadcast
  **/

#include <boost/simd/function/scalar/broadcast.hpp>
#include <boost/simd/function/simd/broadcast.hpp>

#endif
