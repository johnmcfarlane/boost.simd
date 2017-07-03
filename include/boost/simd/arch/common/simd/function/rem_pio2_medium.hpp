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
#include <boost/simd/function/rem_pio2_cephes.hpp>
#include <boost/simd/function/quadrant.hpp>
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/detail/constant/pio2_1.hpp>
#include <boost/simd/detail/constant/pio2_1t.hpp>
#include <boost/simd/detail/constant/pio2_2.hpp>
#include <boost/simd/detail/constant/pio2_2t.hpp>
#include <boost/simd/detail/constant/pio2_3.hpp>
#include <boost/simd/detail/constant/pio2_3t.hpp>
#include <boost/config.hpp>
#include <utility>

namespace boost { namespace simd { namespace detail
{

  struct rem_medium_aux
  {
    template < typename T>
    BOOST_FORCEINLINE T
    operator()(const T & t, const T & fn) const  BOOST_NOEXCEPT
    {
      T r  = t-fn*Pio2_1<T>();
      T w  = fn*Pio2_1t<T>();
      T t2 = r;
      w  = fn*Pio2_2<T>();
      r  = t2-w;
      w  = fn*Pio2_2t<T>()-((t2-r)-w);
      t2 = r;
      w  = fn*Pio2_3<T>();
      r  = t2-w;
      w  = fn*Pio2_3t<T>()-((t2-r)-w);
      return   r-w;
    }
  };

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE std::pair<pack<T,N,simd_emulation_>, pack<T,N,simd_emulation_>>
  rem_pio2_medium_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N,simd_emulation_> const& x) BOOST_NOEXCEPT
  {
    T xi =  map_to(rem_cephes_aux1(), x);
    T xr =  map_to(rem_medium_aux(), x, xi);
    return { map_to(quadrant, xi), xr};
  }

} } }


#endif
