//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXP10_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXP10_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/arch/common/detail/simd/exponential.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/meta/is_pack.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> exp10_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return detail::exponential<p_t,bs::tag::exp10_,is_pack_t<p_t>>::expa(a);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> exp10_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::exp10, a);
  }


} } }

#endif
