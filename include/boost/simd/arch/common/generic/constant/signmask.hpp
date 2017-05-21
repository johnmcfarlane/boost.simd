//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_SIGNMASK_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_SIGNMASK_HPP_INCLUDED

#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename Type>
  BOOST_FORCEINLINE Type signmask_( as_<Type> const&, as_<double> const&) BOOST_NOEXCEPT
  {
    return Type{bitwise_cast<double>(0x8000000000000000ULL)};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type signmask_( as_<Type> const&, as_<float> const&) BOOST_NOEXCEPT
  {
    return Type{bitwise_cast<float>(0x80000000U)};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type signmask_( as_<Type> const&, as_<uint8_t> const& ) BOOST_NOEXCEPT
  {
    return Type{0x80U};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type signmask_( as_<Type> const&, as_<uint16_t> const& ) BOOST_NOEXCEPT
  {
    return Type{0x8000U};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type signmask_( as_<Type> const&, as_<uint32_t> const& ) BOOST_NOEXCEPT
  {
    return Type{0x80000000UL};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type signmask_( as_<Type> const&, as_<uint64_t> const& ) BOOST_NOEXCEPT
  {
    return Type{0x8000000000000000ULL};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type signmask_( as_<Type> const&, as_<int8_t> const& ) BOOST_NOEXCEPT
  {
    return Type{-128};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type signmask_( as_<Type> const&, as_<int16_t> const& ) BOOST_NOEXCEPT
  {
    return Type{-32768};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type signmask_( as_<Type> const&, as_<int32_t> const& ) BOOST_NOEXCEPT
  {
    return Type{-2147483648};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type signmask_( as_<Type> const&, as_<int64_t> const& ) BOOST_NOEXCEPT
  {
    return Type{-9223372036854775807LL-1};
  }

  template<typename Type, typename Arch>
  BOOST_FORCEINLINE Type signmask_(BOOST_SIMD_SUPPORTS(Arch), as_<Type> const& tgt) BOOST_NOEXCEPT
  {
    using base = detail::value_type_t<Type>;
    return signmask_( tgt, as_<base>{});
  }
} } }

#endif
