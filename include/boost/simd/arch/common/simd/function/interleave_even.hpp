//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INTERLEAVE_EVEN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INTERLEAVE_EVEN_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/combine.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T> struct v_ie
  {
    static_assert ( T::static_size >= 2
                  , "interleave_even requires at least two elements"
                  );

    template< typename N, typename V>
    static BOOST_FORCEINLINE
    typename V::value_type value(V const&, V const& y, tt::false_type const&)
    {
      return simd::extract<2*(N::value/2)>(y);
    }

    template<typename N, typename V>
    static BOOST_FORCEINLINE
    typename V::value_type value(V const& x, V const&, tt::true_type const&)
    {
      return simd::extract<2*(N::value/2)>(x);
    }

    template< typename K, typename... N> static BOOST_FORCEINLINE
    T do_( T const& x, T const& y, K const&, nsm::list<N...> const&) BOOST_NOEXCEPT
    {
      return T( value<N>(x,y, nsm::bool_<N::value%2==0>{})... );
    }

    template< typename N0, typename N1> static BOOST_FORCEINLINE
    T do_( T const& x, T const& y, aggregate_storage const&, nsm::list<N0,N1> const&) BOOST_NOEXCEPT
    {
      return  T(x[0],y[0]);
    }

    template< typename... N> static BOOST_FORCEINLINE
    T do_( T const& x, T const& y, aggregate_storage const&, nsm::list<N...> const&) BOOST_NOEXCEPT
    {
       auto const& x0 = x.storage()[0];
       auto const& x1 = x.storage()[1];
       auto const& y0 = y.storage()[0];
       auto const& y1 = y.storage()[1];

       return  combine(interleave_even(x0,y0), interleave_even(x1,y1));
    }
  };

  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE pack<T,N,X>
  interleave_even_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N,X> const & x
                  , pack<T,N,X> const & y) BOOST_NOEXCEPT
  {
    using stk_t = typename pack<T,N,X>::traits::storage_kind;
    return v_ie<pack<T,N,X>>::do_( x, y, stk_t{}
                                 , nsm::range<std::size_t, 0, N>{}
                                 );
  }

} } }

#endif
