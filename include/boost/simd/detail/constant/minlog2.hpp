//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MINLOG2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MINLOG2_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant Minlog2 used in logarithm/exponential computations
    boost::simd::log2(x) return  0 if x is less than Minlog2 (underflow)

    @par Semantic:

    @code
    T r = Minlog2<T>();
    @endcode

    is similar to:

    @code
    if T is double
    r = -1023.0;
    else if T is float
    r = -127.0;

    @endcode


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type minlog2_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0XC2FE0000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type minlog2_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0XC08FF00000000000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type minlog2_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type minlog2_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return minlog2_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(minlog2_, minlog2);

  template<typename T>
  BOOST_FORCEINLINE T Minlog2(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return minlog2( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Minlog2() BOOST_NOEXCEPT
  {
    return minlog2( boost::simd::as_<T>{} );
  }
} }

#endif
