//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MANTISSAMASK_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MANTISSAMASK_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generate a mask used to compute the mantissa of a floating point value

    @par Semantic:

    @code
    as_integer<T> r = Mantissamask<T>();
    @endcode

    @code
    if T is double
      r =  -2.225073858507200889e-308;
    else if T is float
      r =  -1.1754942106924410755e-38;
    @endcode

    @return The Mantissamask constant for the proper type
  */

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type mantissamask_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X807FFFFFU)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type mantissamask_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X800FFFFFFFFFFFFFULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type mantissamask_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type mantissamask_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return mantissamask_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(mantissamask_, mantissamask);

  template<typename T>
  BOOST_FORCEINLINE T Mantissamask(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return mantissamask( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Mantissamask() BOOST_NOEXCEPT
  {
    return mantissamask( boost::simd::as_<T>{} );
  }
} }

#endif
