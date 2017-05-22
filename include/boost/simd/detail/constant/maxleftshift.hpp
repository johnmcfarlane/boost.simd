//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CONSTANT_MAXLEFTSHIFT_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CONSTANT_MAXLEFTSHIFT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

/*

    @ingroup group-constant

    Generate the number of bits-1 of the scalar component of the value type

    @par Semantic:

    @code
    as_integer<T> r = Maxleftshift<T>();
    @endcode

    is similar to:

    @code
    as_integer<T> r =size(scalar_of<T>)*8-1;
    @endcode

    @return The Maxleftshift constant for the proper type
  */

namespace bd = boost::dispatch;

namespace boost { namespace simd {
  namespace detail
  {

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE bd::as_integer_t<Type> maxleftshift_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const&
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return bd::as_integer_t<Type>{sizeof(base)*CHAR_BIT-1};
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(maxleftshift_, maxleftshift);

  template<typename T>
  BOOST_FORCEINLINE bd::as_integer_t<T> Maxleftshift(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return maxleftshift( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Maxleftshift() BOOST_NOEXCEPT
  {
    return maxleftshift( boost::simd::as_<T>{} );
  }
} }

#endif

