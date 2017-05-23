//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BITWISE_AND_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/hierarchy.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  namespace bd = boost::dispatch;

  template<typename T> BOOST_FORCEINLINE
  T simd_bitwise_and_( T const& a, T const& b
                      , tt_::false_type const&, tt_::false_type const& ) BOOST_NOEXCEPT
  {
    return a&b;
  }

  template<typename T1, typename T2> BOOST_FORCEINLINE
  T1 simd_bitwise_and_( T1 const& a, T2 const& b
                      , tt_::true_type const&, tt_::false_type const& ) BOOST_NOEXCEPT
  {
    using b_t = bd::as_integer_t<T1, unsigned>;
    return bitwise_cast<T1>(b_t(bitwise_cast<b_t>(a) & bitwise_cast<b_t>(b)));
  }
  template<typename T> BOOST_FORCEINLINE
  T simd_bitwise_and_( T const& a, T const& b
                      , tt_::false_type const&, tt_::true_type const& ) BOOST_NOEXCEPT
  {
    using b_t = bd::as_integer_t<T, unsigned>;
    return bitwise_cast<T>(b_t(bitwise_cast<b_t>(a) & bitwise_cast<b_t>(b)));
  }

  template<typename T1, typename T2> BOOST_FORCEINLINE
  T1 simd_bitwise_and_( T1 const& a, T2 const& b
                      , tt_::true_type const&, tt_::true_type const& ) BOOST_NOEXCEPT
  {
    using b_t = bd::as_integer_t<T1, unsigned>;
    return bitwise_cast<T1>(b_t(bitwise_cast<b_t>(a) & bitwise_cast<b_t>(b)));
  }


  template<typename T1, typename T2>
  BOOST_FORCEINLINE
  T1 bitwise_and_ ( BOOST_SIMD_SUPPORTS(boost::dispatch::cpu_)
          , T1 const& a, T2 const& b
          ) BOOST_NOEXCEPT
  {
    return simd_bitwise_and_ ( a ,b
                             , nsm::and_< nsm::not_<std::is_same<T1, T2>>
                                        , nsm::bool_<sizeof(T1) == sizeof(T2)>
                                        >{}
                             , std::is_floating_point<T1>{});
  }

} } }

#endif
