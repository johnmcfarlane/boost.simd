//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_INVLOG_10LO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_INVLOG_10LO_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type invlog_10lo_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0xb804ead9U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type invlog_10lo_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0x3dbb9438ca9aadd5ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type invlog_10lo_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type invlog_10lo_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return invlog_10lo_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(invlog_10lo_, invlog_10lo);

  template<typename T>
  BOOST_FORCEINLINE T Invlog_10lo(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return invlog_10lo( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Invlog_10lo() BOOST_NOEXCEPT
  {
    return invlog_10lo( boost::simd::as_<T>{} );
  }
} }

#endif
