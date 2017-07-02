//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N >
  BOOST_FORCEINLINE
  as_ui_t<pack<T, N>> bits_( BOOST_SIMD_SUPPORTS(simd_)
                      , pack<T, N> a
                      ) BOOST_NOEXCEPT
  {
    using r_t = as_ui_t<pack<T, N>>;
    return bitwise_cast<r_t>(a);
  }

} } }


#endif
