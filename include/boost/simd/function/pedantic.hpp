//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_PEDANTIC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_PEDANTIC_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/decorator.hpp>
#include <boost/simd/detail/dispatch.hpp>

/*!
  @ingroup group-decorator
  @defgroup decorator-pedantic pedantic_ (function object)

  Imbue a **@projectname** function object to have pendantic behavior.

  @headerref{<boost/simd/function/pedantic.hpp>}

  @par Description

  @code
  Callable pedantic_(Callable const& f);
  @endcode

  Returns a function object performing the same computation as `f` but with additional
  provisions with respect to precision and/or handling of corner cases.

  Depending on the function object being affected, the additional code can either be provided as
  a convenience or, if any standard exists, the function object will be made as conformant as
  possible. Usually, the standard followed is the C++ standard but for some functions, an external
  one can be followed.

  These additional provisions may reduce the function object performance but improve its
  numerical behavior.

  @par Parameters

  | Name    | Description                                              |
  |:--------|:---------------------------------------------------------|
  | **f**   | a @cppconcept{Callable} which behavior is to be altered  |

  @par Return Value
  A @cppconcept{Callable} performing a similar computation than `f` but with a different code path
  for handling function-specific scenarios.

  @par Example
  @code
  auto r = boost::simd::pedantic_(boost::simd::hypot)(3.f, 3.1e9f);
  @endcode
**/

#if !defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  struct pedantic_tag : decorator_<pedantic_tag>
  {
    using parent = decorator_<pedantic_tag>;
  };

  const detail::decorator<pedantic_tag> pedantic_ = {};
} }
#endif

#endif
