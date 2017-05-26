//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_NBMANTISSABITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_CONSTANT_NBMANTISSABITS_HPP_INCLUDED

#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename Type>
  BOOST_FORCEINLINE  bd::as_integer_t<Type> nbmantissabits_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
  {
    using iType = bd::as_integer_t<Type>;
    return iType(23);
  }

  template<typename Type>
  BOOST_FORCEINLINE  bd::as_integer_t<Type> nbmantissabits_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
  {
    using iType =  bd::as_integer_t<Type>;
    return iType(52);
  }

  template<typename Type, typename Value>
  BOOST_FORCEINLINE Type nbmantissabits_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
  {
    return Type(0);
  }

  template<typename Type, typename Arch>
  BOOST_FORCEINLINE auto nbmantissabits_ ( BOOST_SIMD_SUPPORTS(Arch)
                                         , as_<Type> const& tgt
                                         ) BOOST_NOEXCEPT ->  decltype(nbmantissabits_( tgt, as_<detail::value_type_t<Type>>{}))
  {
    using base = detail::value_type_t<Type>;
    return nbmantissabits_( tgt, as_<base>{});
  }
} } }

#endif
