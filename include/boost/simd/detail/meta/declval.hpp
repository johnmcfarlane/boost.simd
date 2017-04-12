//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_META_DECLVAL_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_META_DECLVAL_HPP_INCLUDED

#include <boost/simd/config.hpp>

#ifdef BOOST_SIMD_INCOMPLETE_STD
#  include <boost/utility/declval.hpp>
#else
#  include <utility>
#endif

namespace boost { namespace simd { namespace detail
{
#ifdef BOOST_SIMD_INCOMPLETE_STD
  using boost::declval;
#else
  using std::declval;
#endif
} } }

#endif
