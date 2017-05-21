//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MLOG2TWO2NMB_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MLOG2TWO2NMB_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(mlog2two2nmb_, mlog2two2nmb);

  template<typename T>
  BOOST_FORCEINLINE auto Mlog2two2nmb(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    mlog2two2nmb( tgt )
  )

  template<typename T> BOOST_FORCEINLINE auto Mlog2two2nmb() BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    mlog2two2nmb( boost::simd::as_<T>{} )
  )
} }

#endif
