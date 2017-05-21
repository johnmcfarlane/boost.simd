//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CONSTANT_MAXFLINT_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CONSTANT_MAXFLINT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>


/*

    @ingroup group-constant

    Generate the least integer value which is exactly
    representable in floating point numbers and
    equal to its integral successor.

    All floating numbers greater than Maxflint are integral.

    @par Semantic:

    @code
    T r = Maxflint<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = 9007199254740992.0
    else if T is float
      r = 16777216.0f
    @endcode


    @return The Maxflint constant for the proper type
  */


namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type maxflint_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0x4b800000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type maxflint_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0x4340000000000000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type maxflint_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(1);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type maxflint_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return maxflint_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(maxflint_, maxflint);

  template<typename T>
  BOOST_FORCEINLINE T Maxflint(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return maxflint( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Maxflint() BOOST_NOEXCEPT
  {
    return maxflint( boost::simd::as_<T>{} );
  }
} }

#endif

