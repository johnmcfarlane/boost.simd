//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MEMORY_PREFERRED_ALIGNMENT_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_PREFERRED_ALIGNMENT_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/detail/dispatch/meta/value_of.hpp>
#include <type_traits>

namespace boost { namespace simd
{
  /*!
    @ingroup api-memory
    @defgroup memory-preferred_alignment preferred_alignment (class template)

    Obtains the best alignment for a given type vectorized with a given cardinal.

    @headerref{<boost/simd/memory/preferred_alignment.hpp>}

    @par Description

    @code
    template<typename Type, std::size_t Cardinal = 0>
    struct preferred_alignment
    @endcode

    Computes the preferred alignment for any type @c Type vectorized with a given cardinal @c Cardinal.

    If @c Cardinal is non null, the computed alignment is:
      - equals to @c pack<Type,Cardina>::alignment if @c Type is Vectorizable
      - equals to <tt>Type::alignment</tt> if @c Type is Vectorized
      - equals to either the preferred alignment of its underlying value type if available
        or its own natural alignment if @c Type is not Vectorizable,

    If @c Cardinal is unspecified, the current architecture is used to provide a default cardinal.

    @par Type Parameters

    | Name          | Description                               |
    |--------------:|:------------------------------------------|
    | **Type**      | Type for which alignment is requested     |
    | **Cardinal**  | Cardinal used to compute said alignment   |

    @par Type Requirements
    - If specified, **Cardinal** must be a non-zero power of two.
  **/

  namespace detail
  {
    template< typename T, std::size_t Cardinal
            , bool isArithmetic = std::is_arithmetic<T>::value
            >
    struct preferred_alignment_
    {
      static const std::size_t value = boost::simd::pack<T,Cardinal>::alignment;
    };

    template< typename T,std::size_t Cardinal>
    struct preferred_alignment_<T,Cardinal,false>
    {
      using value_t = boost::dispatch::value_of_t<T>;
      using base_t  = std::conditional< std::is_same<T,value_t>::value
                                      , nsm::size_t<alignof(T)>
                                      , preferred_alignment_<value_t,Cardinal>
                                      >;

      static const std::size_t value = base_t::type::value;
    };

    template<typename T> struct preferred_alignment_<T,0ULL,true>
    {
      static const std::size_t value = boost::simd::pack<T>::alignment;
    };

    template<typename T, std::size_t N, typename ABI, std::size_t Cardinal>
    struct preferred_alignment_<boost::simd::pack<T,N,ABI>, Cardinal, false>
    {
      static const std::size_t card = Cardinal ? Cardinal : N;
      static const std::size_t value = boost::simd::pack<T,card>::alignment;
    };
  }

  template<typename T, std::size_t Cardinal = 0ULL>
  struct  preferred_alignment
        : nsm::size_t<detail::preferred_alignment_<T,Cardinal>::value>
  {};
} }
#endif
