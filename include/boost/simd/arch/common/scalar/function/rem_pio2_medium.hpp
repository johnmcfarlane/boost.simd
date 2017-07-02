//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REM_PIO2_MEDIUM_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REM_PIO2_MEDIUM_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/detail/constant/pio2_1.hpp>
#include <boost/simd/detail/constant/pio2_1t.hpp>
#include <boost/simd/detail/constant/pio2_2.hpp>
#include <boost/simd/detail/constant/pio2_2t.hpp>
#include <boost/simd/detail/constant/pio2_3.hpp>
#include <boost/simd/detail/constant/pio2_3t.hpp>
#include <boost/simd/constant/twoopi.hpp>
#include <boost/simd/function/quadrant.hpp>
#include <utility>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename Arch>
  BOOST_FORCEINLINE   std::pair<T, T>
  rem_pio2_medium_(BOOST_SIMD_SUPPORTS(Arch)
                  , T const& t) BOOST_NOEXCEPT
  {
    T fn = nearbyint(t*Twoopi<T>());
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
    return  {quadrant(fn), r-w};
  }

} } }

#endif
