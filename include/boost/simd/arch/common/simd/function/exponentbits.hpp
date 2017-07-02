//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPONENTBITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPONENTBITS_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  template<  typename T, std::size_t N
             , typename =  std::enable_if<std::is_floating_point<T>::value>
             >
  BOOST_FORCEINLINE
  as_si_t<pack<T, N>> exponentbits_( BOOST_SIMD_SUPPORTS(simd_)
                                , pack<T,N> const& a0
                                ) BOOST_NOEXCEPT
  {
    using r_t =  as_si_t<pack<T, N>>;
    using s_t =  as_si_t<T>;
    s_t me = Maxexponent<T>();
    s_t nmb= Nbmantissabits<T>();
    r_t mask = r_t((2*me+1)<<nmb);
    return (bitwise_and(mask, a0));
  }

} } }

#endif

