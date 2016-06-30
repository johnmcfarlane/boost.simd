//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

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

    static_assert ( sizeof...(Values) <= 4
                  , "boost::simd::make - Invalid number of parameters"
                  );

    BOOST_FORCEINLINE target_t operator()(Target const&, Values const&... vs) const BOOST_NOEXCEPT
    {
      return do_(std::integral_constant<int,sizeof...(Values)>{}, vs...);
    }

    template<typename V0, typename V1>
    BOOST_FORCEINLINE target_t do_( std::integral_constant<int,2> const&
                                  , V0 v0, V1 v1
                                  ) const BOOST_NOEXCEPT
    {
      return _mm_setr_ps(v0,v1,0,0);
    }

    BOOST_FORCEINLINE target_t do_( std::integral_constant<int,4> const&
                                  , Values const&... vs
                                  ) const BOOST_NOEXCEPT
    {
      return _mm_setr_ps(static_cast<typename target_t::value_type>(vs)...);
    }
  };
} } }

#endif
