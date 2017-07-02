//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ILOG2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ILOG2_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/clz.hpp>
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
   template<typename T, std::size_t N>
   BOOST_FORCEINLINE as_i_t<pack<T,N>>
   silog2_( pack<T,N> const & a0, std::true_type const &) BOOST_NOEXCEPT //floating
   {
     return simd::exponent(a0);

   }
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_i_t<pack<T,N>>
  silog2_( pack<T,N> const & a0, std::false_type const &) BOOST_NOEXCEPT //integral
  {
    using pi_t = as_i_t<pack<T,N>>;
    return saturated_(dec)((sizeof(T)*8)-bitwise_cast<pi_t>(clz(a0)));
  }

  // regular
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_i_t<pack<T,N>>
  ilog2_(BOOST_SIMD_SUPPORTS(simd_), pack<T,N> const & a0) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG( assert_all(a0 > 0)
                    , "Logarithm is not defined for zero or negative values." );
    return silog2_(a0, std::is_floating_point<T>());
  }

  // emulation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_i_t<pack<T,N,simd_emulation_>>
  ilog2_(BOOST_SIMD_SUPPORTS(simd_), pack<T,N,simd_emulation_> const & a0) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG( assert_all(a0 > 0)
                    , "Logarithm is not defined for zero or negative values." );
    return map_to(simd::ilog2, a0);
  }

} } }


#endif

