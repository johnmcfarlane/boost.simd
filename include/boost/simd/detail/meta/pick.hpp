//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_META_PICK_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_META_PICK_HPP_INCLUDED

#include <boost/simd/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<std::size_t N>
  using case_ = tt_::integral_constant<std::size_t, N>;

  template<typename T> struct default_ : std::true_type {};
  template<typename T> struct never_   : std::false_type {};

  template<typename T, template<class> class... Checkers> struct pick;
  template< std::size_t N, typename T, bool Checked, template<class> class... Checkers> struct pick_;

  template< std::size_t N, typename T, template<class> class... Checkers>
  struct pick_<N,T,true,Checkers...> : tt_::integral_constant<std::size_t, N>
  {};

  template< std::size_t N, typename T, template<class> class Checker0, template<class> class... Checkers>
  struct pick_<N,T,false,Checker0,Checkers...> : pick_<N+1, T, Checker0<T>::value, Checkers...>
  {};

  template< std::size_t N, typename T, template<class> class Checker>
  struct pick_<N,T,false,Checker> : tt_::integral_constant<std::size_t, N + 1 + !Checker<T>::value>
  {};

  template<typename T, template<class> class Checker0, template<class> class... Checkers>
  struct pick<T,Checker0,Checkers...> : pick_<0, T, Checker0<T>::value, Checkers...>
  {};

  template<typename T, template<class> class Checker0>
  struct pick<T,Checker0> : tt_::integral_constant<std::size_t, !Checker0<T>::value>
  {};
} } }

#endif
