//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_CONSTANT_CONSTANT_GENERATOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_CONSTANT_CONSTANT_GENERATOR_HPP_INCLUDED

#include <boost/simd/detail/constant_traits.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/as.hpp>
#include <boost/config.hpp>

#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4310) // Truncation
#pragma warning(disable: 4309) // Truncation
#endif

namespace boost { namespace simd { namespace detail
{
  template<typename T, T Value, typename Target>
  BOOST_FORCEINLINE T constant_ ( BOOST_SIMD_SUPPORTS(cpu_)
                                , tt_::integral_constant<T,Value> const&
                                , Target const&
                                ) BOOST_NOEXCEPT
  {
    return Value;
  }

  template<typename R, typename T, T N, typename Target>
  BOOST_FORCEINLINE R constant_ ( BOOST_SIMD_SUPPORTS(cpu_)
                                , nsm::real_<R,T,N> const& value
                                , Target const&
                                ) BOOST_NOEXCEPT
  {
    return static_cast<R>(value);
  }

  template<typename T, std::intmax_t N, std::intmax_t D, typename Target>
  BOOST_FORCEINLINE T constant_ ( BOOST_SIMD_SUPPORTS(cpu_)
                                , detail::ratio<T,N,D>  const&
                                , Target const&
                                ) BOOST_NOEXCEPT
  {
    return static_cast<T>(double(N)/double(D));
  }
} } }

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

#endif
