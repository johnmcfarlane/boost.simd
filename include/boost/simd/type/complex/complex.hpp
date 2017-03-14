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

#include <boost/simd/type/complex/function/abs.hpp>
#include <boost/simd/type/complex/function/arg.hpp>
#include <complex>
namespace boost { namespace simd { namespace cmplx
{
  /*!
    @ingroup group-type
    @brief SIMD-compatible complex number abstraction

    @tparam Type Underlying floating point type
  **/
  template<typename Type> struct complex
  {
    using value_type = Type;

    template<typename U> using rebind = complex<U>;

    /// @brief Default constructor
    complex() = default;

    /// @brief Explicitly construct a complex from a real part and settings its imaginary part to 0.
    template<typename T0>
    explicit complex(T0 const& rr) : real(static_cast<Type>(rr)), imag(0) {}


    /// @brief Construct a complex from a real and imaginary parts.
    template<typename T0, typename T1>
    complex(T0 const& rr, T1 const& ii) : real(static_cast<Type>(rr))
                                        , imag(static_cast<Type>(ii))
    {}

    /// @brief std::complex compatibility
    explicit complex(std::complex<Type> const& cc)
      : real(std::real(cc)), imag(std::imag(cc)) {}

    Type modulus()  const { return bs::abs(*this); }
    Type argument() const { return bs::arg(*this); }

    Type real, imag;
  };
} } }

#endif
