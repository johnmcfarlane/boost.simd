//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_LOG10_EHI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_LOG10_EHI_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Generates constant log10_ehi.This constant is coupled with Log10_elo and is
    used in the float logarithms computations
    We have double(log10_ehi<float>())+double(Log10_elo<float>()) == Log_10(e)

    @par Semantic:

    @code
    T r = log10_ehi<T>();
    @endcode


*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type log10_ehi_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X3EDE0000U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type log10_ehi_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X3FDBCB7B1526E510ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type log10_ehi_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type log10_ehi_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return log10_ehi_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(log10_ehi_, log10_ehi);

  template<typename T>
  BOOST_FORCEINLINE T Log10_ehi(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return log10_ehi( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Log10_ehi() BOOST_NOEXCEPT
  {
    return log10_ehi( boost::simd::as_<T>{} );
  }
} }

#endif
