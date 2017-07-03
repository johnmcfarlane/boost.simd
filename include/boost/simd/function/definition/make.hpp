//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_MAKE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(make_, make_);

  template<typename Target, typename... Args>
  Target make(Args const&... args) BOOST_NOEXCEPT
  {
    return make_(as_<Target>(), args... );
  }

  template<typename Target, typename Arg0>
  Target make(Arg0 arg0) BOOST_NOEXCEPT
  {
    return make_(as_<Target>(), arg0);
  }

  template<typename Target, typename Arg0, typename... Args>
  Target make(as_<Target> const& tgt, Arg0 arg0, Args const&... args) BOOST_NOEXCEPT
  {
    return make_(tgt, arg0, args... );
  }
} }

#endif
