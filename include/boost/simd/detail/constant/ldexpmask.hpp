//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CONSTANT_LDEXPMASK_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CONSTANT_LDEXPMASK_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>

/*

    @ingroup group-constant

    Generate the mask to extract the exponent
    bits of a floating point value

    @par Semantic:

    @code
    T r = Ldexpmask<T>();
    @endcode

    @return The Ldexpmask constant for the proper type
  */

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type ldexpmask_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0x7F800000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type ldexpmask_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0x7FF0000000000000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type ldexpmask_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type ldexpmask_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return ldexpmask_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(ldexpmask_, ldexpmask);

  template<typename T>
  BOOST_FORCEINLINE T Ldexpmask(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return ldexpmask( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Ldexpmask() BOOST_NOEXCEPT
  {
    return ldexpmask( boost::simd::as_<T>{} );
  }
} }

#endif

