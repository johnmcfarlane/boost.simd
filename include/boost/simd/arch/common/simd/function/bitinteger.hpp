//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITINTEGER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITINTEGER_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N
          , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE
  btg_t<pack<T, N>> bitinteger_( BOOST_SIMD_SUPPORTS(simd_)
                      , pack<T, N> a
                      ) BOOST_NOEXCEPT
  {
    using result_t = btg_t<pack<T, N>>;
    result_t a0 = simd::bitwise_cast<result_t>(a);
    return if_else(bs::is_positive(a), a0, Signmask<result_t>()-a0 );
  }

} } }

#endif

