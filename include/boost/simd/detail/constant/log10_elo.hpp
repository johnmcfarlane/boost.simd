//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_LOG10_ELO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_LOG10_ELO_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant log10_elo.This constant is coupled with Log10_ehi and is
    used in the float logarithms computations
    We have abs( double(log10_elo<float>())+double(Log10_ehi<float>()) - Log_10(e)) < 3e-11

    @par Semantic:

    @code
    T r = log10_elo<T>();
    @endcode


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type log10_elo_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X3A37B152U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type log10_elo_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X00ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type log10_elo_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type log10_elo_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return log10_elo_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(log10_elo_, log10_elo);

  template<typename T>
  BOOST_FORCEINLINE T Log10_elo(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return log10_elo( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Log10_elo() BOOST_NOEXCEPT
  {
    return log10_elo( boost::simd::as_<T>{} );
  }
} }

#endif
