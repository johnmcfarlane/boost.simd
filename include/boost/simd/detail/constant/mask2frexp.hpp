//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CONSTANT_MASK2FREXP_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CONSTANT_MASK2FREXP_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>

/*

    @ingroup group-constant

    Generate the constant mask2frexp, a utility mask for frexp implementation.

    @par Semantic:

    @code
    as_integer<T> r = Mask2frexp<T>();
    @endcode

    @code
    if T is double
      r =  4602678819172646912ll;
    else if T is float
      r =  1056964608;
    @endcode

    @return The Mask2frexp constant for the proper type
  */

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type mask1frexp_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(00x3f000000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type mask1frexp_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0x3fe0000000000000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type mask1frexp_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type mask1frexp_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return mask1frexp_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(mask1frexp_, mask1frexp);

  template<typename T>
  BOOST_FORCEINLINE T Mask1frexp(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return mask1frexp( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Mask1frexp() BOOST_NOEXCEPT
  {
    return mask1frexp( boost::simd::as_<T>{} );
  }
} }

#endif
