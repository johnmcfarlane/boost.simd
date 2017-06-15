//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/slide.hpp>
#include <boost/simd/function/interleave_second.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T> struct v_if
  {
    template<typename N, typename V>
    static BOOST_FORCEINLINE
    typename V::value_type value(V const& x, V const&, tt::true_type const&)
    {
      return simd::extract<N::value/2>(x);
    }

    template< typename N, typename V>
    static BOOST_FORCEINLINE
    typename V::value_type value(V const&, V const& y, tt::false_type const&)
    {
      return simd::extract<N::value/2>(y);
    }

    template< typename K, typename... N> static BOOST_FORCEINLINE
    T do_( T const& x, T const& y, K const&, nsm::list<N...> const&) BOOST_NOEXCEPT
    {
      return T( value<N>(x,y, nsm::bool_<N::value%2==0>{})... );
    }

    template< typename K, typename N> static BOOST_FORCEINLINE
    T do_( T const& x, T const&, K const&, nsm::list<N> const&) BOOST_NOEXCEPT
    {
      return x;
    }

    template< typename... N> static BOOST_FORCEINLINE
    T do_( T const& x, T const& y, aggregate_storage const&, nsm::list<N...> const&) BOOST_NOEXCEPT
    {
      auto const& x0 = x.storage()[0];
      auto const& y0 = y.storage()[0];

      return  combine ( interleave_first(x0, y0)
                      , interleave_second(x0, y0)
                      );
    }
  };

  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE pack<T,N,X>
  interleave_first_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N,X> const & x
          , pack<T,N,X> const & y) BOOST_NOEXCEPT
  {
    using stk_t = typename pack<T,N,X>::traits::storage_kind;
    return v_if<pack<T,N,X>>::do_( x, y, stk_t{}
                                , nsm::range<std::size_t, 0, N>{}
                                );
  }

} } }

#endif
