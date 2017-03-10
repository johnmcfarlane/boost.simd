//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_IF_ELSE_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/meta/is_pack.hpp>
#include <boost/config.hpp>
#include <boost/simd/function/if_else.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF( if_else_
                            , (typename A0,typename A1,typename A2)
                            , ( std::is_same< bd::value_of_t<typename A1::value_type>
                                            , bd::value_of_t<typename A2::value_type>
                                            >
                              )
                            , bd::cpu_
                            , bd::generic_<bs::logical_<A0>>
                            , bs::cmplx::complex_<A1>
                            , bs::cmplx::complex_<A2>
                            )
  {
    using value1_t  = typename A1::value_type;
    using value2_t  = typename A2::value_type;
    using base_t    = typename std::conditional<is_pack_t<value1_t>::value,value1_t,value2_t>::type;
    using result_t  = cmplx::complex<base_t>;

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& a1, A2 const& a2) const BOOST_NOEXCEPT
    {
      return {if_else(a0, a1.real, a2.real), if_else(a0, a1.imag, a2.imag)};
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF( if_else_
                            , (typename A0, typename A1,typename A2)
                            , ( std::is_same< bd::value_of_t<typename A1::value_type>
                                            , bd::value_of_t<typename A2::value_type>
                                            >
                              )
                            , bd::cpu_
                            , bd::scalar_<bd::fundamental_<A0>>
                            , bs::cmplx::complex_<A1>
                            , bs::cmplx::complex_<A2>
                            )
  {
    using value1_t  = typename A1::value_type;
    using value2_t  = typename A2::value_type;
    using base_t    = typename std::conditional<is_pack_t<value1_t>::value,value1_t,value2_t>::type;
    using result_t  = cmplx::complex<base_t>;

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& a1, A2 const& a2) const BOOST_NOEXCEPT
    {
    #ifdef BOOST_SIMD_BRANCH_FREE_IF_ELSE
       return {if_else(a0, a1.real, a2.real), if_else(a0, a1.imag, a2.imag)};
    #else
      return a0 ? a1 : a2;
    #endif
    }
  };

} } }

#endif
