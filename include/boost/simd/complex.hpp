//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_COMPLEX_HPP_INCLUDED
#define BOOST_SIMD_COMPLEX_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-api
    @defgroup group-complex Complex functions

    These functions provide scalar and SIMD implementation for classical complex functions.

          All the function of the stdlibc++ have been implemented and a couple of other.

          A proper type boost::simd::complex is used that can be freely mixed with the real underlying type in operator and
          functions,  also, in the scalar case, it can be constructed from an std::complex type.

          The SIMD routines are used with `boost::simd::complex<boost::simd::pack<T>>` (i.e. in a non
          interlaced way) **NOT** `boost::simd::packboost::simd::complexT>>` (i.e interlaced real/imaginary data)
          This is done to ensure best simd performances.

          Of course load and store from and to interlaced/not-interlaced data are provided (TODO)

          Some functors as boost::simd::sqrt behave differently if the input is real or complex.

          Let `namespace bs = boost::simd; `.

          For instance

              - `bs::sqrt(-1.0)` will return `Nan<double>()`
              - `bs::sqrt(bs::complex<double>(-1.0, 0.0)` will return (0.0, 1.0);

           In any case the complex behaviour can be ensured by calling bs::cmplx::sqrt

               - `bs::cmplx::sqrt(-1.0)` will return (0.0, 1.0);
               - `bs::cmplx::sqrt(bs::complex<double>(-1.0, 0.0)` will also return (0.0, 1.0);

           Involved functions are [sqrt](@ref complex-sqrt), [log] (@ref complex-log), [log10] (@ref complex-log10), [pow] (@ref complex-pow),
           [acos] (@ref complex-acos), [asin] (@ref complex-asin), [acosh] (@ref complex-acosh), [atanh] (@ref complex-atanh),  i.e. all
           complex functions which restricted to the real axis are not surjective (onto).

           In fact all implemented functions for which some parts of the real axis would need to
           return complex value to be consistenly defined.

    - Operators


       <center>
          | Name                                              | op  | arity |
          |---------------------------------------------------|-----|-------|
          | [divides](@ref complex-divides)                   | /   |  2    |
          | [if_else](@ref complex-if_else)                   | NA  |  3    |
          | [is_equal](@ref complex-is_equal)                 | ==  |  2    |
          | [is_not_equal](@ref complex-is_not_equal)         | !=  |  2    |
          | [minus](@ref complex-minus)                       | -   |  2    |
          | [multiplies](@ref complex-multiplies)             | *   |  2    |
          | [plus](@ref complex-plus)                         | +   |  2    |
          | [unary_minus](@ref complex-unary_minus)           | -   |  1    |
          | [unary_plus](@ref complex-unary_plus)             | +   |  1    |
       </center>

       Arity 2 operators can mix simd/scalar types real/complex types (but not different base types,
       except real scalars that are casted appropriately). The result follows the motto: 'the bigger win'

       Compound assignements are also available.

    -  Basic functions

       <center>
         |                                     |                              |                             |                           |                                |
         |:-----------------------------------:|:----------------------------:|:---------------------------:|:-------------------------:|:------------------------------:|
         | [abs](@ref complex-abs)             | [arg](@ref complex-arg)      |  [conj](@ref complex-conj)  | [imag](@ref complex-imag) | [mul_i](@ref complex-mul_i)    |
         | [mul_mi](@ref complex-mul_mi)       | [polar](@ref complex-polar)  |  [proj](@ref complex-proj)  | [real](@ref complex-real) | [sqr](@ref complex-sqr)        |
         | [sqr_abs](@ref complex-sqr_abs)     | [sqrt](@ref complex-sqrt)    |                             |                           |                                |
       </center>

        - `std::norm` is implemented under the name [sqr_abs](@ref complex-sqr_abs) because the name `norm` is deceiving.
          The sum of the squares of the real and imaginary parts of a complex is not a mathematical norm,
          The `abs` function defines a mathematical norm.

        - `mul_i` and  `mul_mi` respectively return their input multiplied by i (respectively -i) (with i*i ==  -1)

    -  Predicates

       <center>
         |                  |                 |                   |              |              |
         |:----------------:|:---------------:|:-----------------:|:------------:|:------------:|
         | [is_equal]   (@ref complex-is_equal)     |[is_eqz]  (@ref complex-is_eqz)      |[is_finite]    (@ref complex-is_finite)     |[is_imag] (@ref  complex-is_imag)  |[is_inf]  (@ref complex-is_inf)   |
         | i[s_invalid] (@ref complex-is_invalid)   |[is_nan]  (@ref complex-is_nan)      |[is_not_equal] (@ref complex-is_not_equal)  |[is_real] (@ref  complex-is_real)  |              |
       </center>

         - all these predicates, when applied to complex data return logical values associated to their (real) base type.

    - Exponential functions

        <center>
         |                 |                 |               |                  |                 |
         |:---------------:|:---------------:|:-------------:|:----------------:|:---------------:|
         | [exp] (@ref complex-exp)  | [exp_i] (@ref complex-exp_i)     | [exp_ipi] (@ref complex-exp_ipi)  | [log] (@ref complex-log)        | [log10] (@ref complex-log10)      |
         | [pow] (@ref complex-pow)  |                                  |                                   |                                 |                                   |
        </center>

          - `exp_i(x)` computes  `exp(mul_i(x))`
          - `exp_ipi(x)` computes  `exp(mul_i(x)*pi)`

    - Trigonometric functions

      <center>
        |             |             |             |             |                 |
        |:-----------:|:-----------:|:-----------:|:-----------:|:---------------:|
        | [acos]   (@ref complex-acos)    |  [asin] (@ref complex-asin)   | [atan]  (@ref complex-atan)   | [cos] (@ref complex-cos)     | [sin]   (@ref complex-sin)         |
        | [sincos] (@ref complex-sincos)  |  [tan]  (@ref complex-tan)    |             |             |                 |
      </center>

        - As in the real case sincos compute simultaneously the sin and the cos of the input as lower cost.

    - hyperbolic functions

      <center>
        |             |             |             |             |                 |
        |:-----------:|:-----------:|:-----------:|:-----------:|:---------------:|
        | [acosh]   (@ref complex-acosh)    |  [asinh] (@ref complex-asinh)   | [atanh]  (@ref complex-atanh)   | [cosh] (@ref complex-cosh)     | [sinh]   (@ref complex-sinh)         |
        | [sinhcosh] (@ref complex-sinhcosh)  |  [tanh]  (@ref complex-tanh)    |             |             |                 |
      </center>

      - As in the real case sinhcosh compute simultaneously the sinh and the cosh of the input as lower cost.


  **/
} }

#include <boost/simd/type/complex/function/abs.hpp>
#include <boost/simd/type/complex/function/acos.hpp>
#include <boost/simd/type/complex/function/acosh.hpp>
#include <boost/simd/type/complex/function/asin.hpp>
#include <boost/simd/type/complex/function/asinh.hpp>
#include <boost/simd/type/complex/function/atan.hpp>
#include <boost/simd/type/complex/function/atanh.hpp>
#include <boost/simd/type/complex/function/arg.hpp>
#include <boost/simd/type/complex/function/conj.hpp>
#include <boost/simd/type/complex/function/cos.hpp>
#include <boost/simd/type/complex/function/cosh.hpp>
#include <boost/simd/type/complex/function/exp.hpp>
#include <boost/simd/type/complex/function/exp_i.hpp>
#include <boost/simd/type/complex/function/exp_mi.hpp>
#include <boost/simd/type/complex/function/imag.hpp>
#include <boost/simd/type/complex/function/log.hpp>
#include <boost/simd/type/complex/function/log10.hpp>
#include <boost/simd/type/complex/function/multiplies.hpp>
#include <boost/simd/type/complex/function/mul_i.hpp>
#include <boost/simd/type/complex/function/mul_mi.hpp>
#include <boost/simd/type/complex/function/polar.hpp>
#include <boost/simd/type/complex/function/proj.hpp>
#include <boost/simd/type/complex/function/real.hpp>
#include <boost/simd/type/complex/function/sin.hpp>
#include <boost/simd/type/complex/function/sinh.hpp>
#include <boost/simd/type/complex/function/sqr_abs.hpp>
#include <boost/simd/type/complex/function/sqr.hpp>
#include <boost/simd/type/complex/function/sqrt.hpp>
#include <boost/simd/type/complex/function/tan.hpp>
#include <boost/simd/type/complex/function/tanh.hpp>
#include <boost/simd/type/complex/function/unary_minus.hpp>
#include <boost/simd/type/complex/function/unary_plus.hpp>


#endif
