//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_AS_HPP_INCLUDED
#define BOOST_SIMD_AS_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/as.hpp>

namespace boost { namespace simd
{
  using boost::dispatch::as_;
  using boost::dispatch::as;

/*
  template<typename T> struct as_
  {
    using type = T;
  };

  template<typename T> as_<typename std::decay<T>::type> as(T&&)
  {
    return {};
  }
*/
} }

#endif
