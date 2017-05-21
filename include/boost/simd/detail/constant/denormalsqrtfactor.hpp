//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_DENORMALSQRTFACTOR_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_DENORMALSQRTFACTOR_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant Denormalsqrtfactor used in pedantic rsqrt

    @par Semantic:

    @code
    T r = Denormalsqrtfactor<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = 2^26;
    else if T is float
      r = 2^12
    @endcode

    @see Maxlog


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type denormalsqrtfactor_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X45800000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type denormalsqrtfactor_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X4190000000000000ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type denormalsqrtfactor_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(1);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type denormalsqrtfactor_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return denormalsqrtfactor_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(denormalsqrtfactor_, denormalsqrtfactor);

  template<typename T>
  BOOST_FORCEINLINE T Denormalsqrtfactor(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return denormalsqrtfactor( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Denormalsqrtfactor() BOOST_NOEXCEPT
  {
    return denormalsqrtfactor( boost::simd::as_<T>{} );
  }
} }

#endif
