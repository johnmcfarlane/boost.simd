//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/meta/is_bitwise_logical.hpp>
#include <boost/simd/meta/as_arithmetic.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/bitwise_not.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost { namespace simd { namespace detail
{
  namespace bs = boost::simd;
  // Native implementation
  template<typename T, std::size_t N
           , typename = typename std::enable_if<bs::is_bitwise_logical_t<pack<T, N>>::value>::type>
  BOOST_FORCEINLINE
  as_logical_t<pack<T, N>> is_equal_ ( BOOST_SIMD_SUPPORTS(simd_)
                                     , pack<T, N> const& a
                                     , pack<T, N> const& b
                                     ) BOOST_NOEXCEPT
  {
    using logi_t = as_logical_t<pack<T, N>>;
    using cast_t = bs::as_arithmetic_t<pack<T, N>>;
    return bitwise_cast<logi_t>(bitwise_not(bitwise_xor(bitwise_cast<cast_t>(a),bitwise_cast<cast_t>(b))));
  }

  // mixed implementation
  template< typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE typename std::enable_if<std::is_convertible<U, T>::value
                                            , as_logical_t< pack<T,N>>>::type
  is_equal_ ( BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N> const& a
            , U b
            ) BOOST_NOEXCEPT
  {
    return is_equal(a, pack<T,N>(b));
  }


  template< typename T, std::size_t N, typename U >
  BOOST_FORCEINLINE typename std::enable_if<std::is_convertible<U, T>::value
                                            , as_logical_t< pack<T,N>>>::type
  is_equal_ ( BOOST_SIMD_SUPPORTS(simd_)
            , U a
            , pack<T,N> const& b
            ) BOOST_NOEXCEPT
  {
    return s_equal(pack<T,N>(a), b);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_logical_t<pack<T, N, simd_emulation_>>
  is_equal_ ( BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N,simd_emulation_> const& a
            , pack<T,N,simd_emulation_> const& b
            ) BOOST_NOEXCEPT
  {
    return map_to( simd::is_equal, a, b);
  }


} } }

#endif
