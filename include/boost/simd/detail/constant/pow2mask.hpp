//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_POW2MASK_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_POW2MASK_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generate a mask value used in pow2

    @return The Pow2mask constant for the proper type
  */

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type pow2mask_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X7FBFFFU)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type pow2mask_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0XFFEFFFFFFFFFFULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type pow2mask_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type pow2mask_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return pow2mask_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(pow2mask_, pow2mask);

  template<typename T>
  BOOST_FORCEINLINE T Pow2mask(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return pow2mask( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Pow2mask() BOOST_NOEXCEPT
  {
    return pow2mask( boost::simd::as_<T>{} );
  }
} }

#endif
