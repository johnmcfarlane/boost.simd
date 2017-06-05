//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CONSTANT_MAXEXPONENT_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CONSTANT_MAXEXPONENT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

/*

    @ingroup group-constant

    Generate the maximum exponent of floating point numbers

    @par Semantic:

    @code
    as_integer<T> r = Maxexponent<T>();
    @endcode

    @code
    if T is double
      r =  1023;
    else if T is float
      r =  127;
    @endcode

    @return The Maxexponent constant for the proper type
  */

namespace bd = boost::dispatch;

namespace boost { namespace simd {

  namespace detail
  {

    template<typename Type>
    BOOST_FORCEINLINE bd::as_integer_t<Type> maxexponent_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      return bd::as_integer_t<Type>{127};
    }

    template<typename Type>
    BOOST_FORCEINLINE bd::as_integer_t<Type> maxexponent_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      return bd::as_integer_t<Type>{1023};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type maxexponent_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE bd::as_integer_t<Type> maxexponent_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return maxexponent_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(maxexponent_, maxexponent);

  template<typename T>
  BOOST_FORCEINLINE  bd::as_integer_t<T> Maxexponent(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return maxexponent( tgt );
  }

  template<typename T> BOOST_FORCEINLINE  bd::as_integer_t<T> Maxexponent() BOOST_NOEXCEPT
  {
    return maxexponent( boost::simd::as_<T>{} );
  }
} }

#endif

