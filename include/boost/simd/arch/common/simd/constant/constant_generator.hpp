//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_CONSTANT_CONSTANT_GENERATOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_CONSTANT_CONSTANT_GENERATOR_HPP_INCLUDED

#if defined(BOOST_SIMD_DETECTED)
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/simd/as.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // this should be auto in C++14 alas we support C++11 for still a bit of time
  template<typename Value, typename Pack> struct constant_return
  {
    using scalar_t  = decltype(simd::constant(Value(),simd::as_<typename Pack::value_type>()));
    using type      = typename Pack::template rebind<scalar_t>;
  };

  template<typename Value, typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE typename constant_return<Value,pack<T,N,X>>::type
  constant_(BOOST_SIMD_SUPPORTS(simd_), Value const& v, as_<pack<T,N,X>> const&) BOOST_NOEXCEPT
  {
    using result_t = typename constant_return<Value,pack<T,N,X>>::type;
    return result_t{ simd::constant(v,as_<T>()) };
  }
} } }

#endif
#endif
