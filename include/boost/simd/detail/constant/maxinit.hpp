//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CONSTANT_MAXINIT_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CONSTANT_MAXINIT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>

/*

    @ingroup group-constant

    Generate the constant maxinit which is identical to minf for
    arithmetic real types but that must be specialized for complex values ordering.

    maxinit is the value to be returned when a maximum of the elements function is used on an
    empty container.

    @return The Maxinit constant for the proper type
  */

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type maxinit_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0xFF800000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type maxinit_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0xFFF0000000000000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type maxinit_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(std::numeric_limits<base>::min());
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type maxinit_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return maxinit_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(maxinit_, maxinit);

  template<typename T>
  BOOST_FORCEINLINE T Maxinit(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return maxinit( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Maxinit() BOOST_NOEXCEPT
  {
    return Maxinit( boost::simd::as_<T>{} );
  }
} }

#endif

