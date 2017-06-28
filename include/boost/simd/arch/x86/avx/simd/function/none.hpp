//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompnoneing file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_NONE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_NONE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/detail/constant/butsign.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

  template< typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool v_none_ (pack<T,N,avx_> const& a0
             , std::false_type const &
             ) BOOST_NOEXCEPT
  {
    return  _mm256_testz_si256(a0, Allbits<A0>());
  }

  template< typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool v_none_ (pack<T,N,avx_> const& a0
             , std::true_type const &
             ) BOOST_NOEXCEPT
  {
    using p_t  = pack<T,N,avx_>;
    using ip_t = bd::as_integer_t<p_t>;
    return _mm256_testz_si256(bitwise_cast<ip_t>(a0), Butsign<ip_t>());
  }

  template< typename T, std::size_t N>
  BOOST_FORCEINLINE
  bool none_ (BOOST_SIMD_SUPPORTS(avx_)
            , pack<T,N,avx_> const& a0
            ) BOOST_NOEXCEPT
  {
    return v_none_(a0, std::is_floating_point<T>());
  }

} } }

#endif
