//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_META_SIZE_PICKER_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_META_SIZE_PICKER_HPP_INCLUDED

#include <boost/simd/detail/meta/pick.hpp>
#include <boost/simd/config.hpp>
#include <boost/simd/detail/nsm.hpp>

namespace boost { namespace simd { namespace detail
{

  template < typename T > using is_ge64 = nsm::bool_<sizeof(T) >= 8>;
  template < typename T > using is_ge32 = nsm::bool_<sizeof(T) >= 4>;
  template < typename T > using is_ge16 = nsm::bool_<sizeof(T) >= 2>;
  template < typename T > using is_ge8  = nsm::bool_<sizeof(T) >= 1>;
  template<typename T>
  using size_picker = typename detail::pick< T
                                          , is_ge64, is_ge32, is_ge16, is_ge8
                                          >::type;
} } }

#endif
