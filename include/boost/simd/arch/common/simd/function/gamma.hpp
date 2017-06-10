//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GAMMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GAMMA_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/arch/common/detail/generic/gamma_kernel.hpp>

#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/logpi.hpp>
#include <boost/simd/constant/logsqrt2pi.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/two.hpp>

#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/is_even.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_lez.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/function/if_neg.hpp>
#include <boost/simd/function/sinpi.hpp>
#include <boost/simd/function/sqr.hpp>

#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  namespace bs = boost::simd;
  template < typename A>
  A large_negative(const A& q) BOOST_NOEXCEPT
  {
    A st =  bs::stirling(q);
    A p = bs::floor(q);
    A sgngam = bs::if_neg(bs::is_even(p), One<A>());
    A z = q - p;
    auto test2 = is_less(z, bs::Half<A>() );
    z = bs::if_dec(test2, z);
    z = q*bs::sinpi(z);
    z =  bs::abs(z);
    return sgngam*bs::Pi<A>()/(z*st);
  }

  template < typename A, typename B>
  static A other(const A& q, const B& test) BOOST_NOEXCEPT
  {
    A x =  bs::if_else(test, Two<A>(), q);
#ifndef BOOST_SIMD_NO_INFINITIES
    auto inf_result = is_equal(q, Inf<A>());
    x = if_else(inf_result, Two<A>(), x);
#endif
    A z = bs::One<A>();
    auto test1 = is_greater_equal(x,Three<A>());
    while( bs::any(test1) )
    {
      x = bs::if_dec(test1, x);
      z = bs::if_else(   test1, z*x, z);
      test1 = is_greater_equal(x,Three<A>());
    }
    //all x are less than 3
    test1 = bs::is_ltz(x);
    while( bs::any(test1) )
    {
      z = bs::if_else(test1, z/x, z);
      x = bs::if_inc(test1, x);
      test1 = bs::is_ltz(x);
    }
    //all x are greater than 0 and less than 3
    auto test2 = is_less(x,bs::Two<A>());
    while( bs::any(test2))
    {
      z = bs::if_else(test2, z/x, z);
      x = bs::if_inc(test2, x);
      test2 = is_less(x,bs::Two<A>());
    }
    //all x are greater equal 2 and less than 3
    x = z*detail::gamma_kernel<A>::gamma1(x-bs::Two<A>());
#ifndef BOOST_SIMD_NO_INFINITIES
    return if_else(inf_result, q, x);
#else
    return x;
#endif
  }

  template<typename T, std::size_t N
           , typename =  typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T,N> gamma_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    auto nan_result = logical_and(is_ltz(a0), is_flint(a0));
#ifndef BOOST_SIMD_NO_INVALIDS
    nan_result = logical_or(bs::is_nan(a0), nan_result);
#endif
    p_t q = bs::abs(a0);
    auto test = is_less(a0, p_t(-33.0));
    std::size_t nb = bs::nbtrue(test);
    p_t r =  Nan<p_t>();
    if(nb > 0)
    {
      //treat negative large with reflection
      r = detail::large_negative(q);
      if (nb >= p_t::static_size)
        return bs::if_nan_else(nan_result, r);
    }
    p_t r1 = detail::other(a0, test);
    p_t r2 = if_else(test, r, r1);
    return bs::if_else(is_eqz(a0), copysign(Inf<p_t>(), a0), bs::if_nan_else(nan_result, r2));
  }

  // Emulated implementation
  template<typename T, std::size_t N
           , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_>
  gamma_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT
  {
    return map_to(simd::gamma, a);
  }

  // std deecorator
  template<typename T, std::size_t N
           , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE
  pack<double,N,simd_emulation_>
  gamma_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<double,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT
  {
    return map_to(std_(gamma), a);
  }
} } }


#endif
