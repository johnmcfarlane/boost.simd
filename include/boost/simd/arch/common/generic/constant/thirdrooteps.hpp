//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_THIRDROOTEPS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_THIRDROOTEPS_HPP_INCLUDED

#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename Type>
  BOOST_FORCEINLINE Type thirdrooteps_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
  {
    using base = detail::value_type_t<Type>;
    return Type{bitwise_cast<base>(0X3BA14518U)};
  }

  template<typename Type>
  BOOST_FORCEINLINE Type thirdrooteps_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
  {
    using base = detail::value_type_t<Type>;
    return Type{bitwise_cast<base>(0X3ED965FEA53D6E3DULL)};
  }

  template<typename Type, typename Value>
  BOOST_FORCEINLINE Type thirdrooteps_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
  {
    return Type( 1);
  }

  template<typename Type, typename Arch>
  BOOST_FORCEINLINE Type thirdrooteps_ ( BOOST_SIMD_SUPPORTS(Arch)
                                  , as_<Type> const& tgt
                                  ) BOOST_NOEXCEPT
  {
    using base = detail::value_type_t<Type>;
    return thirdrooteps_( tgt, as_<base>{});
  }
} } }

#endif

