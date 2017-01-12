//==================================================================================================
/*!
  @file
  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_COMPLEX_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_COMPLEX_HPP_INCLUDED

namespace boost { namespace simd { namespace cmplx
{
  /*!
    @ingroup group-type
    @brief SIMD-compatible complex number abstraction

    @tparam Type Underlying floating point type
  **/
  template<typename Type> struct complex
  {
    /// @brief Default constructor
    complex() = default;

    /// @brief Explicitly construct a complex from a real part and settings its imaginary part to 0.
    template<typename T0>
    explicit complex(T0 const& rr) : real(rr), imag(T0(0)) {}

    /// @brief Construct a complex from a real and imaginary parts.
    template<typename T0, typename T1>
    complex(T0 const& rr, T1 const& ii) : real(rr), imag(ii) {}

    Type real, imag;
  };

  template<typename Type>
  auto operator==(complex<Type> const& z1,complex<Type> const& z2)
                -> decltype(z1.imag == z2.imag)
  {
    return z1.real == z2.real && z1.imag == z2.imag;
  }
} } }

#endif
