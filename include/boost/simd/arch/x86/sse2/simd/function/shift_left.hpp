//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/constant/signmask.hpp>
//#include <boost/simd/detail/make_dependent.hpp>

namespace boost { namespace simd { namespace detail
{
 template < typename T, std::size_t N, typename I> // 64bits
  BOOST_FORCEINLINE
  pack<T,N,sse_> vi_shift_left_ ( pack<T,N,sse_> const& a0
                                , I a1
                                , case_<0> const &
                                ) BOOST_NOEXCEPT
  {
//    BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_left ints64 sse2: a shift is out of range");
    return _mm_slli_epi64(a0, int(a1));
  }

  template < typename T, std::size_t N, typename I > // 32bits
  BOOST_FORCEINLINE
  pack<T,N,sse_> vi_shift_left_ ( pack<T,N,sse_> const& a0
                                , I a1
                                , case_<1> const &
                                ) BOOST_NOEXCEPT
  {
//      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_left ints32 sse2: a shift is out of range");
    return _mm_slli_epi32(a0, int(a1));
  }

  template < typename T, std::size_t N, typename I > // 16bits
  BOOST_FORCEINLINE
  pack<T,N,sse_> vi_shift_left_ ( pack<T,N,sse_> const& a0
                                , I a1
                                , case_<2> const &
                                ) BOOST_NOEXCEPT
  {
//      BOOST_ASSERT_MSG(assert_good_shift<A0>(a1), "shift_left ints16 sse2: a shift is out of range");
    return _mm_slli_epi16(a0, int(a1));
  }

  template < typename T, std::size_t N, typename I > // 8bits
  BOOST_FORCEINLINE
  pack<T,N,sse_> vi_shift_left_ ( pack<T,N,sse_> const& a0
                                , I a1
                                , case_<3> const &
                                ) BOOST_NOEXCEPT
  {
//       using int_t =  detail::make_dependent_t<std::uint16_t,A0>;
//       using gen_t = pack<int_t, A0::static_size/2>;
    using p_t =  pack<T,N,sse_>;
    using int_t = std::uint16_t;
    using gen_t = pack<int_t, N/2, sse_>;
//      BOOST_ASSERT_MSG(assert_good_shift<p_t>(a1), "shift_left ints8 sse2: a shift is out of range");
    p_t const Mask1 = bitwise_cast<p_t>( gen_t(0x00ff));
    p_t const Mask2 = bitwise_cast<p_t>( gen_t(0xff00));
    p_t tmp  = bitwise_and(a0, Mask1);
    p_t tmp1 = _mm_slli_epi16(tmp, int(a1));
    tmp1 = bitwise_and(tmp1, Mask1);
    tmp = bitwise_and(a0, Mask2);
    p_t tmp3 = _mm_slli_epi16(tmp, int(a1));
    return bitwise_or(tmp1, bitwise_and(tmp3, Mask2));
  }

  template < typename T, std::size_t N, typename I>
  typename std::enable_if<std::is_integral<T>::value &&
                          std::is_integral<I>::value, pack<T,N, sse_>>::type
  shift_left_ ( BOOST_SIMD_SUPPORTS(sse2_)
              , pack<T,N,sse_> const& a0
              , I a1
              ) BOOST_NOEXCEPT

  {
    return vi_shift_left_(a0, a1, size_picker<T>());
  }

} } }

#endif
