//==================================================================================================
/**
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TOINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TOINT_HPP_INCLUDED

#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/is_nan.hpp>
#endif
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/saturate.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  as_si_t<T> s_toint_( T a0
           , std::true_type const &) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T >
  BOOST_FORCEINLINE
  as_si_t<T> s_toint_( T a0
           , std::false_type) BOOST_NOEXCEPT
  {
   return a0;
  }

  template<typename T>
  BOOST_FORCEINLINE
  as_si_t<T> toint_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a) BOOST_NOEXCEPT
  {
    return s_toint_(a, std::is_floating_point<T>());
  }

  //================================================================================================
  // saturated_ decorator
  template<typename T>  //floating
  BOOST_FORCEINLINE as_si_t<T>
  s_toint_(T a0
          , detail::case_<0> const&) BOOST_NOEXCEPT
  {
    using r_t =  as_si_t<T>;
#ifndef BOOST_SIMD_NO_NANS
      if (simd::is_nan(a0)) return Zero<r_t>();
#endif
    if (a0 >= Valmax<r_t>()) return Valmax<r_t>();
    if (a0 <= Valmin<r_t>()) return Valmin<r_t>();
    return r_t(a0);
  }

  template<typename T>         //signed
  BOOST_FORCEINLINE as_si_t<T>
  s_toint_(T a
          , detail::case_<1> const&) BOOST_NOEXCEPT
  {
    return a;
  }

  template<typename T>
  BOOST_FORCEINLINE as_si_t<T>     //unsigned
  s_toint_(T a
          , detail::case_<2> const&) BOOST_NOEXCEPT
  {
    using r_t =  as_si_t<T>;
    return r_t(saturate<r_t>(a));
  }

  template<typename T>
  BOOST_FORCEINLINE as_si_t<T>
  toint_( BOOST_SIMD_SUPPORTS(cpu_)
        , saturated_tag const&
        , T const& a) BOOST_NOEXCEPT
  {
    return s_toint_(a, fsu_picker<T>{});
  }

} } }



#endif
