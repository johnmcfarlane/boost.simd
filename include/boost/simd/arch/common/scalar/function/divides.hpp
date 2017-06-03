//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DIVIDES_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/hierarchy.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>

#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4723) // potential divide by 0
#endif

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // Regular case
  template<typename T>
  BOOST_FORCEINLINE T divides_(BOOST_SIMD_SUPPORTS(cpu_)
                              , T const& a
                              , T const& b) BOOST_NOEXCEPT
  {
    return a/b;
  }

  // -----------------------------------------------------------------------------------------------
  // Saturated cases
  template<typename T> BOOST_FORCEINLINE
  T sdivides_( T const& a, T const& b
             , detail::case_<0> const& ) BOOST_NOEXCEPT //floating
  {
    // IEEE case
    return a/b;
  }

  template<typename T> BOOST_FORCEINLINE
  T sdivides_ ( T const& a0, T const& a1
              , detail::case_<1> const // signed integral
              ) BOOST_NOEXCEPT
  {
    typedef bd::as_unsigned_t<T> utype;
    T const aa0 = a0 + !((a1 + One<T>()) | ((utype)a0 + Valmin<T>()));
    if (a1)
      return aa0/a1;
    else if (a0)
      return Valmax<T>() + ((utype)a0 >> (sizeof(T)*CHAR_BIT-1));
    else
      return Zero<T>();
  }

  template<typename T> BOOST_FORCEINLINE
  T sdivides_( T const& a0, T const& a1, detail::case_<2> const&) BOOST_NOEXCEPT // unsigned integral
  {
    return a1 ? a0/a1 : genmask(a0);
  }


  template<typename T>
  BOOST_FORCEINLINE
  T divides_(BOOST_SIMD_SUPPORTS(cpu_)
            , saturated_tag const&, T const& a, T const& b) BOOST_NOEXCEPT
  {
    return sdivides_ ( a ,b, fsu_picker<T>());
  }

} } }

#ifdef BOOST_MSVC
  #pragma warning(pop)
#endif

#endif
