//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_LDEXP_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>

#include <boost/config.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/constant/nbexponentbits.hpp>
#include <boost/simd/detail/constant/pow2mask.hpp>
#include <boost/simd/constant/two.hpp>

namespace boost { namespace simd { namespace ext
{

  BOOST_FORCEINLINE pack<double,4,avx_> ldexp__( BOOST_SIMD_SUPPORTS(avx_)
                                               , pack<double,4,avx_> const& a0
                                               , pack<double,4,avx_> const& a1
                                               ) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(assert_all(is_flint(a1)||is_invalid(a1)), "parameter is not a flint nor invalid");
    using p_t = pack<double,4,avx_>;
    A0 oddv = fma(a1+Maxexponent<double>(), Two<double>(), (1 << (Nbexponentbits<double>()+1)) + 1);
    return a0*shift_left(bitwise_and(Pow2mask<p_t>(), oddv), Nbexponentbits<double>());
  }

} } }

#endif

