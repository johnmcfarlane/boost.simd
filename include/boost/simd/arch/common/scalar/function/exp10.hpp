//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXP10_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXP10_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/arch/common/detail/scalar/exponential.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/config.hpp>
#include <boost/simd/meta/is_pack.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T exp10_(BOOST_SIMD_SUPPORTS(cpu_)
        , T a) BOOST_NOEXCEPT
  {
    return detail::exponential<T,bs::tag::exp10_,is_pack_t<T>>::expa(a);
  }

} } }


#endif
