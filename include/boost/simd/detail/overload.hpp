//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_OVERLOAD_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_OVERLOAD_HPP_INCLUDED

#include <boost/simd/config.hpp>

// TO REMOVE LATER
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/hierarchy.hpp>

// Builds a Boost.SIMD delayed function object
#define BOOST_SIMD_MAKE_CALLABLE(TAG,NAME)                                                          \
namespace tag { struct TAG {}; }                                                                    \
namespace detail                                                                                    \
{                                                                                                   \
  template<> struct callable_object<tag::TAG>                                                       \
  {                                                                                                 \
    using tag_type = tag::TAG;                                                                      \
    template<typename... Args>                                                                      \
    BOOST_FORCEINLINE auto operator()(Args&&... args) const BOOST_NOEXCEPT                          \
      -> decltype( TAG( delay_t{}, BOOST_SIMD_DEFAULT_SITE{}, std::forward<Args>(args)... ) )       \
    {                                                                                               \
      return TAG( delay_t{}, BOOST_SIMD_DEFAULT_SITE{}, std::forward<Args>(args)... );              \
    };                                                                                              \
  };                                                                                                \
}                                                                                                   \
                                                                                                    \
detail::callable_object<tag::TAG> const NAME = {}                                                   \
/**/

// Flag a unction to support delayed calls on given architecture
#define BOOST_SIMD_SUPPORTS(ARCH) delay_t const&, ARCH const&

// basic type to support delayed calls
namespace boost { namespace simd { namespace detail
{
  struct delay_t {};
  template<typename Tag, typename Mode = void> struct callable_object;
} } }

#endif
