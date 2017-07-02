//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IFREXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IFREXP_HPP_INCLUDED

#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/std.hpp>


#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/constant/twotonmb.hpp>
#include <boost/simd/function/is_eqz.hpp>
#endif

#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/std.hpp>

#include <boost/simd/detail/constant/limitexponent.hpp>
#include <boost/simd/detail/constant/mask1frexp.hpp>
#include <boost/simd/detail/constant/mask2frexp.hpp>
#include <boost/simd/detail/constant/maxexponentm1.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_andnot.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/config.hpp>
#include <utility>
#include <cmath>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  template < typename T> using pair_it = std::pair<T, as_si_t<T>>;

  // raw case
  template<typename T>
  BOOST_FORCEINLINE pair_it<T>
  ifrexp_(BOOST_SIMD_SUPPORTS(cpu_)
        , raw_tag const &
         , T a0) BOOST_NOEXCEPT
  {
    using r2_t = as_si_t<T>;
    auto m1f  = Mask1frexp<T>();
    auto r1   = bitwise_cast<r2_t>(bitwise_and(m1f, a0));
    auto    x   = bitwise_andnot(a0, m1f);

    return  pair_it<T>{ bitwise_or(x,Mask2frexp<T>())
        , shr(r1,Nbmantissabits<T>()) - Maxexponentm1<T>()
        };
  }

  // regular case
  template<typename T>
  BOOST_FORCEINLINE pair_it<T>
  ifrexp_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a0) BOOST_NOEXCEPT
  {
    return a0 ? raw_(simd::ifrexp)(a0) : pair_it<T>{0, 0};
  }


  // pedantic case
  template<typename T>
  BOOST_FORCEINLINE pair_it<T>
  ifrexp_(BOOST_SIMD_SUPPORTS(cpu_)
         , pedantic_tag const &
         , T a0) BOOST_NOEXCEPT
  {
    using r2_t = as_si_t<T>;
    if (a0 == 0 || is_invalid(a0))
    {
      return pair_it<T>{a0, 0};
    }
    else
    {
      auto m1f  = Mask1frexp<T>();
      auto nmb  = Nbmantissabits<T>();

      r2_t r1 = simd::bitwise_cast<r2_t>(bitwise_and(m1f, a0));  // extract exp.

#ifndef BOOST_SIMD_NO_DENORMALS
      r2_t t(0);
      if(is_eqz(r1)) // denormal
      {
        a0 *= Twotonmb<T>();
        r1  = simd::bitwise_cast<r2_t>(bitwise_and(m1f, a0));  // extract exp. again
        t   = nmb;
      }
#endif

      T x  = bitwise_andnot(a0, m1f);               // clear exp. in a0
      r1 = shr(r1,nmb)- Maxexponentm1<T>();         // compute exp.
      if (r1 > Limitexponent<T>()) return pair_it<T>{a0, 0};

#ifndef BOOST_SIMD_NO_DENORMALS
      r1 -= t;
#endif

      return {bitwise_or(x,Mask2frexp<T>()), r1};
    }
  }

  template<typename T>
  BOOST_FORCEINLINE pair_it<T>
  ifrexp_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const &
         , T a0) BOOST_NOEXCEPT
  {
    int e(0);
    T r = std::frexp(a0, &e);
    return pair_it<T>{r, e};
  }

} } }

#endif
