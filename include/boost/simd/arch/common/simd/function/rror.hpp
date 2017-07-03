//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_RROR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_RROR_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/rol.hpp>
#include <boost/simd/function/ror.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_integral<U>::value && std::is_signed<U>::value, pack<T,N>>::type
  v_rror_( pack<T,N> const & a0
         , pack<U,N> const & a1
         , std::true_type const &) BOOST_NOEXCEPT
  {
#ifndef NDEBUG
    auto aa1 = simd::abs(a1);
    return if_else(is_gtz(a1), ror(a0, aa1), rol(a0, aa1));
#else
    return if_else(is_gtz(a1), ror(a0, a1), rol(a0, -a1));
#endif
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_unsigned<U>::value, pack<T,N>>::type
  v_rror_( pack<T,N> const & a0
         , pack<U,N> const & a1
         , std::false_type const &) BOOST_NOEXCEPT
  {
    return  ror(a0, a1);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_integral<U>::value, pack<T,N>>::type
  rror_(BOOST_SIMD_SUPPORTS(simd_)
       , pack<T,N> const & a0
       , pack<U,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    BOOST_ASSERT_MSG(assert_good_rotation<p_t>(a1), "rror : rotation is out of range");
    return v_rror_(a0, a1, std::is_signed<T>());
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_unsigned<U>::value, pack<T,N>>::type
  rror_(BOOST_SIMD_SUPPORTS(simd_)
       , pack<T,N> const & a0
       , U const & a1) BOOST_NOEXCEPT
  {
    return ror(a0, a1);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_signed<U>::value, pack<T,N>>::type
  rror_(BOOST_SIMD_SUPPORTS(simd_)
       , pack<T,N> const & a0
       , U const & a1) BOOST_NOEXCEPT
  {
    return if_else(is_gtz(a1), ror(a0, a1), rol(a0, -a1));
  }


  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_integral<U>::value, pack<T,N>>::type
  rror_(BOOST_SIMD_SUPPORTS(simd_)
       , T const & a0
       , pack<U,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return rror(p_t(a0), a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  rror_(BOOST_SIMD_SUPPORTS(simd_)
       , pack<T,N,simd_emulation_> const & a0
       , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(rror, a0, a1);
  }

} } }

#endif
