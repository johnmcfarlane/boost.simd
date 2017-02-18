//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#include <boost/simd/meta/is_power_of_2.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/detail/nope.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename Base> struct sse_set;

  template<> struct sse_set<float>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m128 do_(nsm::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm_setr_ps( static_cast<float>(vs)..., detail::nope<float,Z>()... );
    }
  };
} } }

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // make a pack of single
  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename... Values)
                          , bs::sse1_
                          , bd::target_<bs::pack_<bd::single_<Target>,bs::sse_>>
                          , bd::scalar_<bd::unspecified_<Values>>...
                          )
  {
    using target_t  = typename Target::type;

    static_assert ( (sizeof...(Values) <= 4) && (is_power_of_2_<sizeof...(Values)>::value)
                  , "boost::simd::make - Invalid number of parameters"
                  );

    BOOST_FORCEINLINE target_t operator()(Target const&, Values const&... vs) const BOOST_NOEXCEPT
    {
      return detail::sse_set<float>::do_( nsm::range<int,sizeof...(Values), 4>{}, vs...);
    }
  };
} } }

#endif
