//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ISINCLUDED_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ISINCLUDED_HPP_INCLUDED

#include <boost/simd/function/scalar/bitwise_or.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

   template <typename T>
  BOOST_FORCEINLINE bool
   s_isincluded_( T a0
                , T a1
                , std::true_type  const &
                ) BOOST_NOEXCEPT
   {
     using p_t = as_i_t<T>;
     return  (bitwise_cast<p_t>(a0)| bitwise_cast<p_t>(a1)) == bitwise_cast<p_t>(a1);
   }
  template <typename T>
  BOOST_FORCEINLINE bool
  s_isincluded_( T a0
             , T a1
             , std::false_type const &
             ) BOOST_NOEXCEPT
  {
    return  (a0 | a1) == a1;
  }

  template <typename T>
  BOOST_FORCEINLINE bool
  isincluded_( BOOST_SIMD_SUPPORTS(cpu_)
             , T a0
             , T a1
             ) BOOST_NOEXCEPT
  {
    return  s_isincluded_(a0, a1, std::is_floating_point<T>()); ;
  }

} } }


#endif
