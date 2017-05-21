//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MAXLOG2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MAXLOG2_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant MaxLog2 used in logarithm/exponential computations
    log2(x) return inf if x is greater than Maxlog2 (overflow)

    @par Semantic:

    @code
    T r = Maxlog2<T>();
    @endcode

    is similar to:

    @code
    if T is double
    r = 1023.0;
    else if T is float
    r = 127.0;

    @endcode


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type maxlog2_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X42FE0000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type maxlog2_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X408FF80000000000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type maxlog2_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type( 0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type maxlog2_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return maxlog2_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(maxlog2_, maxlog2);

  template<typename T>
  BOOST_FORCEINLINE T Maxlog2(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return maxlog2( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Maxlog2() BOOST_NOEXCEPT
  {
    return maxlog2( boost::simd::as_<T>{} );
  }
} }

#endif
