//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DEINTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DEINTERLEAVE_FIRST_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/make.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T> struct v_df
  {
    static_assert ( T::static_size >= 2
                  , "deinterleave_first requires at least two elements"
                  );

    template<typename K, typename... N> static BOOST_FORCEINLINE
    T do_( T const& x, T const& y, K const&, nsm::list<N...> const&) BOOST_NOEXCEPT
    {
      return make( as_<T>{}, bs::extract<N::value*2>(x)..., bs::extract<N::value*2>(y)... );
    }

    template<typename N0, typename N1, typename... Ns> static BOOST_FORCEINLINE
    T do_( T const& x, T const& y, aggregate_storage const&, nsm::list<N0,N1,Ns...> const&) BOOST_NOEXCEPT
    {
      return  combine ( deinterleave_first(x.storage()[0],x.storage()[1])
                      , deinterleave_first(y.storage()[0],y.storage()[1])
                      );
    }
  };

  template<typename T, std::size_t N, typename X>
 BOOST_FORCEINLINE pack<T,N,X>
  deinterleave_first_(BOOST_SIMD_SUPPORTS(simd_)
                     , pack<T,N,X> const & x
                     , pack<T,N,X> const & y) BOOST_NOEXCEPT
  {
    using stk_t = typename pack<T,N,X>::traits::storage_kind;
    return v_df<pack<T,N,X>>::do_( x, y, stk_t{}
                                 , nsm::range<std::size_t, 0, N/2>{}
                                 );
  }

} } }

#endif
