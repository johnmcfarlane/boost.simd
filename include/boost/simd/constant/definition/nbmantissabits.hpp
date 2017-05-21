//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_NBMANTISSABITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_NBMANTISSABITS_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(nbmantissabits_, nbmantissabits);

  template<typename T>
  BOOST_FORCEINLINE T Nbmantissabits(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return nbmantissabits( tgt );
  }

  template<typename T> BOOST_FORCEINLINE auto Nbmantissabits() BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    nbmantissabits( boost::simd::as_<T>{} )
  )

} }

#endif

