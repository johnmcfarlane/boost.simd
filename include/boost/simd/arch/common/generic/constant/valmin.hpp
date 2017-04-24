//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_VALMIN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_VALMIN_HPP_INCLUDED

#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename Type>
  BOOST_FORCEINLINE Type valmin_( as_<Type> const&, std::true_type const& ) BOOST_NOEXCEPT
  {
    using base = detail::value_type_t<Type>;
    return Type(-std::numeric_limits<base>::max());
  }

  template<typename Type>
  BOOST_FORCEINLINE Type valmin_( as_<Type> const&, std::false_type const& ) BOOST_NOEXCEPT
  {
    using base = detail::value_type_t<Type>;
    return Type(std::numeric_limits<base>::min());
  }

  template<typename Type, typename Arch>
  BOOST_FORCEINLINE Type valmin_(BOOST_SIMD_SUPPORTS(Arch), as_<Type> const& tgt) BOOST_NOEXCEPT
  {
    using base = detail::value_type_t<Type>;
    return valmin_( tgt, std::is_floating_point<base>{});
  }
} } }

#endif
