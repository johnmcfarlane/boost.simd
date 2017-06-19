//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/function/is_not_equal.hpp>
#include <boost/simd/detail/meta/size_picker.hpp>

namespace boost { namespace simd { namespace detail
{
 BOOST_FORCEINLINE pack<double,2,sse_>
 multiplies_( BOOST_SIMD_SUPPORTS(sse2_)
            , pack<double,2,sse_> const& a0
            , pack<double,2,sse_> const& a1
            ) BOOST_NOEXCEPT
 {
   return _mm_mul_pd(a0,a1);
 }


  template < class T, std::size_t N> // 64bit
  BOOST_FORCEINLINE
  pack<T,N,sse_> vi_multiplies_ ( pack<T,N,sse_> const& a0
                                   , pack<T,N,sse_> const& a1
                                   , case_<0> const &
                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::multiplies, a0, a1);
  }

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"
#endif // __clang__
  template < class T, std::size_t N> // 32bit
  BOOST_FORCEINLINE
  pack<T,N,sse_> vi_multiplies_ ( pack<T,N,sse_> const& a0
                                , pack<T,N,sse_> const& a1
                                , case_<1> const &
                                ) BOOST_NOEXCEPT
  {
    return _mm_or_si128(
      _mm_and_si128(
        _mm_mul_epu32(a0,a1),
        _mm_setr_epi32(0xffffffff,0,0xffffffff,0)
      )
      , _mm_slli_si128(
        _mm_and_si128(
          _mm_mul_epu32( _mm_srli_si128(a0,4)
                       , _mm_srli_si128(a1,4)
                       )
          , _mm_setr_epi32(0xffffffff,0,0xffffffff,0)
        )
        , 4
      )
    );
  }

#ifdef __clang__
#pragma clang diagnostic pop
#endif // __clang__


  template < class T, std::size_t N> // 16bit
  BOOST_FORCEINLINE
  pack<T,N,sse_> vi_multiplies_ ( pack<T,N,sse_> const& a0
                                , pack<T,N,sse_> const& a1
                                , case_<2> const &
                                ) BOOST_NOEXCEPT
  {
    return _mm_mullo_epi16(a0, a1);
  }

  template < class T, std::size_t N> // 8bit
  BOOST_FORCEINLINE
  pack<T,N,sse_> vi_multiplies_ ( pack<T,N,sse_> const& a0
                                , pack<T,N,sse_> const& a1
                                , case_<3> const &
                                ) BOOST_NOEXCEPT
  {
    using i16_t = std::int16_t;
    i16_t mask = Constant<i16_t,0x00FF>();
    return _mm_or_si128 ( _mm_and_si128(mask, _mm_mullo_epi16(a0,a1))
                        , _mm_slli_epi16
                          ( _mm_and_si128 ( mask
                                          , _mm_mullo_epi16
                                            ( _mm_srli_epi16(a0, 8)
                                            , _mm_srli_epi16(a1, 8)
                                            )
                                          )
                          , 8
                          )
                        );
  }


  template < typename T, std::size_t N >
  typename std::enable_if<std::is_integral<T>::value && (sizeof(T) <  8), pack<T,N,sse_>>::type
  multiplies_ ( BOOST_SIMD_SUPPORTS(sse2_)
              , pack<T,N,sse_> const& a0
              , pack<T,N,sse_> const& a1
              ) BOOST_NOEXCEPT

  {
    return vi_multiplies_(a0, a1, size_picker<T>());
  }


  //saturated decorator
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  multiplies_ ( BOOST_SIMD_SUPPORTS(sse2_)
              , saturated_tag const&, pack<T,N> const& a
              , pack<T,N> const& b
              ) BOOST_NOEXCEPT
  {
    return map_to (saturated_(multiplies), a, b);
  }


  BOOST_FORCEINLINE pack<std::int32_t,4,sse_>
  multiplies_( BOOST_SIMD_SUPPORTS(sse2_)
             , saturated_tag const &
             , pack<std::int32_t,4,sse_> const& a0
             , pack<std::int32_t,4,sse_> const& a1
             ) BOOST_NOEXCEPT
  {
      using p_t  = pack<std::int32_t, 4, sse_>;
      using u_t = pack<std::uint32_t, 4, sse_>;
      using up_t = pack<std::int64_t, 2, sse_>;

      up_t res0, res1;
      std::tie(res0, res1) = split_multiplies(a0, a1);

      u_t res2 = shift_right(bitwise_cast<u_t>(a0 ^ a1), 4*CHAR_BIT-1) + Valmax<std::int32_t>() ;
      p_t hi = group( shift_right(res0, 4*CHAR_BIT)
                    , shift_right(res1, 4*CHAR_BIT)
                    );
      p_t lo = group(res0, res1);

      return if_else( hi == shift_right(lo, 4*CHAR_BIT-1)
                    , lo
                    , bitwise_cast<p_t>(res2)
                    );
  }

  BOOST_FORCEINLINE pack<std::uint32_t,4,sse_>
  multiplies_( BOOST_SIMD_SUPPORTS(sse2_)
             , saturated_tag const &
             , pack<std::uint32_t,4,sse_> const& a0
             , pack<std::uint32_t,4,sse_> const& a1
             ) BOOST_NOEXCEPT
  {
    using up_t = pack<std::uint64_t, 2, sse_>;
    up_t res0, res1;
    std::tie(res0, res1) = split_multiplies(a0, a1);

    return group(res0, res1)
      | genmask( group( shift_right(res0, 4*CHAR_BIT)
                      , shift_right(res1, 4*CHAR_BIT)
                      )
               );

  }

} } }


#endif
