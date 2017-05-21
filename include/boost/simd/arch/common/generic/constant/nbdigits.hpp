//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_NBDIGITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_NBDIGITS_HPP_INCLUDED

#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename Type>
  BOOST_FORCEINLINE  bd::as_integer_t<Type> nbdigits_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
  {
    using iType = bd::as_integer_t<Type>;
    return iType(24);
  }

  template<typename Type>
  BOOST_FORCEINLINE  bd::as_integer_t<Type> nbdigits_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
  {
    using iType =  bd::as_integer_t<Type>;
    return iType(53);
  }

  template<typename Type, typename Value>
  BOOST_FORCEINLINE Type nbdigits_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
  {
    using base = detail::value_type_t<Type>;
    return Type(sizeof(base)*8);
  }

  template<typename Type, typename Arch>
  BOOST_FORCEINLINE auto nbdigits_ ( BOOST_SIMD_SUPPORTS(Arch)
                                         , as_<Type> const& tgt
                                         ) BOOST_NOEXCEPT ->  decltype(nbdigits_( tgt, as_<detail::value_type_t<Type>>{}))
  {
    using base = detail::value_type_t<Type>;
    return nbdigits_( tgt, as_<base>{});
  }
} } }

#endif

