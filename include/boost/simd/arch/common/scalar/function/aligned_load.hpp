//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED

#include <boost/simd/mask.hpp>
#include <boost/simd/as.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //------------------------------------------------------------------------------------------------
  // Iterator with target/offset
  template<typename Target, typename Iterator>
  BOOST_FORCEINLINE Target aligned_load_( BOOST_SIMD_SUPPORTS(cpu_)
                                        , Iterator ptr, simd::as_<Target> const&
                                        ) BOOST_NOEXCEPT
  {
    return static_cast<Target>(simd::aligned_load(ptr));
  }

  template<typename Target, typename Iterator>
  BOOST_FORCEINLINE Target aligned_load_( BOOST_SIMD_SUPPORTS(cpu_)
                                        , Iterator ptr
                                        , std::ptrdiff_t offset
                                        , simd::as_<Target> const&
                                        ) BOOST_NOEXCEPT
  {
    std::advance(ptr,offset);
    return static_cast<Target>(simd::aligned_load(ptr));
  }

  //------------------------------------------------------------------------------------------------
  // Misaligned Iterator
  template<typename Iterator, std::ptrdiff_t Misalignment>
  BOOST_FORCEINLINE   auto aligned_load_( BOOST_SIMD_SUPPORTS(cpu_)
                                        , Iterator ptr
                                        , std::integral_constant<std::ptrdiff_t,Misalignment> const&
                                        ) BOOST_NOEXCEPT
                  ->  decltype(*ptr)
  {
    return simd::aligned_load(ptr,-Misalignment);
  }

  template<typename Target, typename Iterator, std::ptrdiff_t Misalignment>
  BOOST_FORCEINLINE Target aligned_load_( BOOST_SIMD_SUPPORTS(cpu_)
                                        , Iterator ptr
                                        , std::integral_constant<std::ptrdiff_t,Misalignment> const&
                                        , simd::as_<Target> const&
                                        ) BOOST_NOEXCEPT
  {
    return simd::aligned_load<Target>(ptr,-Misalignment);
  }

  //------------------------------------------------------------------------------------------------
  //  masked pointer
  template<typename T, typename M, bool Z>
  BOOST_FORCEINLINE T aligned_load_ ( BOOST_SIMD_SUPPORTS(cpu_)
                                    , detail::masked_pointer<T,M,Z> const& ptr
                                    ) BOOST_NOEXCEPT
  {
    return ptr.mask() ? boost::simd::aligned_load(ptr.get()) : T(ptr.value());
  }

  template<typename Target, typename T, typename M, bool Z>
  BOOST_FORCEINLINE Target aligned_load_( BOOST_SIMD_SUPPORTS(cpu_)
                                        , detail::masked_pointer<T,M,Z> const& ptr
                                        , simd::as_<Target> const&
                                        ) BOOST_NOEXCEPT
  {
    return static_cast<Target>( simd::aligned_load(ptr) );
  }
} } }

#endif
