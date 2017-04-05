//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#error This file is documentation-only and must not be included

/*!
  @ingroup group-concept-types

  A LogicalValue is a type which refines Vectorized or Vectorizable while providing boolean-like
  semantic.

  @par Requirements

  A type @c T satisfies LogicalValue if it refines Vectorized or Vectorizable and if:

  - boost::simd::scalar_of<T>::type satisfies Logical

  @par Example

  - @c boost::simd::logical<double>
  - @c boost::simd::pack<boost::simd::logical<char>>

**/
struct LogicalValue {};
