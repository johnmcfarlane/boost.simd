//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ROUND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ROUND_HPP_INCLUDED
#include <boost/simd/pack.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/ceil.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/copysign.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/none.hpp>
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/function/tenpower.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/mpl/equal_to.hpp>

namespace boost { namespace simd { namespace detail
{
  // one parameter round
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vround_( pack<T,N> const& a0, std::true_type const &) BOOST_NOEXCEPT
  {
    auto v = bs::abs(a0);
    auto c = bs::ceil(v);
    return if_else(v > Maxflint(as(a0)), a0, copysign(if_dec(c-Half(as(a0)) > v, c), a0));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vround_( pack<T,N> const& a0, std::false_type const &) BOOST_NOEXCEPT
  {
    return a0;
  }


  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> round_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return vround_(a0, std::is_floating_point<T>());
  }

 // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> round_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::round, a);
  }

  //std_ decorator
  template<typename T, std::size_t N >
  BOOST_FORCEINLINE
  auto round_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const &
         , pack<T, N> const &a) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to(std::round, a)
  )
  //================================================================================================
  // two parameters round
  // scalar signed iT
  template<typename T, typename iT, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vround_( pack<T,N> const& a0
                   , iT const& a1
                   , std::true_type const &) BOOST_NOEXCEPT
  {
    auto fac = tenpower(a1);
    auto tmp1 = round(a0*fac)/fac;
    return if_else(is_ltz(a1), round(tmp1), tmp1);
  }

  // scalar unsigned iT
  template<typename T, typename iT, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vround_( pack<T,N> const& a0
                   , iT const& a1
                   , std::false_type const &) BOOST_NOEXCEPT
  {
    auto fac = tenpower(a1);
    return round(a0*fac)/fac;
  }

 // pack signed iT
  template<typename T, typename iT, std::size_t N
           , typename = typename std::enable_if<std::is_integral<iT>::value>::type
           , typename = typename std::enable_if<sizeof(T) == sizeof(iT)>::type
  >
  BOOST_FORCEINLINE
  pack<T,N> vround_( pack<T,N> const& a0
                   , pack<iT,N> const& a1
                   , std::true_type const & ) BOOST_NOEXCEPT
  {
    return vround_(a0, a1, std::is_signed<iT>());
  }

 // pack unsigned iT
  template<typename T, typename iT, std::size_t N
           , typename = typename std::enable_if<std::is_integral<iT>::value>::type
           , typename = typename std::enable_if<sizeof(T) == sizeof(iT)>::type
           >
  BOOST_FORCEINLINE
  pack<T,N> vround_( pack<T,N> const& a0
                   , pack<iT,N> const& a1
                   , std::false_type const &) BOOST_NOEXCEPT
  {
    auto fac = tenpower(a1);
    return round(a0*fac)/fac;
  }


  template<typename T,typename iT, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> round_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0
                 , iT const& a1 ) BOOST_NOEXCEPT
  {
    return vround_(a0, a1, std::is_signed<iT>());
  }

  // Emulated implementation
  template<typename T, typename T1, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> round_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a0
                                  , pack<T1,N,simd_emulation_> const& a1
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::round, a0, a1);
  }

} } }

#endif
