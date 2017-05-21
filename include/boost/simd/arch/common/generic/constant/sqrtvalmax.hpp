//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_SQRTVALMAX_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_SQRTVALMAX_HPP_INCLUDED

#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename Type>
  BOOST_FORCEINLINE Type sqrtvalmax_( as_<Type> const&, as_<double> const&) BOOST_NOEXCEPT
  {
    return Type{bitwise_cast<double>(0X5FEFFFFFFFFFFFFFULL)};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type sqrtvalmax_( as_<Type> const&, as_<float> const&) BOOST_NOEXCEPT
  {
    return Type{bitwise_cast<float>(0x5f7FFFFEU)};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type sqrtvalmax_( as_<Type> const&, as_<uint8_t> const& ) BOOST_NOEXCEPT
  {
    return Type{15};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type sqrtvalmax_( as_<Type> const&, as_<uint16_t> const& ) BOOST_NOEXCEPT
  {
    return Type{255};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type sqrtvalmax_( as_<Type> const&, as_<uint32_t> const& ) BOOST_NOEXCEPT
  {
    return Type{65535};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type sqrtvalmax_( as_<Type> const&, as_<uint64_t> const& ) BOOST_NOEXCEPT
  {
    return Type{4294967296ULL};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type sqrtvalmax_( as_<Type> const&, as_<int8_t> const& ) BOOST_NOEXCEPT
  {
    return Type{11};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type sqrtvalmax_( as_<Type> const&, as_<int16_t> const& ) BOOST_NOEXCEPT
  {
    return Type{181};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type sqrtvalmax_( as_<Type> const&, as_<int32_t> const& ) BOOST_NOEXCEPT
  {
    return Type{46340};
  }
  template<typename Type>
  BOOST_FORCEINLINE Type sqrtvalmax_( as_<Type> const&, as_<int64_t> const& ) BOOST_NOEXCEPT
  {
    return Type{3037000499LL};
  }

  template<typename Type, typename Arch>
  BOOST_FORCEINLINE Type sqrtvalmax_(BOOST_SIMD_SUPPORTS(Arch), as_<Type> const& tgt) BOOST_NOEXCEPT
  {
    using base = detail::value_type_t<Type>;
    return sqrtvalmax_( tgt, as_<base>{});
  }
} } }

#endif
