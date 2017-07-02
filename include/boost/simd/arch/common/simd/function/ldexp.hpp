//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LDEXP_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/detail/constant/limitexponent.hpp>
#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/rshl.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/if_minus.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/detail/constant/minexponent.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_less.hpp>
#endif

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  pack<T,N> vldexp_( pack<T,N> const & a0
                   , pack<U,N> const & a1
                   , std::false_type const &
                   ) BOOST_NOEXCEPT
  {
    return  rshl(a0, a1);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  pack<T,N> vldexp_( pack<T,N> const & a0
                   , pack<U,N> const & a1
                   , std::true_type const &
                   ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    using pi_t = as_si_t<pack<T,N>>;
    pi_t ik =  a1+Maxexponent<p_t>();
    ik = shift_left(ik, Nbmantissabits<T>());
    return a0*bitwise_cast<p_t>(ik);
  }

  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> ldexp_( BOOST_SIMD_SUPPORTS(simd_)
                            , pack<T,N> const & a0
                            , pack<U,N> const & a1
                            ) BOOST_NOEXCEPT
  {
    return vldexp_(a0, pack_cast<as_si_t<T>>(a1), std::is_floating_point<T>());
  }

//--------------------------------------------------------------------------------------------------------

  // pedantic
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vpldexp_( pack<T,N> const & a0
                    , as_si_t<pack<T,N>> const & a1
                    , std::false_type const &
                    ) BOOST_NOEXCEPT
  {
    return  rshl(a0, a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vpldexp_( pack<T,N> const & a0
                    , as_si_t<pack<T,N>> const & a1
                    , std::true_type const &
                    ) BOOST_NOEXCEPT
  {
      using pi_t = as_si_t<pack<T,N>>;
      using p_t = pack<T, N>;
      pi_t e = a1;
      p_t f = One<p_t>();
#ifndef BOOST_SIMD_NO_DENORMALS
      auto denormal = is_less(e, Minexponent<p_t>());
      e = if_minus(denormal, e, Minexponent<p_t>());
      f = if_else(denormal, Smallestposval<p_t>(), One<p_t>());
#endif
      auto test = is_equal(e, Limitexponent<p_t>());
      f = if_inc(test, f);
      e = if_dec(test, e);
      e += Maxexponent<p_t>();
      e = shift_left(e, Nbmantissabits<T>());
      return a0*bitwise_cast<p_t>(e)*f;

  }

  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> ldexp_( BOOST_SIMD_SUPPORTS(simd_)
                                    , pedantic_tag const &
                                    , pack<T,N> const & a0
                                    , pack<U,N> const & a1
                                    ) BOOST_NOEXCEPT
  {
    return vpldexp_(a0, pack_cast<as_si_t<T>>(a1), std::is_floating_point<T>());
  }


  //========================================================================================================================
  // mixed calls
  // regular
  template<typename T, std::size_t N,  typename U>
  BOOST_FORCEINLINE
  pack<T,N> vldexp_( pack<T,N> const & a0
                   , U a1
                   ,  std::false_type const &
                   ) BOOST_NOEXCEPT
  {
    return  rshl(a0, a1);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  pack<T,N> vldexp_( pack<T,N> const & a0
                   , U a1
                   ,  std::true_type const &
                   ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    auto ik =  as_si_t<T>(a1)+Maxexponent<T>();
    ik = shift_left(ik, Nbmantissabits<T>());
    return a0*p_t(bitwise_cast<T>(ik));
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N> ldexp_( BOOST_SIMD_SUPPORTS(simd_)
                            , pack<T,N> const & a0
                            , U a1
                            ) BOOST_NOEXCEPT
  {
    return vldexp_(a0, a1, std::is_floating_point<T>());
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N> ldexp_( BOOST_SIMD_SUPPORTS(simd_)
                            , T a0
                            , pack<U,N> const & a1
                            ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return ldexp_(p_t(a0), a1,std::is_floating_point<T>());
  }

  //========================================================================================================================
  // mixed calls
  // pedantic
  template<typename T, std::size_t N,  typename U>
  BOOST_FORCEINLINE
  pack<T,N> vpldexp_( pack<T,N> const & a0
                   , U a1
                   ,  std::false_type const &
                   ) BOOST_NOEXCEPT
  {
    return  rshl(a0, a1);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  pack<T,N> vpldexp_( pack<T,N> const & a0
                   , U a1
                   ,  std::true_type const &
                   ) BOOST_NOEXCEPT
  {
    using si_t = as_si_t<T>;
    using p_t = pack<T, N>;
    auto e = a1;
    p_t f = One<p_t>();
#ifndef BOOST_SIMD_NO_DENORMALS
    auto denormal =  is_less(e, Minexponent<si_t>());
    e = if_minus(denormal, e, Minexponent<si_t>());
    f = if_else(denormal, Smallestposval<p_t>(), One<p_t>());
#endif
    if (is_equal(e, Limitexponent<si_t>()))
    {
      f+= One<T>();
      e-= One<U>();
    }
    e += Maxexponent<T>();
    e = shift_left(e, Nbmantissabits<T>());
    return a0*(bitwise_cast<T>(e)*f);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  pack<T,N> ldexp_( BOOST_SIMD_SUPPORTS(simd_)
                  , pedantic_tag const &
                  , pack<T,N> const & a0
                  , U a1
                  ) BOOST_NOEXCEPT
  {
    return vldexp_(a0, a1, std::is_floating_point<T>());
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  pack<T,N> ldexp_( BOOST_SIMD_SUPPORTS(simd_)
                  , pedantic_tag const &
                  , T a0
                  , pack<U,N> const & a1
                  ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return ldexp_(p_t(a0), a1, std::is_floating_point<T>());
  }

  //emulation
  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  ldexp_( BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N,simd_emulation_> const & a0
        , pack<U,N,simd_emulation_> const & a1
        ) BOOST_NOEXCEPT
  {
    return map_to(ldexp, a0, a1);
  }

  //std decorator
  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> ldexp_( BOOST_SIMD_SUPPORTS(simd_)
                                    , std_tag const &
                                    , pack<T,N> const & a0
                                    , pack<U,N> const & a1
                                    ) BOOST_NOEXCEPT
  {
    return map_to(std_(ldexp), a0, a1);
  }

} } }

#endif
