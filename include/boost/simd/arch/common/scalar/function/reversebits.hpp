//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REVERSEBITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REVERSEBITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/detail/meta/size_picker.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE T
  s_reversebits_(T a0
                , detail::case_<0> const&) BOOST_NOEXCEPT // 64bits
  {
    union { T a; std::uint32_t b[2]; } z = {a0};
    z.b[0] = reversebits(z.b[0]);
    z.b[1] = reversebits(z.b[1]);
    std::swap(z.b[0], z.b[1]);
    return z.a;
  }

  template<typename T>
  BOOST_FORCEINLINE T
  s_reversebits_(T a0
                , detail::case_<1> const&) BOOST_NOEXCEPT // 32bits
  {
    union { T a; std::uint16_t b[2]; } z = {a0};
    z.b[0] = reversebits(z.b[0]);
    z.b[1] = reversebits(z.b[1]);
    std::swap(z.b[0], z.b[1]);
    return z.a;
  }

  template<typename T>
  BOOST_FORCEINLINE T
  s_reversebits_(T a0
                , detail::case_<2> const&) BOOST_NOEXCEPT // 16bits
  {
    union { T a; std::uint8_t b[2]; } z = {a0};
    z.b[0] = reversebits(z.b[0]);
    z.b[1] = reversebits(z.b[1]);
    std::swap(z.b[0], z.b[1]);
    return  z.a;
  }
  template<typename T>
  BOOST_FORCEINLINE T
  s_reversebits_(T a0
                , detail::case_<3> const&) BOOST_NOEXCEPT // 8bits
  {
    return T(
      ((uint8_t(a0) * 0x0802LU & 0x22110LU)
       | (uint8_t(a0) * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16
    );
  }

  template<typename T
           , typename =  typename std::enable_if<std::is_integral<T>::value>::type
  >
  BOOST_FORCEINLINE T
  reversebits_( BOOST_SIMD_SUPPORTS(cpu_)
              , T a0) BOOST_NOEXCEPT
  {
    return s_reversebits_(a0, size_picker<T>());
  }

} } }


#endif
