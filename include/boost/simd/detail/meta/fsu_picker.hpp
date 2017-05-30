//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_META_FSU_PICKER_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_META_FSU_PICKER_HPP_INCLUDED

#include <boost/simd/detail/meta/pick.hpp>
#include <boost/simd/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  using fsu_picker = typename detail::pick< T
                                          , tt_::is_floating_point, tt_::is_signed, tt_::is_unsigned
                                          >::type;



} } }

#endif
