//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_HMSB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_HMSB_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/simd/detail/bitset.hpp>
#include <cstddef>

namespace boost { namespace simd { namespace detail
{

  namespace bs = boost::simd;

  template<typename A0, typename I, typename R> BOOST_FORCEINLINE
  void piece(const A0& a0, R& r) BOOST_NOEXCEPT
  {
    r.set ( I::value
          , bs::bitwise_and ( bs::Signmask<as_i_t<typename A0::value_type>>()
                            , bs::extract<I::value>(a0)
                            ) != 0
          );
  }

  template<typename A0, typename... N>
  BOOST_FORCEINLINE void vhmsb_(const A0& a0
                               , bs::bitset<cardinal_of<A0>::value> & r
                               , nsm::list<N...> const&)  BOOST_NOEXCEPT
  {
    (void)(std::initializer_list<bool>{(piece<A0,N>(a0,r),true)...});
  }


  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  bs::bitset<N> hmsb_(BOOST_SIMD_SUPPORTS(cpu_)
                        , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
     bs::bitset<N> r;
     vhmsb_(a0,r,typename p_t::traits::element_range());
     return r;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  bs::bitset<N> hmsb_(BOOST_SIMD_SUPPORTS(cpu_)
                     , bs::as_logical_t<pack<T, N>> const & a0
                     )
  {
    return bs::hmsb(bs::genmask(a0));
  }

} } }

#endif
