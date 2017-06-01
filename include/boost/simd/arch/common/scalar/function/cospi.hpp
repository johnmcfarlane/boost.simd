//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COSPI_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COSPI_HPP_INCLUDED

#include <boost/simd/arch/common/detail/scalar/trigo.hpp>
#include <boost/simd/function/restricted.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/function/is_odd.hpp>
#include <boost/simd/meta/is_not_scalar.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T scospi_( T const& a
           , std::true_type const &) BOOST_NOEXCEPT
  {
    return detail::trig_base<T,tag::pi_tag,is_pack_t<T>>::cosa(a);
  }

  template<typename T,
           typename = typename std::enable_if<tt_::is_signed<T>::value>
  >
  BOOST_FORCEINLINE
  T scospi_( T const& a
           , std::false_type) BOOST_NOEXCEPT
  {
    return (bs::is_odd(a)?Mone<T>():One<T>());
  }

  template<typename T>
  BOOST_FORCEINLINE
  T cospi_(BOOST_SIMD_SUPPORTS(cpu_)
         , T const& a) BOOST_NOEXCEPT
  {
    return scospi_(a, std::is_floating_point<T>());
  }

  //================================================================================================
  // restricted_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T cospi_(BOOST_SIMD_SUPPORTS(cpu_)
         , restricted_tag const&
         , T const& a) BOOST_NOEXCEPT
  {
    return detail::trig_base<T,tag::pi_tag,is_pack_t<T>,tag::clipped_pio4_tag>::cosa(a);
  }

  //================================================================================================
  // other_ tags
  template<typename T, typename Tag>
  BOOST_FORCEINLINE
  T cospi_(BOOST_SIMD_SUPPORTS(cpu_)
         , T const& a
         , Tag const& ) BOOST_NOEXCEPT
  {
    return detail::trig_base<T,tag::pi_tag,is_pack_t<T>,Tag>::cosa(a);
  }

} } }


#endif
