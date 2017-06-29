//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_ALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_ALIGNED_LOAD_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/as.hpp>
#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_MAKE_CALLABLE(aligned_load_,aligned_load_);

  // -----------------------------------------------------------------------------------------------
  // aligned_load without specific target
  template<typename Pointer, typename... Opts>
  BOOST_FORCEINLINE auto aligned_load(Pointer const& p, Opts&&... o)
                ->  decltype(aligned_load_( p, std::forward<Opts>(o)... ))
  {
    return aligned_load_( p, std::forward<Opts>(o)... );
  }

  // -----------------------------------------------------------------------------------------------
  // aligned_load with a specific target
  template<typename T, typename Pointer, typename... Opts>
  BOOST_FORCEINLINE T aligned_load(Pointer const& p, Opts&&... o)
  {
    return aligned_load_( p, std::forward<Opts>(o)..., boost::simd::as_<T>() );
  }

  // -----------------------------------------------------------------------------------------------
  // aligned_load without target and with misalignment
  template<std::ptrdiff_t Misalignment, typename Pointer, typename... Opts>
  BOOST_FORCEINLINE auto aligned_load(Pointer const& p, Opts&&... o)
                ->  decltype( aligned_load_ ( p, std::forward<Opts>(o)...
                                            , std::integral_constant<std::ptrdiff_t,Misalignment>{}
                                            )
                            )
  {
    return aligned_load_( p, std::forward<Opts>(o)...
                        , std::integral_constant<std::ptrdiff_t,Misalignment>{}
                        );
  }

  // -----------------------------------------------------------------------------------------------
  // aligned_load with target and with misalignment
  template<typename T, std::ptrdiff_t Misalignment, typename Pointer, typename... Opts>
  BOOST_FORCEINLINE T aligned_load(Pointer const& p, Opts&&... o)
  {
    return aligned_load_( p, std::forward<Opts>(o)...
                        , std::integral_constant<std::ptrdiff_t,Misalignment>{}
                        , boost::simd::as_<T>()
                        );
  }
} }

#endif
