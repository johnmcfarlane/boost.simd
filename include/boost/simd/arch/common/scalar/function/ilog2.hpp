//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ILOG2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ILOG2_HPP_INCLUDED

#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/function/clz.hpp>
#include <boost/simd/function/exponent.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  // floating point
  template<typename T> BOOST_FORCEINLINE
  as_si_t<T> silog2_( T a0, std::true_type const&) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG( a0 > 0
                    , "Logarithm is not defined for zero or negative values." );
    return exponent(a0);
  }

#if !defined(BOOST_MSVC)
  //not msvc  integral
  template<typename T> BOOST_FORCEINLINE
  T silog2_( T a0, std::false_type const&) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG( a0 > 0
                    , "Logarithm is not defined for zero or negative values." );
    return T(sizeof(T)*8-simd::clz(a0)-1);
  }
#else
  template<typename T> BOOST_FORCEINLINE //small ints
  T ssilog2_( T a0, std::true_type const&) BOOST_NOEXCEPT
  {
    unsigned long index;
    BOOST_VERIFY(::_BitScanReverse(&index, a0));
    return static_cast<T>(index);
  }
  #if defined(_WIN64) //large int msvc64
  template<typename T> BOOST_FORCEINLINE
  T ssilog2_( T a0, std::false_type const&) BOOST_NOEXCEPT
  {
    unsigned long index;
    BOOST_VERIFY(::_BitScanReverse64(&index, a0));
    return static_cast<T>(index);
  }
  #else //large int msvc32
  template<typename T> BOOST_FORCEINLINE
  T ssilog2_( T a0, std::false_type const&) BOOST_NOEXCEPT
  {
    return T(sizeof(T)*8-simd::clz(a0)-1);
  }

  #endif
  //integral msvc
  template<typename T> BOOST_FORCEINLINE
  T silog2_( T a0, std::false_type const&) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG( a0 > 0
                    , "Logarithm is not defined for zero or negative values." );
    return ssilog2_(a0,  typename nsm::bool_<sizeof(A0) <= 4>::type());
  }
#endif

  template<typename T> BOOST_FORCEINLINE
  auto ilog2_( BOOST_SIMD_SUPPORTS(cpu_)
             , T a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    silog2_(a0, std::is_floating_point<T>())
  )

} } }

#endif
