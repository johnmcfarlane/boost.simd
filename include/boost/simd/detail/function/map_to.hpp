//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_FUNCTION_MAP_TO_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_FUNCTION_MAP_TO_HPP_INCLUDED

#include <boost/simd/detail/diagnostic.hpp>
#include <boost/simd/detail/meta/storage_kind.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/slice.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename Func, typename Pi, typename... Pn>
  struct automapper
  {
    // Use the very first pack as reference
    using traits              = typename Pi::traits;

    // We build the return pack as a pack of same cardinal but which type is the scalar return
    // type of functor applied to the input parameter value type.
    using return_type         = decltype(Func()(value_type_t<Pi>(),value_type_t<Pn>()...));
    using result_type         = typename Pi::template rebind<return_type>;
    using result_storage_type = typename result_type::storage_type;
    using result_traits       = typename result_type::traits;

    // We need to iterate over output type cardinal to fill it
    using element_range       = nsm::range<std::size_t, 0, Pi::static_size>;

    // Constructing the output depends on the storage_kind of all the inputs
    struct storage_checker
    {
      template <typename S, typename E>
      struct apply : nsm::bool_ <  S::value
                                && std::is_same<storage_kind_t<E>, aggregate_storage>::value
                                >
      {};
    };

    using storage_kind  = nsm::fold < nsm::list<typename Pn::traits...>
                                    , tt_::true_type
                                    , storage_checker
                                    >;

    // Constructing the output also depends on the storage_kind the output
    using result_storage_kind = typename result_traits::storage_kind;

    // ---------------------------------------------------------------------------------------------
    // (P)
    template <typename P0, typename SKI, typename SKO, typename... N>
    BOOST_FORCEINLINE result_type map_( SKI const&, SKO const&
                                      , nsm::list<N...> const&
                                      , P0 const& p0
                                      ) const BOOST_NOEXCEPT
    {
      BOOST_SIMD_DIAG("unrolled automap for: " << *this);
      Func f;
      return result_type{ f(simd::extract<N::value>(p0))... };
    }

    // ---------------------------------------------------------------------------------------------
    // (P, P)
    template <typename P0, typename P1, typename SKI, typename SKO, typename... N>
    BOOST_FORCEINLINE result_type map_( SKI const&, SKO const&
                                      , nsm::list<N...> const&
                                      , P0 const& p0, P1 const& p1
                                      ) const BOOST_NOEXCEPT
    {
      BOOST_SIMD_DIAG("unrolled automap for: " << *this);
      Func f;
      return result_type{ f( simd::extract<N::value>(p0), simd::extract<N::value>(p1) )...  };
    }

    // ---------------------------------------------------------------------------------------------
    // (P, P, P)
    template< typename P0, typename P1, typename P2
            , typename SKI, typename SKO, typename... N
            >
    BOOST_FORCEINLINE result_type map_( SKI const&, SKO const&
                                      , nsm::list<N...> const&
                                      , P0 const& p0, P1 const& p1, P2 const& p2
                                      ) const BOOST_NOEXCEPT
    {
      BOOST_SIMD_DIAG("unrolled automap for: " << *this);
      Func f;
      return result_type{ f ( simd::extract<N::value>(p0)
                            , simd::extract<N::value>(p1)
                            , simd::extract<N::value>(p2)
                            )...
                        };
    }

    // ---------------------------------------------------------------------------------------------
    // (P, P, P, P)
    template< typename P0, typename P1, typename P2, typename P3
            , typename SKI, typename SKO, typename... N
            >
    BOOST_FORCEINLINE result_type map_( SKI const&, SKO const&
                                      , nsm::list<N...> const&
                                      , P0 const& p0, P1 const& p1
                                      , P2 const& p2, P3 const& p3
                                      ) const BOOST_NOEXCEPT
    {
      BOOST_SIMD_DIAG("unrolled automap for: " << *this);
      Func f;
      return result_type{ f ( simd::extract<N::value>(p0), simd::extract<N::value>(p1)
                            , simd::extract<N::value>(p2), simd::extract<N::value>(p3)
                            )...
                        };
    }

    // ---------------------------------------------------------------------------------------------
    // Map dispatcher when both input and output are aggregates
    BOOST_FORCEINLINE result_type map_( Pi const& p0, Pn const&... p ) const BOOST_NOEXCEPT
    {
      BOOST_SIMD_DIAG("aggregation automap for: " << *this);
      Func f;
      return combine( f( slice_low(p0), slice_low(p)...)
                    , f( slice_high(p0), slice_high(p)...)
                    );
    }

    template <typename... N>
    BOOST_FORCEINLINE result_type map_( nsm::bool_<true> const&
                                      , ::boost::simd::aggregate_storage const&
                                      , nsm::list<N...> const&
                                      , Pi const& p0, Pn const&... pn
                                      ) const BOOST_NOEXCEPT
    {
      return map_( p0, pn... );
    }

    // ---------------------------------------------------------------------------------------------
    // Map operator()
    BOOST_FORCEINLINE result_type operator()(Pi const& p0, Pn const&... pn) const BOOST_NOEXCEPT
    {
      return map_( storage_kind{}, result_storage_kind{}, element_range{}, p0, pn... );
    }
  };

  // -----------------------------------------------------------------------------------------------
  // map_to takes a callable object and a series of value that can be pack (or not) and
  // try to find the best way to implement it using the scalar version of the callable object
  template<typename Function, typename P0, typename... Pn>
  BOOST_FORCEINLINE typename automapper<Function,P0,Pn...>::result_type
  map_to(Function const&, P0 const& p0, Pn const&... pn) BOOST_NOEXCEPT
  {
    return automapper<Function,P0,Pn...>()(p0, pn...);
  }
} } }

#endif
