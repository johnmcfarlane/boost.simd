//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MINLOG_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MINLOG_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant Minlog used in logarithm/exponential computations
    boost::simd::log(x) return  0 if x is less than Minlog (underflow)

    @par Semantic:

    @code
    T r = Minlog<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = -708.3964185322641;
    else if T is float
      r = -88.3762626647949
    @endcode

    @see Maxlog


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type minlog_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0XC2B0C0A5U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type minlog_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0XC086232BDD7ABCD2ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type minlog_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type minlog_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return minlog_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(minlog_, minlog);

  template<typename T>
  BOOST_FORCEINLINE T Minlog(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return minlog( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Minlog() BOOST_NOEXCEPT
  {
    return minlog( boost::simd::as_<T>{} );
  }
} }

#endif
