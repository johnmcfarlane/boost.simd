//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COSD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COSD_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/arch/common/detail/simd/trigo.hpp>
#include <boost/simd/function/restricted.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/meta/is_pack.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> cosd_(BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return detail::trig_base<p_t,tag::degree_tag,is_pack_t<p_t>,tag::big_tag>::cosa(a);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> cosd_ ( BOOST_SIMD_SUPPORTS(simd_)
                                 , pack<T,N,simd_emulation_> const& a
                                 ) BOOST_NOEXCEPT
  {
    return map_to(simd::cosd, a);
  }

  // restricted_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> cosd_( BOOST_SIMD_SUPPORTS(simd_)
                  , restricted_tag const&
                  , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return detail::trig_base<p_t, tag::degree_tag,is_pack_t<p_t>,tag::clipped_pio4_tag>::cosa(a);
  }

  // other tags
  template<typename T, std::size_t N, typename X, typename Tag>
  BOOST_FORCEINLINE
  pack<T,N> cosd_( BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a
                , Tag const&) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return detail::trig_base<p_t, tag::degree_tag, is_pack_t<p_t>,Tag>::cosa(a);

  }

} } }


#endif
