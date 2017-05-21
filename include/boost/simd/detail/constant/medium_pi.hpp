//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CONSTANT_MEDIUM_PI_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CONSTANT_MEDIUM_PI_HPP_INCLUDED


#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>

/*


    @ingroup group-constant

    Constant used in trigonometric reductions

    @par Semantic:

    For type T:

    @code
    T r = Medium_pi<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = Pi<T>()*pow2(18);
    else if T is float
      r = Pi<T>()*pow2(6);
    else
      r =  201
    @endcode

    @return a value of type T

*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type medium_pi_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X43490FDBU)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type medium_pi_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(00X412921FB54442D18ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type medium_pi_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(201);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type medium_pi_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return medium_pi_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(medium_pi_, medium_pi);

  template<typename T>
  BOOST_FORCEINLINE T Medium_pi(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return medium_pi( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Medium_pi() BOOST_NOEXCEPT
  {
    return medium_pi( boost::simd::as_<T>{} );
  }
} }

#endif

