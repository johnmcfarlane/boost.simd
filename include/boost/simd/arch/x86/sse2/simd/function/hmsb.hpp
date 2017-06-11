//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_HMSB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_HMSB_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/bitset.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>


namespace boost { namespace simd { namespace detail
{
  namespace bs = boost::simd;

  template < typename T>
  BOOST_FORCEINLINE
  bs::bitset<16> hmsb_ ( BOOST_SIMD_SUPPORTS(sse2_)
                      , pack<T,16,sse_> const& a0
                      ) BOOST_NOEXCEPT
  {
    return _mm_movemask_epi8(a0);
  }

  BOOST_FORCEINLINE
  bs::bitset<2> hmsb_ ( BOOST_SIMD_SUPPORTS(sse2_)
                      , pack<double,2,sse_> const& a0
                      ) BOOST_NOEXCEPT
  {
    return _mm_movemask_pd(a0);
  }

  template < typename T, std::size_t N,
             typename = typename std::enable_if<std::is_integral<T>::value && (sizeof(T) > 2)>::type
  >
  BOOST_FORCEINLINE
  bs::bitset<N> hmsb_ ( BOOST_SIMD_SUPPORTS(sse2_)
                      , pack<T,N,sse_> const& a0
                      ) BOOST_NOEXCEPT
  {
   using p_t = pack<T,N,sse_>;
    return hmsb(bitwise_cast<f_t<p_t>>(a0));
  }


} } }

#endif
