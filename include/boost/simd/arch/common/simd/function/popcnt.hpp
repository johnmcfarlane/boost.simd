//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_POPCNT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_POPCNT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> popcnt_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return map_to(simd::popcnt, a)
  }

} } }


#endif
