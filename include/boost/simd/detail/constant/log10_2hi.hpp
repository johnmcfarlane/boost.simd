//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_LOG10_2HI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_LOG10_2HI_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant log10_2hi.This constant is coupled with Log10_2lo and is
    used in the float logarithms computations
    We have abs( double(log10_2hi<float>())+double(Log10_2lo<float>()) - Log10(2.0) < 3e-11

    @par Semantic:

    @code
    T r = log10_2hi<T>();
    @endcode


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type log10_2hi_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X3E9A0000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type log10_2hi_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X3FD3440000000000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type log10_2hi_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type log10_2hi_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return log10_2hi_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(log10_2hi_, log10_2hi);

  template<typename T>
  BOOST_FORCEINLINE T Log10_2hi(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return log10_2hi( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Log10_2hi() BOOST_NOEXCEPT
  {
    return log10_2hi( boost::simd::as_<T>{} );
  }
} }

#endif
