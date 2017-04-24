//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_VALMAX_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_VALMAX_HPP_INCLUDED

#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/as.hpp>
#include <limits>

namespace boost { namespace simd { namespace detail
{
  template<typename Type, typename Arch>
  BOOST_FORCEINLINE Type valmax_( BOOST_SIMD_SUPPORTS(Arch), as_<Type> const& ) BOOST_NOEXCEPT
  {
    using base = detail::value_type_t<Type>;
    return Type(std::numeric_limits<base>::max());
  }
} } }

#endif
