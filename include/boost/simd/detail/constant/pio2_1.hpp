//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_PIO2_1_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_PIO2_1_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Constant used in modular computation involving \f$\pi\f$

    @par Semantic:

    For type T:

    @code
    T r = Pio2_1<T>();
    @endcode

    @return a value of type T

*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type pio2_1_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X3FC90F80U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type pio2_1_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X3FF921FB54400000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type pio2_1_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(1);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type pio2_1_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return pio2_1_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(pio2_1_, pio2_1);

  template<typename T>
  BOOST_FORCEINLINE T Pio2_1(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return pio2_1( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Pio2_1() BOOST_NOEXCEPT
  {
    return pio2_1( boost::simd::as_<T>{} );
  }
} }

#endif
