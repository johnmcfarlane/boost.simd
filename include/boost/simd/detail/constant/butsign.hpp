//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CONSTANT_BUTSIGN_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CONSTANT_BUTSIGN_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/as.hpp>

  /*
    @ingroup group-constant

    Generate value with all bits set to one except the most significant
    set to zero (the sign bit)

     @return The Butsign constant for the proper type

  */

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type butsign_( as_<Type> const&, as_<double> const&) BOOST_NOEXCEPT
    {
      return Type{bitwise_cast<double>(0xEFFFFFFFFFFFFFFFULL)};
    }
    template<typename Type>
    BOOST_FORCEINLINE Type butsign_( as_<Type> const&, as_<float> const&) BOOST_NOEXCEPT
    {
      return Type{bitwise_cast<float>(0xEFFFFFFFU)};
    }
    template<typename Type>
    BOOST_FORCEINLINE Type butsign_( as_<Type> const&, as_<uint8_t> const& ) BOOST_NOEXCEPT
    {
      return Type{127};
    }
    template<typename Type>
    BOOST_FORCEINLINE Type butsign_( as_<Type> const&, as_<uint16_t> const& ) BOOST_NOEXCEPT
    {
      return Type{32767};
    }
    template<typename Type>
    BOOST_FORCEINLINE Type butsign_( as_<Type> const&, as_<uint32_t> const& ) BOOST_NOEXCEPT
    {
      return Type{2147483647};
    }
    template<typename Type>
    BOOST_FORCEINLINE Type butsign_( as_<Type> const&, as_<uint64_t> const& ) BOOST_NOEXCEPT
    {
      return Type{9223372036854775807ULL};
    }
    template<typename Type>
    BOOST_FORCEINLINE Type butsign_( as_<Type> const&, as_<int8_t> const& ) BOOST_NOEXCEPT
    {
      return Type{127};
    }
    template<typename Type>
    BOOST_FORCEINLINE Type butsign_( as_<Type> const&, as_<int16_t> const& ) BOOST_NOEXCEPT
    {
      return Type{32767};
    }
    template<typename Type>
    BOOST_FORCEINLINE Type butsign_( as_<Type> const&, as_<int32_t> const& ) BOOST_NOEXCEPT
    {
      return Type{2147483647};
    }
    template<typename Type>
    BOOST_FORCEINLINE Type butsign_( as_<Type> const&, as_<int64_t> const& ) BOOST_NOEXCEPT
    {
      return Type{9223372036854775807LL};
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type butsign_(BOOST_SIMD_SUPPORTS(Arch), as_<Type> const& tgt) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return butsign_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(butsign_, butsign);

  template<typename T>
  BOOST_FORCEINLINE auto Butsign(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    butsign( tgt )
  )

  template<typename T> BOOST_FORCEINLINE auto Butsign() BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    butsign( boost::simd::as_<T>{} )
  )
} }

#endif
