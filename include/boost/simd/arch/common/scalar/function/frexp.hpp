//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FREXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FREXP_HPP_INCLUDED

#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/config.hpp>
#include <utility>
#include <cmath>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
 // regular case
  template<typename T>
  BOOST_FORCEINLINE std::pair<T, T>
  frexp_(BOOST_SIMD_SUPPORTS(cpu_)
        , T a0) BOOST_NOEXCEPT
  {
    using p_t = std::pair<T, as_si_t<T>>;
    p_t that = ifrexp(a0);
    return {that.first, T(that.second)};
  }

  // pedantic case
  template<typename T>
  BOOST_FORCEINLINE std::pair<T, T>
  frexp_(BOOST_SIMD_SUPPORTS(cpu_)
        , pedantic_tag const &
        , T a0) BOOST_NOEXCEPT
  {
    using p_t = std::pair<T, as_si_t<T>>;
    p_t that = pedantic_(ifrexp)(a0);
    return {that.first, T(that.second)};
  }

  // raw case
  template<typename T>
  BOOST_FORCEINLINE std::pair<T, T>
  frexp_(BOOST_SIMD_SUPPORTS(cpu_)
        , raw_tag const &
        , T a0) BOOST_NOEXCEPT
  {
    using p_t = std::pair<T, as_si_t<T>>;
    p_t  that = raw_(ifrexp)(a0);
    return {that.first, T(that.second)};
  }

  // std case
  template<typename T>
  BOOST_FORCEINLINE std::pair<T, T>
  frexp_(BOOST_SIMD_SUPPORTS(cpu_)
        , std_tag const &
        , T a0) BOOST_NOEXCEPT
  {
    using p_t = std::pair<T, as_si_t<T>>;
    p_t that =std_(ifrexp)(a0);
    return {that.first, T(that.second)};
  }

} } }

#endif
