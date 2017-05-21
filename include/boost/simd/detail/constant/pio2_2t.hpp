//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_PIO2_2T_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_PIO2_2T_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/meta/value_type.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/as.hpp>
#include <type_traits>
/*
group-constant

    Constant used in modular computation involving \f$\pi\f$

    @par Semantic:

    For type T:

    @code
    T r = Pio2_2t<T>();
    @endcode

    @return a value of type T

*/

namespace boost { namespace simd {
  namespace detail
  {
    template<typename Type>
    BOOST_FORCEINLINE Type pio2_2t_( as_<Type> const&, as_<float> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X2E85A308U)};
    }

    template<typename Type>
    BOOST_FORCEINLINE Type pio2_2t_( as_<Type> const&, as_<double> const& ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return Type{bitwise_cast<base>(0X3BA3198A2E037073ULL)};
    }

    template<typename Type, typename Value>
    BOOST_FORCEINLINE Type pio2_2t_( as_<Type> const&, as_<Value> const& ) BOOST_NOEXCEPT
    {
      return Type(0);
    }

    template<typename Type, typename Arch>
    BOOST_FORCEINLINE Type pio2_2t_ ( BOOST_SIMD_SUPPORTS(Arch)
                                   , as_<Type> const& tgt
                                   ) BOOST_NOEXCEPT
    {
      using base = detail::value_type_t<Type>;
      return pio2_2t_( tgt, as_<base>{});
    }
  }

  BOOST_SIMD_MAKE_CALLABLE(pio2_2t_, pio2_2t);

  template<typename T>
  BOOST_FORCEINLINE T Pio2_2t(boost::simd::as_<T> const& tgt) BOOST_NOEXCEPT
  {
    return pio2_2t( tgt );
  }

  template<typename T> BOOST_FORCEINLINE T Pio2_2t() BOOST_NOEXCEPT
  {
    return pio2_2t( boost::simd::as_<T>{} );
  }
} }

#endif
