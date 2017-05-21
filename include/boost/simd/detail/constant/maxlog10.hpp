//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MAXLOG10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MAXLOG10_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant MaxLog10 used in logarithm/exponential computations
    log10(x) return inf if x is greater than Maxlog10 (overflow)

    @par Semantic:

    @code
    T r = Maxlog10<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = 308.2547155599167;
    else if T is float
      r = 38.23080825805664;

    @endcode


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type maxlog10_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X4218EC59U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type maxlog10_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X40734413509F79FEULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type maxlog10_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type maxlog10_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return maxlog10_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(maxlog10_, maxlog10);

  template<typename T>
  BOOST_FORCEINLINE T Maxlog10(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return maxlog10( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Maxlog10() BOOST_NOEXCEPT
  {
    return maxlog10( boost::simd::as_<T>{} );
  }
} }

#endif
