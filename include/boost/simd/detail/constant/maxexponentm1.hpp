//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CONSTANT_MAXEXPONENTM1_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CONSTANT_MAXEXPONENTM1_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

/*

    @ingroup group-constant

    Generate the maximum exponent of floating point numbers minus one

    @par Semantic:

    @code
    as_integer<T> r = Maxexponentm1<T>();
    @endcode

    @code
    if T is double
      r =  1022;
    else if T is float
      r =  126;
    @endcode

    @return The Maxexponentm1 constant for the proper type
  */

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE bd::as_integer_t<Type> maxexponentm1_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      return bd::as_integer_t<Type>{126};
    }

    template<typename Type>
    BOOST_FORCEINLINE bd::as_integer_t<Type> maxexponentm1_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      return bd::as_integer_t<Type>{1022};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type maxexponentm1_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE bd::as_integer_t<Type> maxexponentm1_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return maxexponentm1_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(maxexponentm1_, maxexponentm1);

  template<typename T>
  BOOST_FORCEINLINE bd::as_integer_t<T> Maxexponentm1(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return maxexponentm1( tgt );
  }

  template<typename T> BOOST_FORCEINLINE bd::as_integer_t<T> Maxexponentm1() BOOST_NOEXCEPT
  {
    return maxexponentm1( boost::simd::as_<T>{} );
  }
} }

#endif
