//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/insert.hpp>
#include <boost/simd/meta/is_power_of_2.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/nope.hpp>

// -------------------------------------------------------------------------------------------------
// Helper for generifying calls to setr
namespace boost { namespace simd { namespace detail
{
  template<> struct sse_set<double>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m128d do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm_setr_pd( static_cast<double>(vs)..., detail::nope<double,Z>()... );
    }
  };

  template<> struct sse_set<std::int32_t>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m128i do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm_setr_epi32( vs..., detail::nope<std::int32_t,Z>()... );
    }
  };

  template<> struct sse_set<std::int16_t>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m128i do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm_setr_epi16( vs..., detail::nope<std::int16_t,Z>()... );
    }
  };

  template<> struct sse_set<char>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m128i do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm_setr_epi8( vs..., detail::nope<char,Z>()... );
    }
  };

  template<> struct sse_set<std::int8_t >   : sse_set<char>         {};
  template<> struct sse_set<std::uint8_t>   : sse_set<char>         {};
  template<> struct sse_set<std::uint16_t>  : sse_set<std::int16_t> {};
  template<> struct sse_set<std::uint32_t>  : sse_set<std::int32_t> {};
} } }
// -------------------------------------------------------------------------------------------------

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // make a pack of double
  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename... Values)
                          , bs::sse2_
                          , bd::target_<bs::pack_<bd::double_<Target>,bs::sse_>>
                          , bd::scalar_<bd::unspecified_<Values>>...
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;

    static_assert ( (sizeof...(Values) == 2) || (sizeof...(Values) == 1)
                  , "boost::simd::make - Invalid number of parameters"
                  );

    BOOST_FORCEINLINE target_t operator()(Target const&, Values const&... vs) const BOOST_NOEXCEPT
    {
      return detail::sse_set<double>::do_( brigand::range<int,sizeof...(Values), 2>{}, vs...);
    }
  };

  //------------------------------------------------------------------------------------------------
  // make a pack of int64
  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename V0, typename V1)
                          , bs::sse2_
                          , bd::target_<bs::pack_<bd::ints64_<Target>,bs::sse_>>
                          , bd::scalar_<bd::unspecified_<V0>>
                          , bd::scalar_<bd::unspecified_<V1>>
                          )
  {
    using target_t  = typename Target::type;

    BOOST_FORCEINLINE
    target_t operator()(Target const&, V0 const& v0, V1 const& v1) const BOOST_NOEXCEPT
    {
      target_t t;
      insert<0>(t,v0);
      insert<1>(t,v1);
      return t;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename V0)
                          , bs::sse2_
                          , bd::target_<bs::pack_<bd::ints64_<Target>,bs::sse_>>
                          , bd::scalar_<bd::unspecified_<V0>>
                          )
  {
    using target_t  = typename Target::type;

    BOOST_FORCEINLINE target_t operator()(Target const&, V0 const& v0) const BOOST_NOEXCEPT
    {
      target_t t;
      insert<0>(t,v0);
      return t;
    }
  };

  //------------------------------------------------------------------------------------------------
  // make a pack of other integers
  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename... Values)
                          , bs::sse2_
                          , bd::target_<bs::pack_<bd::integer_<Target>,bs::sse_>>
                          , bd::scalar_<bd::unspecified_<Values>>...
                          )
  {
    using target_t  = typename Target::type;

    static_assert (     (sizeof...(Values) <= target_t::static_size)
                    &&  (is_power_of_2_<sizeof...(Values)>::value  )
                  , "boost::simd::make - Invalid number of parameters"
                  );

    BOOST_FORCEINLINE target_t operator()(Target const&, Values const&... vs) const BOOST_NOEXCEPT
    {
      using t_t = typename target_t::value_type;
      return detail::sse_set<t_t>::do_( brigand::range<int, sizeof...(Values)
                                                          , (16/sizeof(t_t))
                                                      >{}
                                      , static_cast<t_t>(vs)...
                                      );
    }
  };
} } }

#endif
