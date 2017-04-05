//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MASK_HPP_INCLUDED
#define BOOST_SIMD_MASK_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/hierarchy/unspecified.hpp>
#include <boost/simd/detail/dispatch/hierarchy_of.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup api-memory
    @defgroup memory-mask mask (function template)

    Tag a pointer as being masked by one or more boolean variables.

    @headerref{<boost/simd/mask.hpp>}

    @par Description

    1.  @code
        template<typename Type,typename Mask, typename U>
        implementation-defined mask(Type* ptr, Mask const& status, U const& def)
        @endcode

    2.  @code
        template<typename Type,typename Mask>
        implementation-defined mask(Type* ptr, Mask const& status)
        @endcode

    1.  Wraps a pointer, a LogicalValue mask and a default value in an implementation defined object
        that is suitable to be passed to function handling memory operation with masked pointer.

    2.  Wraps a pointer and a LogicalValue mask in an implementation defined object that is suitable
        to be passed to function handling memory operation with masked pointer.

    @par Parameters

    | Name               | Description                                                        |
    |-------------------:|:-------------------------------------------------------------------|
    | **ptr**            | the pointer to mask                                                |
    | **status**         | Condition associated to the pointer                                |
    | **def**            | Value to return when a value is accessed where **status** is false |

    @par Return Value
    An implementation-defined object that represents the pointer and its associated mask.

    @par Requirements
    - @c Type and @c U models Value
    - @c Mask models LogicalValue

    @par Related components
      - @ref memory-load
      - @ref memory-store

    @par Example
    @snippet mask.cpp mask

    Possible output

    @snippet mask.txt mask
  **/

  namespace detail
  {
    // Hint-type for masked pointer
    template<typename T, typename Mask, bool isZero = false> struct masked_pointer
    {
      using pointer       = T*;
      using element_type  = T;
      using mask_type     = Mask;

      BOOST_FORCEINLINE operator      pointer() const BOOST_NOEXCEPT { return ptr;      }
      BOOST_FORCEINLINE pointer       get()     const BOOST_NOEXCEPT { return ptr;      }
      BOOST_FORCEINLINE Mask          mask()    const BOOST_NOEXCEPT { return status;   }
      BOOST_FORCEINLINE element_type  value()   const BOOST_NOEXCEPT { return fallback; }

      pointer       ptr;
      element_type  fallback;
      Mask          status;
    };
  }

  template<typename T, typename U, typename Mask> BOOST_FORCEINLINE
  detail::masked_pointer<T,Mask> mask(T* ptr, Mask const& status, U const& def)
  {
    return detail::masked_pointer<T,Mask>{ptr,T(def),status};
  }

  template<typename T, typename Mask>
  BOOST_FORCEINLINE detail::masked_pointer<T,Mask, true> mask(T* ptr, Mask const& status)
  {
    return detail::masked_pointer<T,Mask, true>{ptr,T{0},status};
  }
} }

//--------------------------------------------------------------------------------------------------
// Hierarchy and dispatch helpers for masked_pointer
namespace boost { namespace dispatch
{
#if defined(DOXYGEN_ONLY)
  template<typename T, typename Zero>
  struct masked_pointer_
  {
    using parent = masked_pointer_<typename T::parent, Zero>;
  };
#else
  template<typename T, typename Zero>
  struct masked_pointer_ : masked_pointer_<typename T::parent, Zero>
  {
    using parent = masked_pointer_<typename T::parent, Zero>;
  };

  template<typename T, typename Zero>
  struct  masked_pointer_<unspecified_<T>,Zero> : unspecified_<T>
  {
    using parent = unspecified_<T>;
  };
#endif

  namespace ext
  {
    template<typename T, typename Mask, bool Zero, typename Origin>
    struct hierarchy_of< boost::simd::detail::masked_pointer<T,Mask,Zero>, Origin >
    {
      using base = typename boost::simd::detail::masked_pointer<T,Mask,Zero>::element_type;
      using type = masked_pointer_< boost::dispatch::hierarchy_of_t<base,Origin>
                                  , nsm::bool_<Zero>
                                  >;
    };
  }
} }

#endif
