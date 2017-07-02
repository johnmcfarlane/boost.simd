//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REM_PIO2_MEDIUM_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REM_PIO2_MEDIUM_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/config.hpp>
#include <utility>

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  rem_pio2_medium_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N,simd_emulation_> const& a) BOOST_NOEXCEPT
  {
    return map_to(rem_pio2_medium, a);
  }

} } }


#endif
