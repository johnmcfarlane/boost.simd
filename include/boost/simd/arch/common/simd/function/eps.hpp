//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EPS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EPS_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/if_plus.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/smallestposval.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> veps_( pack<T,N> const& a0, std::true_type const &) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    using ip_t = bd::as_integer_t<p_t>;
    using sp_t = typename p_t::value_type;

    p_t  a = boost::simd::abs(a0);
    auto e1 = exponent(a)-Nbmantissabits<p_t>();
    p_t  e =  bitwise_cast<p_t>(bitwise_cast<ip_t>(p_t(1))+(shift_left(e1,Nbmantissabits<sp_t>())));

#ifndef BOOST_SIMD_NO_DENORMALS
    return if_plus( is_invalid(a)
                  , if_else(a < Smallestposval<p_t>(), Mindenormal<p_t>(), e)
                  , Nan<p_t>()
                  );
#else
    return if_nan_else(is_invalid(a), e);
#endif
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> veps_( pack<T,N> const& a0, std::false_type const &) BOOST_NOEXCEPT
  {
    return One(as(a0));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> eps_(BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return veps_(a0, std::is_floating_point<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> eps_ ( BOOST_SIMD_SUPPORTS(simd_)
                                 , pack<T,N,simd_emulation_> const& a
                                 ) BOOST_NOEXCEPT
  {
    return map_to(simd::eps, a);
  }

} } }

#endif
