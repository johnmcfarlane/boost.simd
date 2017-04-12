//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_META_VALUE_TYPE_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_META_VALUE_TYPE_HPP_INCLUDED

#include <boost/core/enable_if.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename Type, typename Enable = void>
  struct value_type
  {
    using type = Type;
  };

  template<typename Type>
  struct value_type<Type, typename boost::enable_if_has_type<typename Type::value_type>::type>
  {
    using type = typename Type::value_type;
  };

  template<typename Type>
  using value_type_t = typename value_type<Type>::type;
} } }

#endif
