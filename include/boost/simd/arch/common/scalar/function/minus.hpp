//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MINUS_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/saturate.hpp>
#include <boost/simd/detail/meta/pick.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE T minus_(BOOST_SIMD_SUPPORTS(cpu_), T const& a, T const& b) BOOST_NOEXCEPT
  {
    return a-b;
  }

  // -----------------------------------------------------------------------------------------------
  // Saturated cases
  template<typename T, typename Sz> BOOST_FORCEINLINE
  T sminus_( T const& a, T const& b, detail::case_<0> const&, Sz const& ) BOOST_NOEXCEPT
  {
    // IEEE case
    return a - b;
  }

  template<typename T> BOOST_FORCEINLINE
  T sminus_ ( T const& a, T const& b
            , detail::case_<1> const&, tt_::true_type const&
            ) BOOST_NOEXCEPT
  {
    // large signed integral case
      using un_t = typename tt_::make_unsigned<T>::type;
      enum sizee { value = sizeof(T)*CHAR_BIT-1 };

      un_t ux = a;
      un_t uy = b;
      un_t res = ux - uy;

      ux = (ux >> value) + Valmax<T>();

      if(T((ux ^ uy) & (ux ^ res)) < Zero<T>()) res = ux;

      return res;
  }

  template<typename T> BOOST_FORCEINLINE
  T sminus_ ( T const& a, T const& b
            , detail::case_<1> const&, tt_::false_type const&
            ) BOOST_NOEXCEPT
  {
    // small signed integral case
    auto r = a-b;
    return static_cast<T>(saturate<T>(r));
  }

  template<typename T> BOOST_FORCEINLINE
  T sminus_( T const& a0, T const& a1, detail::case_<2> const&, tt_::true_type const& ) BOOST_NOEXCEPT
  {
    // large unsigned integral case
    T res = a0 - a1;
    res &= -(res <= a0);

    return res;
  }

  template<typename T> BOOST_FORCEINLINE
  T sminus_( T const& a0, T const& a1, detail::case_<2> const&, tt_::false_type const& ) BOOST_NOEXCEPT
  {
    // small unsigned integral case (the same)
    T res = a0 - a1;
    res &= -(res <= a0);

    return res;
  }

  template<typename T>
  BOOST_FORCEINLINE
  T minus_(BOOST_SIMD_SUPPORTS(cpu_), saturated_tag const&, T const& a, T const& b) BOOST_NOEXCEPT
  {
    return sminus_ ( a ,b
                  , typename detail::pick <T, tt_::is_floating_point
                                            , tt_::is_signed
                                            , tt_::is_unsigned
                                          >::type{}
                  , tt_::integral_constant<bool,(sizeof(T) >= 4)>{}
                  );
  }
} } }

#endif
