//==================================================================================================
/**
  Cpyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED


#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/slice.hpp>
#include <boost/simd/function/if_one_else_zero.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
 {

   template < typename A>
  struct st_nbtrue
  {

    BOOST_FORCEINLINE std::size_t operator()(A const& a0)  const BOOST_NOEXCEPT
    {
      return do_( a0, typename A::storage_kind(), typename A::traits::static_range{});
    }

    // Aggregate case: add the nbtrue of both sides
    template<typename... N> static BOOST_FORCEINLINE
    std::size_t do_(A const& a0, aggregate_storage const&, nsm::list<N...> const&) BOOST_NOEXCEPT
    {
      return nbtrue(slice_low(a0)) + nbtrue(slice_high(a0));
    }

    // Other case: Compute nbtrue piecewise
    template<typename K, typename... N> static BOOST_FORCEINLINE
    std::size_t do_(A const& a0, K const&, nsm::list<N...> const&) BOOST_NOEXCEPT
    {
      std::size_t that = 0;

      (void)std::initializer_list<std::size_t>
      {
        (that += if_one_else_zero(bs::extract<N::value>(a0)))...
      };

      return that;
    }
  };

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  typename std::enable_if<!std::is_arithmetic<T>::value, std::size_t>::type
  nbtrue_(BOOST_SIMD_SUPPORTS(simd_)
                     , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    st_nbtrue<as_logical_t<pack<T,N>>> r;
    return r(a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_arithmetic<T>::value, std::size_t>::type
  nbtrue_(BOOST_SIMD_SUPPORTS(simd_)
                     , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    //   as_logical_t<pack<T,N>> inz = False<pack<T,N>>(); //is_nez(a0);
    return nbtrue(is_nez(a0));
  }

} } }

#endif
