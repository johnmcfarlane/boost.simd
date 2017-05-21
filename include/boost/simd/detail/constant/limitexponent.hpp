//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CONSTANT_LIMITEXPONENT_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CONSTANT_LIMITEXPONENT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

/*

    @ingroup group-constant

    Generate the limit exponent of floating point numbers,  that is Maxexponant+1

    @par Semantic:

    @code
    as_integer<T> r = Limitexponent<T>();
    @endcode

    @code
    if T is double
      r =  1024;
    else if T is float
      r =  128;
    @endcode

    @return The Limitexponent constant for the proper type
  */
namespace bd = boost::dispatch;

namespace boost { namespace simd {
  namespace detail
  {

    template<typename Type>
    BOOST_FORCEINLINE bd::as_integer_t<Type> limitexponent_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      return bd::as_integer_t<Type>{128};
    }

    template<typename Type>
    BOOST_FORCEINLINE bd::as_integer_t<Type> limitexponent_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      return bd::as_integer_t<Type>{1024};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type limitexponent_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type limitexponent_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return limitexponent_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(limitexponent_, limitexponent);

  template<typename T>
  BOOST_FORCEINLINE T Limitexponent(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return limitexponent( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Limitexponent() BOOST_NOEXCEPT
  {
    return limitexponent( boost::simd::as_<T>{} );
  }
} }

#endif

