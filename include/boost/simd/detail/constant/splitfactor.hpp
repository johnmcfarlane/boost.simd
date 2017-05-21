//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_SPLITFACTOR_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_SPLITFACTOR_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generate  a constant used to split a floating number in two parts,
    in floating point routines (such @ref two_add and
    @ref two_prod) to get extra precision.

    @par Semantic:

    @code
    T r = Splitfactor<T>();
    @endcode

    is similar to:

    @code
    if T is integral
      r = 0
    else if T is double
      r =  pow(2, 27);
    else if T is float
      r =  pow(2, 13);
    @endcode

    @return The Splitfactor constant for the proper type
  */

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type splitfactor_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X46000000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type splitfactor_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X41A0000000000000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type splitfactor_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type splitfactor_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return splitfactor_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(splitfactor_, splitfactor);

  template<typename T>
  BOOST_FORCEINLINE T Splitfactor(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return splitfactor( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Splitfactor() BOOST_NOEXCEPT
  {
    return splitfactor( boost::simd::as_<T>{} );
  }
} }

#endif
