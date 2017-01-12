//==================================================================================================
/*!
  @file
  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_IO_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_IO_HPP_INCLUDED

#include <iostream>

namespace boost { namespace simd { namespace cmplx
{
    /// @brief Stream insertion for complex
  template <typename T>
  std::ostream& operator<<(std::ostream& os, cmplx::complex<T> const& z)
  {
    return os << z.real << " + i * " << z.imag;
  }
} } }

#endif


