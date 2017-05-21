//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MAXLOG_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MAXLOG_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant MaxLog used in logarithm/exponential computations
    log(x) return inf if x is greater than Maxlog (overflow)

    @par Semantic:

    @code
    T r = Maxlog<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = 709.78271289338400;
    else if T is float
      r =  88.3762626647949
    @endcode

    @see Minlog


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type maxlog_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X42B0C0A5U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type maxlog_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X40862E42FEFA39EFULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type maxlog_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type maxlog_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return maxlog_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(maxlog_, maxlog);

  template<typename T>
  BOOST_FORCEINLINE T Maxlog(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return maxlog( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Maxlog() BOOST_NOEXCEPT
  {
    return maxlog( boost::simd::as_<T>{} );
  }
} }

#endif
