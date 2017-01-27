//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_DETAIL_HIERARCHY_SIMD_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_DETAIL_HIERARCHY_SIMD_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/forward.hpp>
#include <boost/simd/detail/dispatch/hierarchy/unspecified.hpp>
#include <boost/simd/detail/dispatch/meta/value_of.hpp>
#include <boost/simd/detail/dispatch/meta/model_of.hpp>
#include <boost/simd/detail/dispatch/hierarchy_of.hpp>

namespace boost { namespace simd { namespace cmplx
{
  template<typename T> struct complex;

  template<typename T>
  struct complex_ : boost::dispatch::unspecified_<T>
  {
    using parent = boost::dispatch::unspecified_<T>;
  };
} } }

namespace boost { namespace dispatch
{
  namespace ext
  {
    template<typename T> struct model_of<boost::simd::cmplx::complex<T>>
    {
      template<typename X> struct apply
      {
        using base = typename model_of<T>::template apply<X>::type;
        using type = boost::simd::cmplx::complex<base>;
      };
    };

    template<typename T> struct value_of<boost::simd::cmplx::complex<T>>
    {
      using type = T;
    };

    template<typename T> struct scalar_of<boost::simd::cmplx::complex<T>>
    {
      using base = scalar_of_t<T>;
      using type = boost::simd::cmplx::complex<base>;
    };

    template<typename T,typename Origin>
    struct hierarchy_of<boost::simd::cmplx::complex<T>,Origin>
    {
      using type = boost::simd::cmplx::complex_<Origin>;
    };
  }
} }

#endif
