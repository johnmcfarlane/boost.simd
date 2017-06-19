//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MULTIPLIES_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/saturate.hpp>
#include <boost/simd/detail/dispatch/meta/upgrade.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  // regular case
  template<typename T >
  BOOST_FORCEINLINE T
  multiplies_(BOOST_SIMD_SUPPORTS(cpu_)
             , T a0
             , T a1) BOOST_NOEXCEPT
  {
    return a0*a1;
  }

  // saturated cases
  BOOST_FORCEINLINE std::int32_t
  multiplies_(BOOST_SIMD_SUPPORTS(cpu_)
             , const saturated_tag &
             , std::int32_t a0
             , std::int32_t a1
             ) BOOST_NOEXCEPT
  {
      using un_t =std::uint32_t;
      using up_t = std::int64_t;

      up_t res = up_t(a0)*up_t(a1);
      un_t res2 = (un_t(a0 ^ a1) >> (sizeof(std::int32_t)*CHAR_BIT-1)) + Valmax<std::int32_t>();

      std::int32_t hi = (res >> sizeof(std::int32_t)*CHAR_BIT);
      std::int32_t lo = res;

      if(hi != (lo >> (sizeof(std::int32_t)*CHAR_BIT-1)))
        res = res2;

      return res;
  }

  BOOST_FORCEINLINE std::int64_t
  multiplies_(BOOST_SIMD_SUPPORTS(cpu_)
             , const saturated_tag &
             , std::int64_t a0
             , std::int64_t a1) BOOST_NOEXCEPT
  {
    using un_t = std::uint64_t;
    if (a1 == 0 || a0 == 0) return Zero<std::int64_t>();
    auto sgn =  bitwise_xor(bitofsign(a0), bitofsign(a1));
    un_t aa0 = simd::abs(a0);
    un_t aa1 = simd::abs(a1);
    if (aa1 >= aa0)
    {
      un_t z = Valmax<std::int64_t>()/aa1;
      return (z < aa0)
        ? ( sgn ? Valmin<std::int64_t>():Valmax<std::int64_t>())
        : a0*a1;
    }
    else
    {
      un_t z = Valmax<std::int64_t>()/aa0;
      return (z < aa1)
        ? ( sgn ? Valmin<std::int64_t>():Valmax<std::int64_t>())
        : a0*a1;
    }
  }

  BOOST_FORCEINLINE std::uint64_t
  multiplies_(BOOST_SIMD_SUPPORTS(cpu_)
             , const saturated_tag &
             , std::uint64_t a0
             , std::uint64_t a1) BOOST_NOEXCEPT
  {
    if (a1 == 0 || a0 == 0) return Zero<std::uint64_t>();
    if (a1 >= a0)
    {
      std::uint64_t z = Valmax<std::uint64_t>()/a1;
      return (z < a0) ? Valmax<std::uint64_t>() : a0*a1;
    }
    else
    {
      std::uint64_t z = Valmax<std::uint64_t>()/a0;
      return (z < a1) ? Valmax<std::uint64_t>() : a0*a1;
    }
  }


  template<typename T>
  BOOST_FORCEINLINE T
  smultiplies_( T a0
              , T a1
              , case_<2> const&) BOOST_NOEXCEPT //unsigned
  {
    using up_t =  bd::upgrade_t<T>;
    up_t res = up_t(a0)*up_t(a1);
    return static_cast<T>(res) | genmask(static_cast<T>(res >> sizeof(T)*CHAR_BIT));
  }


  template<typename T>
  BOOST_FORCEINLINE T
  smultiplies_( T a0
              , T a1
              , case_<0> const&) BOOST_NOEXCEPT //floating
  {
    return a0*a1;
  }

  template<typename T>
  BOOST_FORCEINLINE T
  smultiplies_( T a0
              , T a1
              , case_<1> const&) BOOST_NOEXCEPT //signed integral
  {
    using up_t =  bd::upgrade_t<T>;
    return T(saturate<T>(static_cast<up_t>(a0)*static_cast<up_t>(a1)));
  }


  template<typename T>
  BOOST_FORCEINLINE T
  multiplies_(BOOST_SIMD_SUPPORTS(cpu_)
             , const saturated_tag &
             , T a0
             , T a1) BOOST_NOEXCEPT
  {
    return smultiplies_(a0, a1, fsu_picker<T>());
  }

} } }

#endif
