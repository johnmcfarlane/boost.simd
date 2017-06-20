//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_IS_LESS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_IS_LESS_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template < typename T,  std::size_t N>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_integral < T>::value
                          , as_logical_t<pack<T,N,avx_>>>::type
  is_greater_( BOOST_SIMD_SUPPORTS(avx2_)
             , pack<T,N,avx_> const& a0
             , pack<T,N,avx_> const& a1
             ) BOOST_NOEXCEPT
  {
    return a1 > a0;
  }

} } }

#endif
