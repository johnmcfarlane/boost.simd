//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LDEXP_HPP_INCLUDED
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/std.hpp>

#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/detail/constant/minexponent.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#endif
#include <boost/simd/detail/constant/limitexponent.hpp>
#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/function/pack_cast.hpp>
namespace boost { namespace simd { namespace detail
{
  template<typename T, typename U>
  BOOST_FORCEINLINE T sldexp_( T a0, U a1
                             , std::false_type const &
                             , std::false_type const &
                             ) BOOST_NOEXCEPT
  {
    return (a1>0)?(a0<<a1):(a0>>a1);
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T sldexp_( T a0, U a1
                             , std::true_type const &
                             , std::false_type const &
                             ) BOOST_NOEXCEPT
  {
    using i_t = bd::as_integer_t<T>;
    i_t ik =  a1+Maxexponent<T>();
    ik = shift_left(ik, Nbmantissabits<T>());
    return a0*bitwise_cast<T>(ik);
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T sldexp_( T a0, U a1
                             , std::false_type const &
                             , std::true_type const &
                             ) BOOST_NOEXCEPT
  {
    auto n =  toint(a1);
    return (n>0)?(a0<<n):(a0>>n);
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T sldexp_( T a0, U a1
                             , std::true_type const &
                             , std::true_type const &
                             ) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(is_flint(a1)||is_invalid(a1), "parameter is not a flint nor is invalid");
    return std::ldexp(a0, toint(a1));
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T ldexp_( BOOST_SIMD_SUPPORTS(cpu_)
                            , T a0, U a1
                            ) BOOST_NOEXCEPT
  {
    return sldexp_(a0, a1, std::is_floating_point<T>(), std::is_floating_point<U>());
  }



  // pedantic
  template<typename T, typename U>
  BOOST_FORCEINLINE T spldexp_( T a0, U a1
                              , std::false_type const &
                              , std::false_type const &
                              ) BOOST_NOEXCEPT
  {
    return (a1>0)?(a0<<a1):(a0>>a1);
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T spldexp_( T a0, U a1
                              , std::true_type const &
                              , std::false_type const &
                              ) BOOST_NOEXCEPT
  {
    using i_t = bd::as_integer_t<T>;
    i_t e =  a1;
    T f = One<T>();
#ifndef BOOST_SIMD_NO_DENORMALS
    if (BOOST_UNLIKELY((e < Minexponent<T>())))
    {
      e -= Minexponent<T>();
      f = Smallestposval<T>();
    }
#endif
    i_t b = (e == Limitexponent<T>());
    f += T(b);
    e -= b;
    e += Maxexponent<T>();
    e = shift_left(e, Nbmantissabits<T>());
    return a0*bitwise_cast<T>(e)*f;
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T spldexp_( T a0, U a1
                              , std::false_type const &
                              , std::true_type const &
                              ) BOOST_NOEXCEPT
  {
    auto n =  toint(a1);
    return (n>0)?(a0<<n):(a0>>n);
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T spldexp_( T a0, U a1
                              , std::true_type const &
                              , std::true_type const &
                              ) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(is_flint(a1)||is_invalid(a1), "parameter is not a flint nor is invalid");
    return std::ldexp(a0, toint(a1));
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T ldexp_( BOOST_SIMD_SUPPORTS(cpu_)
                            , pedantic_tag const &
                            , T a0, U a1
                            ) BOOST_NOEXCEPT
  {
    return spldexp_(a0, a1, std::is_floating_point<T>(), std::is_floating_point<U>());
  }

  //std decorator
  template<typename T, typename U,
           typename =  typename std::enable_if < std::is_floating_point<T>::value &&
                                std::is_integral<U>::value>::type>
  BOOST_FORCEINLINE T ldexp_( BOOST_SIMD_SUPPORTS(cpu_)
                            , std_tag const &
                            , T a0, U a1
                            ) BOOST_NOEXCEPT
  {
    return std::ldexp(a0, a1);
  }

} } }


#endif
