//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IFREXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IFREXP_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/detail/constant/limitexponent.hpp>
#include <boost/simd/detail/constant/mask1frexp.hpp>
#include <boost/simd/detail/constant/mask2frexp.hpp>
#include <boost/simd/detail/constant/maxexponentm1.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_andnot.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/logical_notand.hpp>
#include <boost/simd/function/if_plus.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <utility>

#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/twotonmb.hpp>
#endif

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // raw case
  template<typename T, std::size_t N
           ,  typename =  typename std::enable_if<std::is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE pair_it<pack<T,N>>
  ifrexp_(BOOST_SIMD_SUPPORTS(simd_)
        , raw_tag const&
        , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    auto m1f = Mask1frexp<p_t>();
    auto r1 = bitwise_cast<as_si_t<p_t>>(bitwise_and(m1f, a0));
    auto x  = bitwise_andnot(a0, m1f);

    return  pair_it<pack<T,N>>{ bitwise_or(x,Mask2frexp<p_t>())
        , shr(r1,Nbmantissabits<T>()) - Maxexponentm1<p_t>()
        };
  }

  //================================================================================================
  // regular case
  template<typename T, std::size_t N
           ,  typename =  typename std::enable_if<std::is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE pair_it<pack < T, N>>
  ifrexp_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    auto that = raw_(ifrexp)(a0);
    return  pair_it<pack<T,N>>{ if_else_zero(a0,that.first), if_else_zero(a0,that.second) };
  }

  //================================================================================================
  // pedantic case
  template<typename T, std::size_t N
           ,  typename =  typename std::enable_if<std::is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE pair_it<pack < T, N>>
  ifrexp_(BOOST_SIMD_SUPPORTS(simd_)
        , pedantic_tag const&
        , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = logical_and(is_less(bs::abs(a0), Smallestposval<p_t>()), is_nez(a0));
    auto    t = if_else_zero(test,Nbmantissabits<p_t>());
    auto  aa0 = if_else(test, Twotonmb<p_t>()*a0, a0);
#else
    auto  aa0 = a0;
#endif

    auto r1 = simd::bitwise_cast<as_si_t<p_t>>(bitwise_and(aa0, Mask1frexp<p_t>())); //extract exp.
    auto x  = bitwise_andnot(aa0, Mask1frexp<p_t>());
    r1 = shr(r1,Nbmantissabits<T>()) - Maxexponentm1<p_t>();
    auto r0 = bitwise_or(x,Mask2frexp<p_t>());

    auto test0 = is_nez(aa0);
    auto test1 = is_greater(r1,Limitexponent<p_t>());
    r1 = if_else_zero(logical_notand(test1, test0), r1);

#ifndef BOOST_SIMD_NO_DENORMALS
    r1 -= t ;
#endif

    return  pair_it<pack < T, N>>{ if_else_zero(test0, if_plus(test1,r0,aa0)), r1};
  }



//   //================================================================================================
//   // std case
//   template<typename T, std::size_t N
//            ,  std::enable_if<std::is_floating_point<T>::value>
//   >
//   BOOST_FORCEINLINE pair_it<pack<T,N>>
//   ifrexp_(BOOST_SIMD_SUPPORTS(simd_)
//         , std_tag const&
//         , pack<T,N> const& a0) BOOST_NOEXCEPT
//   {
//     return ???
//   }

} } }

#endif
