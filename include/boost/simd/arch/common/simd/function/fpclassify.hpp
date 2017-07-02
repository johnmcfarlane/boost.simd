//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FPCLASSIFY_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FPCLASSIFY_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N
          , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE as_si_t<pack<T, N>>
  fpclassify_( BOOST_SIMD_SUPPORTS(simd_)
             , pack<T, N> a
             ) BOOST_NOEXCEPT
  {
    map_to(fpclassify, a)
  }

  template<typename T, std::size_t N
          , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE as_si_t<pack<T, N>>
  fpclassify_( BOOST_SIMD_SUPPORTS(simd_)
             , std_tag const &
             , pack<T, N> a
             ) BOOST_NOEXCEPT
  {
    map_to(std_(fpclassify), a)
  }

} } }

#endif

