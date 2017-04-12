//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_PLUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_PLUS_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/saturate.hpp>
#include <boost/simd/detail/meta/pick.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE
  T plus_(BOOST_SIMD_SUPPORTS(boost::dispatch::cpu_), T const& a, T const& b) BOOST_NOEXCEPT
  {
    return a+b;
  }

  // -----------------------------------------------------------------------------------------------
  // Saturated cases
  template<typename T, typename Sz> BOOST_FORCEINLINE
  T splus_( T const& a, T const& b, detail::case_<0> const&, Sz const& ) BOOST_NOEXCEPT
  {
    // IEEE case
    return a + b;
  }

  template<typename T> BOOST_FORCEINLINE
  T splus_ ( T const& a, T const& b
                    , detail::case_<1> const&, tt_::true_type const&
                    ) BOOST_NOEXCEPT
  {
    // large signed integral case
    using utype = typename tt_::make_unsigned<T>::type;
    enum sizee { value = sizeof(T)*CHAR_BIT-1 };

    utype ux = a, uy = b;
    utype res = ux + uy;

    ux = (ux >> sizee::value) + Valmax<T>();

    if( T((ux ^ uy) | ~(uy ^ res)) >= T(0)) return ux;
    return static_cast<T>(res);
  }

  template<typename T> BOOST_FORCEINLINE
  T splus_ ( T const& a, T const& b
                    , detail::case_<1> const&, tt_::false_type const&
                    ) BOOST_NOEXCEPT
  {
    // small signed integral case
    auto r = a+b;
    return static_cast<T>(saturate<T>(r));
  }

  template<typename T> BOOST_FORCEINLINE
  T splus_( T const& a, T const& b, detail::case_<2> const&, tt_::true_type const& ) BOOST_NOEXCEPT
  {
    // large unsigned integral case
    T r  = a + b;
    return r | -(r < a);
  }

  template<typename T> BOOST_FORCEINLINE
  T splus_( T const& a, T const& b, detail::case_<2> const&, tt_::false_type const& ) BOOST_NOEXCEPT
  {
    // small unsigned integral case - use C promotion then clamp
    auto        r   = a+b;
    decltype(r) mx  = boost::simd::Valmax<T>();
    return static_cast<T>(std::min(mx,r));
  }

  template<typename T>
  BOOST_FORCEINLINE
  T plus_ ( BOOST_SIMD_SUPPORTS(boost::dispatch::cpu_)
          , saturated_tag const&, T const& a, T const& b
          ) BOOST_NOEXCEPT
  {
    return splus_ ( a ,b
                  , typename detail::pick <T, tt_::is_floating_point
                                            , tt_::is_signed
                                            , tt_::is_unsigned
                                          >::type{}
                  , tt_::integral_constant<bool,(sizeof(T) >= 4)>{}
                  );
  }
} } }

#endif
