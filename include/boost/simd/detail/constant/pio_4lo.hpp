//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_PIO_4LO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_PIO_4LO_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    This constant is such that, for pairs of types (Tup, T)
    (namely (float,  double) and (double, long double)) the sum:

    abs(Tup(Pio_4lo<T>())+Tup(Pio_4<T>())-Pio_4\<Tup\>())  is  less than
    a few Eps<Tup>().

    This is used to improve accuracy when computing sums of the kind
    Pio_4 + x with x small,  by replacing them by Pio_4 + (Pio_4lo+x)

    @par Semantic:

    For type T:

    @code
    T r = Pio_4lo<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = 3.061616997868383e-17
    else if T is float
      r = -2.1855694e-08
    @endcode

    @return a value of type T

*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type pio_4lo_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0XB2BBBD2EU)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type pio_4lo_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X3C81A62633145C07ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type pio_4lo_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type pio_4lo_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return pio_4lo_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(pio_4lo_, pio_4lo);

  template<typename T>
  BOOST_FORCEINLINE T Pio_4lo(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return pio_4lo( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Pio_4lo() BOOST_NOEXCEPT
  {
    return pio_4lo( boost::simd::as_<T>{} );
  }
} }

#endif
