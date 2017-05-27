//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ATAN2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ATAN2_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/arch/common/detail/simd/f_invtrig.hpp>
#include <boost/simd/arch/common/detail/simd/d_invtrig.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/negatenz.hpp>
#include <boost/simd/function/rec.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/copysign.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/logical_and.hpp>
#endif

#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/if_allbits_else.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/logical_or.hpp>
#endif

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // regular cases
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> atan2_ ( BOOST_SIMD_SUPPORTS(simd_)
                                     , pack<T,N> const& a0
                                     , pack<T,N> const& a1
                                     ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T, N>;
    p_t q = bs::abs(a0/a1);
    p_t z = detail::invtrig_base<p_t,tag::radian_tag, tag::simd_type>::kernel_atan(q, rec(q));
    return bs::if_else(bs::is_positive(a1), z, bs::Pi<p_t>()-z)* signnz(a0);
  }

  // -----------------------------------------------------------------------------------------------
  // pedantic case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> atan2_(  BOOST_SIMD_SUPPORTS(simd_)
                                    , pedantic_tag const&
                                    , pack<T,N> const& a0
                                    , pack<T,N> const& a1
                                    ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T, N>;
    p_t a00 = a0, a10 = a1;
#ifndef BOOST_SIMD_NO_INFINITIES
    auto test1 =  bs::logical_and(bs::is_inf(a0),  bs::is_inf(a1));
    a00 =  bs::if_else(test1, bs::copysign(One<p_t>(), a00), a00);
    a10 =  bs::if_else(test1, bs::copysign(One<p_t>(), a10), a10);
#endif
    p_t q = bs::abs(a00/a10);
    p_t z = detail::invtrig_base<p_t,tag::radian_tag, tag::simd_type>::kernel_atan(q, rec(q));
    //p_t z = atan(abs(a0/a1));  // case a1 > 0,  a0 > 0
    p_t sgn = signnz(a0);
    z = bs::if_else(bs::is_positive(a10), z, bs::Pi<p_t>()-z)*sgn;
    z = bs::if_else( bs::is_eqz(a00),
                     bs::if_else_zero( bs::is_negative(a10),  bs::Pi<p_t>()*sgn),
                     z);
#ifdef BOOST_SIMD_NO_NANS
    return z;
#else
    return  bs::if_nan_else( bs::logical_or( bs::is_nan(a00),  bs::is_nan(a10)), z);
#endif
  }

  // -----------------------------------------------------------------------------------------------
  // std case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> atan2_(  BOOST_SIMD_SUPPORTS(simd_)
                                    , std_tag const&
                                    , pack<T,N> const& a0
                                    , pack<T,N> const& a1
                                    ) BOOST_NOEXCEPT
  {
    return map_to(std_(atan2), a0, a1);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> atan2_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pack<T,N,simd_emulation_> const& a
                                   , pack<T,N,simd_emulation_> const& b
                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::atan2, a, b);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> atan2_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pedantic_tag const&
                                   , pack<T,N,simd_emulation_> const& a
                                   , pack<T,N,simd_emulation_> const& b
                                   ) BOOST_NOEXCEPT
  {
    return map_to(pedantic_(simd::atan2), a, b);
  }


  //================================================================================================
  // mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T2,M> atan2_ ( BOOST_SIMD_SUPPORTS(simd_)
                    , T1 a
                    , pack<T2,M> const& b
                    ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return simd::atan2(p_t(a), b);
  }

  // mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
           , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T1,N> atan2_ ( BOOST_SIMD_SUPPORTS(simd_)
                    , pack<T1,N> const& a
                    , T2 b
                    ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return simd::atan2(a, p_t(b));
  }

  // pedantic mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T2, M> atan2_ ( BOOST_SIMD_SUPPORTS(simd_)
                     , pedantic_tag const&
                     , T1 a
                     , pack<T2,M> const& b
                     ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return pedantic_(simd::atan2)(p_t(a), b);
  }

  // pedantic mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
           , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T1,N> atan2_ ( BOOST_SIMD_SUPPORTS(simd_)
                    , pedantic_tag const&
                    , pack<T1,N> const& a
                    , T2 b
                    ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return pedantic_(simd::atan2)(a, p_t(b));
  }

} } }

#endif
