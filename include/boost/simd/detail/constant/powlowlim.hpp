//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_POWLOWLIM_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_POWLOWLIM_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant powlowlim

    @par Semantic:

    @code
    T r = powlowlim<T>();
    @endcode


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type powlowlim_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0XC5160000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type powlowlim_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0XC0D0C7C000000000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type powlowlim_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type powlowlim_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return powlowlim_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(powlowlim_, powlowlim);

  template<typename T>
  BOOST_FORCEINLINE T Powlowlim(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return powlowlim( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Powlowlim() BOOST_NOEXCEPT
  {
    return powlowlim( boost::simd::as_<T>{} );
  }
} }

#endif
