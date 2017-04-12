//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_META_STORAGE_KIND_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_META_STORAGE_KIND_HPP_INCLUDED

#include <boost/core/enable_if.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename Type, typename Enable = void>
  struct storage_kind
  {
    using type = Type;
  };

  template<typename Type>
  struct storage_kind<Type, typename boost::enable_if_has_type<typename Type::storage_kind>::type>
  {
    using type = typename Type::storage_kind;
  };

  template<typename Type>
  using storage_kind_t = typename storage_kind<Type>::type;
} } }

#endif
