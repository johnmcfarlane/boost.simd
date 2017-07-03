//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REM_PIO2_CEPHES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REM_PIO2_CEPHES_HPP_INCLUDED

#include <boost/simd/detail/constant/pio2_1.hpp>
#include <boost/simd/detail/constant/pio2_2.hpp>
#include <boost/simd/detail/constant/pio2_3.hpp>
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/function/quadrant.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/config.hpp>
#include <utility>

namespace boost { namespace simd { namespace detail
{
  struct rem_cephes_aux2
  {
    template<typename T>
    BOOST_FORCEINLINE T
    operator()( const T& x, const T& xi) const BOOST_NOEXCEPT
    {
      T xr  = fnms(xi, Pio2_1<T>(), x);
      xr -= xi*Pio2_2<T>();
      xr -= xi*Pio2_3<T>();
      return xr;
    }
  };

  struct rem_cephes_aux1
  {
    template < typename T>
    BOOST_FORCEINLINE T
    operator()(const T & x) const  BOOST_NOEXCEPT
    {
      return nearbyint(x*Twoopi<T>());
    }

  };


  // emulation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE std::pair<pack<T,N,simd_emulation_>, pack<T,N,simd_emulation_>>
  rem_pio2_cephes_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N,simd_emulation_> const& x) BOOST_NOEXCEPT
  {
    T xi =  map_to(rem_cephes_aux1(), x);
    T xr =  map_to(rem_cephes_aux2(), x, xi);
    return { map_to(quadrant, xi), xr};

  }

} } }


#endif
