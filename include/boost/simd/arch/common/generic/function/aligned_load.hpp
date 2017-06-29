//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED

#include <boost/simd/mask.hpp>
#include <boost/pointee.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //------------------------------------------------------------------------------------------------
  //  arbitrary iterator without target type
  template<typename Iterator>
  BOOST_FORCEINLINE   auto aligned_load_( BOOST_SIMD_SUPPORTS(cpu_), Iterator ptr ) BOOST_NOEXCEPT
                  ->  decltype(*ptr)
  {
    return *ptr;
  }

  template<typename Iterator>
  BOOST_FORCEINLINE   auto aligned_load_( BOOST_SIMD_SUPPORTS(cpu_)
                                        , Iterator ptr, std::ptrdiff_t offset
                                        ) BOOST_NOEXCEPT
                  ->  decltype(*ptr)
  {
    std::advance(ptr,offset);
    return *ptr;
  }

  //------------------------------------------------------------------------------------------------
  //  masked pointer handling of offset
  template<typename T, typename M, bool Z>
  BOOST_FORCEINLINE T aligned_load_ ( BOOST_SIMD_SUPPORTS(cpu_)
                                    , detail::masked_pointer<T,M,Z> const& ptr
                                    , std::ptrdiff_t offset
                                    ) BOOST_NOEXCEPT
  {
    return simd::aligned_load( boost::simd::mask(ptr.get()+offset,ptr.mask(),ptr.value()) );
  }

  template<typename Target, typename T, typename M, bool Z>
  BOOST_FORCEINLINE Target aligned_load_( BOOST_SIMD_SUPPORTS(cpu_)
                                        , detail::masked_pointer<T,M,Z> const& ptr
                                        , std::ptrdiff_t offset
                                        , simd::as_<Target> const&
                                        ) BOOST_NOEXCEPT
  {
    return simd::aligned_load<Target>( boost::simd::mask(ptr.get()+offset,ptr.mask(),ptr.value()) );
  }

  //------------------------------------------------------------------------------------------------
  // aligned_load from an pointer, a misalignment and an integral offset
  template<typename Iterator, std::ptrdiff_t Misalignment>
  BOOST_FORCEINLINE auto aligned_load_( BOOST_SIMD_SUPPORTS(cpu_)
                                      , Iterator ptr
                                      , std::ptrdiff_t offset
                                      , std::integral_constant<std::ptrdiff_t,Misalignment> const&
                                      ) BOOST_NOEXCEPT
                ->  decltype( simd::aligned_load<Misalignment>(ptr) )
  {
    std::advance(ptr,offset);
    return simd::aligned_load<Misalignment>(ptr);
  }

  template<typename Target, typename Iterator, std::ptrdiff_t Misalignment>
  BOOST_FORCEINLINE Target aligned_load_( BOOST_SIMD_SUPPORTS(cpu_)
                                        , Iterator ptr
                                        , std::ptrdiff_t offset
                                        , std::integral_constant<std::ptrdiff_t,Misalignment> const&
                                        , simd::as_<Target> const&
                                        ) BOOST_NOEXCEPT
  {
    std::advance(ptr,offset);
    return simd::aligned_load<Target,Misalignment>(ptr);
  }
} } }

#endif
