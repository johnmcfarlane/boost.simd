//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_META_CONVERT_HELPERS_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_META_CONVERT_HELPERS_HPP_INCLUDED

#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T> using ui_t =  boost::dispatch::as_integer_t<T, unsigned>;
  template<typename T> using  i_t =  boost::dispatch::as_integer_t<T, signed>;
  template<typename T> using  f_t =  boost::dispatch::as_floating<T>;
} } }

#endif
