//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_SIMD_LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_SIMD_LOGICAL_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE bool
  is_simd_logical_ ( BOOST_SIMD_SUPPORTS(cpu_)
                   , bool
                   ) BOOST_NOEXCEPT
  {
    return true;
  }

  template <typename T>
  BOOST_FORCEINLINE bool
  is_simd_logical_ ( BOOST_SIMD_SUPPORTS(cpu_)
                   , logical<T>
                   ) BOOST_NOEXCEPT
  {
    return true;
  }

  template <typename T>
  BOOST_FORCEINLINE bool
  s_is_simd_logical_( T a0
                    , std::true_type const &
                    ) BOOST_NOEXCEPT
  {
    return is_simd_logical(bitwise_cast<as_si_t<T>>(a0));;
  }

  template <typename T>
  BOOST_FORCEINLINE bool
  s_is_simd_logical_( T a0
                    , std::false_type const &
                    ) BOOST_NOEXCEPT
  {
    return a0 == genmask(a0);
  }

  template <typename T,
            typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE bool
  is_simd_logical_( BOOST_SIMD_SUPPORTS(cpu_)
                  , T a0
                  ) BOOST_NOEXCEPT
  {
    return s_is_simd_logical_(a0, std::is_floating_point<T>());
  }

} } }


#endif
