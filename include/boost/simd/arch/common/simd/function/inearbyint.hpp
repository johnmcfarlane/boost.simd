//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INEARBYINT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#endif

#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE auto
  vinearbyint_( pack<T,N> const & a0
         , std::true_type const &) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    toint(simd::nearbyint(a0))
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  vinearbyint_( pack<T,N> const & a0
         , std::false_type const & ) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE auto
  inearbyint_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const & a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    vinearbyint_(a0, std::is_floating_point<T>())
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE auto
  inearbyint_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N,simd_emulation_> const & a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to(inearbyint, a0)
  )

  //pedantic
  template<std::size_t N>
  BOOST_FORCEINLINE pack<std::int64_t, N>
  inearbyint_(BOOST_SIMD_SUPPORTS(simd_)
             , pedantic_tag const &
             , pack<double,N> const & a0) BOOST_NOEXCEPT
  {
    return saturated_(toint)(nearbyint(a0));
  }


  template<std::size_t N>
  BOOST_FORCEINLINE  pack<std::int32_t, N>
  inearbyint_(BOOST_SIMD_SUPPORTS(simd_)
             , pedantic_tag const &
             , pack<float,N> const & a0) BOOST_NOEXCEPT
  {
    using p_t = pack<float,N>;
    using sr_t = std::int32_t;
    using r_t = pack<std::int32_t, N>;
    p_t Vax(simd::Valmax<sr_t>());
    p_t Vix(simd::Valmin<sr_t>());
#ifndef BOOST_SIMD_NO_NANS
    p_t aa0 = if_zero_else(is_nan(a0), a0);
    return if_else(simd::is_less(aa0, Vix), Valmin<r_t>(),
                   if_else(simd::is_greater(aa0, Vax), Valmax<r_t>(),
                           inearbyint(aa0)
                          )
                  );
#else
    return if_else(simd::is_less(a0, Vix), Valmin<r_t>(),
                   if_else(simd::is_greater(a0, Vax), Valmax<r_t>(),
                           inearbyint(a0)
                          )
                  );
#endif
  }


  template<typename T, std::size_t N,
           typename =  typename std::enable_if<std::is_integral<T>::value>::type
  >
  BOOST_FORCEINLINE  pack<T,N>
  inearbyint_(BOOST_SIMD_SUPPORTS(simd_)
             , pedantic_tag const &
             , pack<T,N> const & a0) BOOST_NOEXCEPT
  {
    return a0;
  }

} } }

#endif
