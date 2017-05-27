//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ASEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ASEC_HPP_INCLUDED

#include <boost/simd/constant/constant.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/detail/constant/pio_2lo.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/acsc.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  double asec_(BOOST_SIMD_SUPPORTS(cpu_)
              , double const& a) BOOST_NOEXCEPT
  {
    if (is_equal(a, One<double>())) return Zero<double>();
    return (Pio_2<double>()-acsc(a)) + Pio_2lo<double>();
  }

  BOOST_FORCEINLINE
  float asec_(BOOST_SIMD_SUPPORTS(cpu_)
             , float const& a) BOOST_NOEXCEPT
  {
    float ax =  bs::abs(a);
    if (ax <  One<float>()) return Nan<float>();
    float ax1 =  dec(ax);

    if (ax1 < 0.001f)
    {
      float tmp = sqrt(Two<float>()*ax1)
        *oneminus(ax1*(Ratio<float, 5, 12>()
                       +ax1*(Ratio<float, 43, 160>()
                             -ax1*(Ratio<float, 177, 896>()
                                   +ax1*Ratio<float, 2867, 18432>()
                                  )
                            )
                      )
                 );

      return (is_ltz(a)) ? Pi<float>()-tmp : tmp;
    }

    if (is_equal(a, One<float>())) return Zero<float>();
    return  (Pio_2<float>()-acsc(a));
  }

} } }


#endif
