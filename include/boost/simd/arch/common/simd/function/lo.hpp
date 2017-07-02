//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LO_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LO_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/interleave_even.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <type_traits>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
 template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T, N>> vlo_(pack<T,N> const& a0
                       , std::true_type const &) BOOST_NOEXCEPT
  {
    using r_t = as_ui_t<pack<T, N>>;
    using d_t = pack<int32_t>;
    return bitwise_cast<r_t>(interleave_even(bitwise_cast<d_t>(a0), Zero<d_t>()));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T, N>> vlo_(pack<T,N> const& a0
                       , std::false_type const &) BOOST_NOEXCEPT
  {
    using s_t = as_ui_t<T>;
    using r_t = as_ui_t<pack < T, N>>;
    r_t sh((s_t(1) << sizeof(s_t)*(CHAR_BIT/2)) - 1);
    return bitwise_and(sh, a0);

  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T, N>> lo_(BOOST_SIMD_SUPPORTS(cpu_)
                      , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vlo_(a, nsm::bool_< sizeof(T)== 8>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_ui_t<pack<T, N, simd_emulation_>>
  lo_(BOOST_SIMD_SUPPORTS(cpu_)
     , pack<T,N, simd_emulation_> const& a) BOOST_NOEXCEPT
  {
    return map_to(simd::lo, a);
  }

} } }


#endif
