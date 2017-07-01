//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ACOS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ACOS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/detail/constant/pio_2lo.hpp>
#include <boost/simd/arch/common/detail/simd/f_invtrig.hpp>
#include <boost/simd/arch/common/detail/simd/d_invtrig.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/config.hpp>
#include <boost/simd/meta/is_pack.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> acos_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    //Exhaustive test for: acos_, sse4_2_>
    //             versus: raw_acos
    //             With T: boost::simd::pack<float, 4ul, boost::simd::sse_>
    //           in range: [-1, 1]
    //         # of tests: 2130706432

    //2130706432/2130706432 values computed.
    // 1967049938 values (92.32%) within 0.0 ULPs
    //  163364747 values (99.99%) within 0.5 ULPs in range [-9.999999404e-01, 9.999991655e-01]. Example: -9.999999404e-01 returns 3.141247511e+00 instead of 3.141247272e+00
    //     252025 values (100.00%)  within 1.0 ULPs in range [8.775838017e-01, 9.999970198e-01]. Example: 8.775838017e-01 returns 4.999974966e-01 instead of 4.999974072e-01
    //      32464 values (100.00%)  within 2.0 ULPs in range [9.922016263e-01, 9.999964833e-01]. Example: 9.922016263e-01 returns 1.249682903e-01 instead of 1.249682382e-01
    //       5800 values (100.00%)  within 4.0 ULPs in range [9.980521798e-01, 9.999993443e-01]. Example: 9.980521798e-01 returns 6.242525578e-02 instead of 6.242519990e-02
    //       1148 values (100.00%)  within 8.0 ULPs in range [9.995126724e-01, 9.999985695e-01]. Example: 9.995126724e-01 returns 3.122079372e-02 instead of 3.122073598e-02
    //        238 values (100.00%)  within 16.0 ULPs  in range [9.998818040e-01, 9.999994636e-01]. Example: 9.998818040e-01 returns 1.537525654e-02 instead of 1.537519693e-02
    //         58 values (100.00%)  within 32.0 ULPs  in range [9.999715686e-01, 9.999995828e-01]. Example: 9.999715686e-01 returns 7.540822029e-03 instead of 7.540762424e-03
    //          9 values (100.00%)  within 64.0 ULPs  in range [9.999928474e-01, 9.999991059e-01]. Example: 9.999928474e-01 returns 3.782153130e-03 instead of 3.782212501e-03
    //          4 values (100.00%)  within 128.0 ULPs in range [9.999996424e-01, 9.999998212e-01]. Example: 9.999996424e-01 returns 8.456707001e-04 instead of 8.457279764e-04
    //          1 values (100.00%)  within 256.0 ULPs in range [9.999999404e-01, 9.999999404e-01]. Example: 9.999999404e-01 returns 3.452301025e-04 instead of 3.452669771e-04
    using p_t = pack<T,N>;
    return Pio_2<p_t>()-invtrig_base<p_t,tag::radian_tag,is_pack_t<p_t>>::asin(a);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> acos_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::acos, a);
  }

  //================================================================================================
  // pedantic_ decorator

  // Native implementation
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> acos_( BOOST_SIMD_SUPPORTS(simd_)
                   , pedantic_tag const&
                   , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    //Exhaustive test for: boost::simd::detail::decorated_functor<boost::simd::tag::acos_, boost::simd::sse4_2_, boost::simd::pedantic_tag>
    //             versus: raw_acos
    //             With T: boost::simd::pack<float, 4ul, boost::simd::sse_>
    //           in range: [-1, 1]
    //         # of tests: 2130706432

    //2130706432/2130706432 values computed.
    //1968259973 values (92.38%)  within 0.0 ULPs
    // 162446459 values (7.62%) within 0.5 ULPs in range [-9.999999404e-01, 9.999996424e-01]. Example: -9.999999404e-01 returns 3.141247511e+00 instead of 1.570796251e+00
    using p_t = pack<T,N>;
    return invtrig_base<p_t,tag::radian_tag,is_pack_t<p_t>>::acos(a);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> acos_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pedantic_tag const&
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(pedantic_(simd::acos), a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> acos_( BOOST_SIMD_SUPPORTS(simd_)
                   , std_tag const&
                   , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::acos), a);
  }

} } }

#endif
