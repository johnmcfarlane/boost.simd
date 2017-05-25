//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ACOSD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ACOSD_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/acos.hpp>
#include <boost/simd/function/indeg.hpp>
#include <boost/config.hpp>


namespace boost { namespace simd { namespace detail
{
  template<typename T, typename Arch>
  BOOST_FORCEINLINE
  T acosd_(BOOST_SIMD_SUPPORTS(Arch)
                  , T const& a) BOOST_NOEXCEPT
  {
    return indeg(simd::acos(a));
  };
  template<typename T, typename Arch>
  BOOST_FORCEINLINE
  T acosd_(BOOST_SIMD_SUPPORTS(Arch)
                  , const pedantic_tag &
                  , T const& a) BOOST_NOEXCEPT
  {
    return indeg(bs::pedantic_(simd::acos)(a));
  };

} } }


#endif
