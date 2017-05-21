//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MINLOG10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MINLOG10_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant Minlog10 used in logarithm/exponential computations
    boost::simd::log10(x) return  0 if x is less than Minlog10 (underflow)

    @par Semantic:

    @code
    T r = Minlog10<T>();
    @endcode

    is similar to:

    @code
    if T is double
    r = -308.2547155599167;
    else if T is float
    r = -37.89999771118164;
    @endcode


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type minlog10_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0XC2179999U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type minlog10_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0XC0734413509F79FEULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type minlog10_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type minlog10_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return minlog10_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(minlog10_, minlog10);

  template<typename T>
  BOOST_FORCEINLINE T Minlog10(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return minlog10( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Minlog10() BOOST_NOEXCEPT
  {
    return minlog10( boost::simd::as_<T>{} );
  }
} }

#endif
