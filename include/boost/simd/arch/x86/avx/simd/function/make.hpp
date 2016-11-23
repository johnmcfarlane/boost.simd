//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/nope.hpp>

namespace boost { namespace simd { namespace detail
{
  //------------------------------------------------------------------------------------------------
  // Helper to generalize AVX make
  template<typename Base> struct avx_set;

  template<> struct avx_set<double>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m256d do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm256_setr_pd( static_cast<double>(vs)..., detail::nope<double,Z>()... );
    }
  };

  template<> struct avx_set<float>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m256 do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm256_setr_ps( static_cast<float>(vs)..., detail::nope<float,Z>()... );
    }
  };

  template<> struct avx_set<std::int64_t>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m256i do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm256_setr_epi64x( vs..., detail::nope<std::int64_t,Z>()... );
    }
  };

  template<> struct avx_set<std::int32_t>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m256i do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm256_setr_epi32( vs..., detail::nope<std::int32_t,Z>()... );
    }
  };

  template<> struct avx_set<std::int16_t>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m256i do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm256_setr_epi16( vs..., detail::nope<std::int16_t,Z>()... );
    }
  };

  template<> struct avx_set<char>
  {
    template<typename... Values, typename... Z> BOOST_FORCEINLINE
    static __m256i do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      return _mm256_setr_epi8( vs..., detail::nope<char,Z>()... );
    }
  };

  template<> struct avx_set<std::int8_t >   : avx_set<char>         {};
  template<> struct avx_set<std::uint8_t>   : avx_set<char>         {};
  template<> struct avx_set<std::uint16_t>  : avx_set<std::int16_t> {};
  template<> struct avx_set<std::uint32_t>  : avx_set<std::int32_t> {};
  template<> struct avx_set<std::uint64_t>  : avx_set<std::int64_t> {};
} } }

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // make a pack of double
  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename... Values)
                          , bs::avx_
                          , bd::target_<bs::pack_<bd::arithmetic_<Target>,bs::avx_>>
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
      return detail::avx_set<t_t>::do_( brigand::range<int, sizeof...(Values)
                                                          , (32/sizeof(t_t))
                                                      >{}
                                      , static_cast<t_t>(vs)...
                                      );
    }
  };
} } }

#endif
