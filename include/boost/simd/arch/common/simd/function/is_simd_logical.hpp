//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_SIMD_LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_SIMD_LOGICAL_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>


namespace boost { namespace simd { namespace detail
{
 //================================================================================================
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool vis_simd_logical_( pack<T,N> const& a0
                        , std::true_type const &) BOOST_NOEXCEPT
  {
    return is_simd_logical(bitwise_cast<as_si_t<pack<T, N>>>(a0));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool vis_simd_logical_( pack<T,N> const& a0
                        , std::false_type const &) BOOST_NOEXCEPT
  {
    return bs::all(logical_or(is_equal(a0, Allbits<pack<T, N>>()), is_eqz(a0)));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool is_simd_logical_(BOOST_SIMD_SUPPORTS(simd_)
                       , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return vis_simd_logical_(a0, std::is_floating_point<T>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool is_simd_logical_(BOOST_SIMD_SUPPORTS(simd_)
                       , as_logical_t<pack<T,N>> const& ) BOOST_NOEXCEPT
  {
    return true;
  }

} } }

#endif

