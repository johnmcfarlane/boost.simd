//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_ATANH_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_ATANH_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/type/complex/function/is_nan.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/atan.hpp>
#include <boost/simd/function/atan2.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/if_neg.hpp>
#include <boost/simd/function/ifnot_plus.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/log1p.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/logical_notand.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/safe_max.hpp>
#include <boost/simd/function/safe_min.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( cmplx_atanh_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      //
      // This implementation is a simd (i.e. no branch) transcription and adaptation of the
      // boost_math code which itself is a transcription of the pseudo-code in:
      //
      // Eric W. Weisstein. "Inverse Hyperbolic Tangent."
      // From MathWorld--A Wolfram Web Resource.
      // http://mathworld.wolfram.com/InverseHyperbolicTangent.html
      //
      // Also: The Wolfram Functions Site,
      // http://functions.wolfram.com/ElementaryFunctions/ArcTanh/
      //
      // Also "Abramowitz and Stegun. Handbook of Mathematical Functions."
      // at : http://jove.prohosting.com/~skripty/toc.htm
      //
      using rtype =  typename A0::value_type;
      const rtype alpha_crossover(0.3);
      auto  ltzra0 = is_ltz(a0.real);
      auto  ltzia0 = is_ltz(a0.imag);
      rtype s_max = bs::safe_max(Two<rtype>());
      rtype s_min = bs::safe_min(Two<rtype>());
      rtype two =  Two<rtype>();
      rtype one =  One<rtype>();
      rtype inf =  Inf<rtype>();
      rtype x = bs::abs(a0.real);
      rtype y = bs::abs(a0.imag);
      rtype r = Zero<rtype>();
      rtype i = Zero<rtype>();
      auto gtxmax = (x > s_max);
      auto ltxmin = (x < s_min);
      auto gtymax = (y > s_max);
      auto ltymin = (y < s_min);
      rtype xx = bs::sqr(x);
      rtype yy = bs::sqr(y);
      rtype sqrabs = xx + yy;

      auto not_in_safe_zone = bs::logical_or( bs::logical_or(gtxmax, ltxmin),
                                              bs::logical_or(gtymax, ltymin)
                                            );
      if(bs::any(not_in_safe_zone))
      {
        //treat underflow or overflow
        // one or both of x and y are small, calculate divisor carefully:
        rtype div = one;
        div = bs::ifnot_plus(ltxmin, div, xx);
        div = bs::ifnot_plus(ltymin, div, yy);
        rtype alpha = x/div;
        alpha =  alpha+alpha;

        auto test =  gtymax;
        // Big y, medium x, divide through by y:
        rtype tmp_alpha = (two*x/y) / (y + xx/y);
        // Small x and y, whatever alpha is, it's too small to calculate:
        tmp_alpha = bs::if_else_zero((x > one), tmp_alpha);
        alpha = bs::if_else(bs::logical_and(test, (x > one)), tmp_alpha, alpha);

        test =  bs::logical_andnot(gtxmax, test);

        // Big x small y, as above but neglect y^2/x:
        tmp_alpha =  two/x;
        // Big x: divide through by x:
        tmp_alpha =  bs::if_else((y > one),  two / (x + y*y/x), tmp_alpha);
        // Big x and y: divide alpha through by x*y:
        tmp_alpha =  bs::if_else(gtymax, (two/y) / (x/y + y/x), tmp_alpha);
        // x or y are infinite: the result is 0
        tmp_alpha = bs::if_zero_else(bs::logical_or((y == inf), (x == inf)), tmp_alpha);

        alpha = bs::if_else(test, tmp_alpha, alpha);
        r = bs::if_else((alpha < alpha_crossover),
                        bs::log1p(alpha) - bs::log1p(-alpha),
                        bs::log(one + two*x + xx) - bs::log(sqr(dec(x)))
                       );
        test = bs::logical_and((x == one), ltymin);
        r = bs::if_else(test, -(bs::Two<rtype>() * (bs::log(y) - bs::Log_2<rtype>())), r);
        r *= Quarter<rtype>();
        //compute the imag part
        // y^2 is negligible:
        i =  bs::atan2(two*y, bs::oneminus(xx));
        i =  if_else(bs::logical_or(gtymax, gtxmax), Pi<rtype>(), i);
        rtype tmp_i = bs::if_else(ltymin, atan2(two*y, one),
                                  bs::atan2(two*y, bs::oneminus(yy)));
        i =  if_else(ltxmin, tmp_i, i);
      }
      auto test0 = bs::logical_and((inf == x), (inf == y));
      if(bs::any(test0))
      {
        //inf x, inf y
        r = bs::if_zero_else(test0, r);
        i = bs::if_else(test0, Pi<rtype>(), r);
      }
      auto test = bs::is_nan(a0);

      if(bs::any(test))
      {
        //nan x, inf y
        r = bs::if_zero_else(bs::logical_and(bs::is_nan(x), (y == inf)), r);
        i = bs::if_else(bs::logical_and(bs::is_nan(x), (y == inf)), Pi<rtype>(), r);

        r = bs::if_zero_else(bs::logical_and(is_nan(y), (x == inf)), r);
        i = bs::if_else(bs::logical_and(is_nan(y), (x == inf)), y, i);

        r = bs::if_zero_else(bs::logical_and(is_nan(y), bs::is_eqz(x)), r);
        i = bs::if_allbits_else(bs::logical_and(is_nan(y), bs::is_eqz(x)), i);
      }
      //compute for safe zone
      // The real part is given by:
      //
      // bs::real(atanh(z)) == log((1 + x^2 + y^2 + 2x) / (1 + x^2 + y^2 - 2x))
      //
      // However, when x is either large (x > 1/E) or very small
      // (x < E) then this effectively simplifies
      // to log(1), leading to wildly inaccurate results.
      // By dividing the above (top and bottom) by (1 + x^2 + y^2) we get:
      //
      // bs::real(atanh(z)) == log((1 + (2x / (1 + x^2 + y^2))) / (1 - (-2x / (1 + x^2 + y^2))))
      //
      // which is much more sensitive to the value of x, when x is not near 1
      // (remember we can compute log(1+x) for small x very accurately).
      //
      // The cross-over from one method to the other has to be determined
      // experimentally, the value used below appears correct to within a
      // factor of 2 (and there are larger errors from other parts
      // of the input domain anyway).
      //
      rtype alpha = x*two / (bs::inc(sqrabs));
      rtype sqrxm1 = bs::sqr(bs::dec(x));
      rtype tmp_r = bs::if_else((alpha < alpha_crossover),
                                bs::log1p(alpha) - log1p(-alpha),
                                bs::log1p(x+x + sqrabs) - bs::log(sqrxm1 + yy)
                               )*Quarter<rtype>();
      r = bs::if_else(not_in_safe_zone, r, tmp_r);

      // compute the imag part
      i = bs::if_else(not_in_safe_zone,
                      i,
                      bs::atan2(y+y, (oneminus(sqrabs)))
                     )*Half<rtype>();

      r = bs::if_neg( ltzra0,r);
      i = bs::if_else(bs::is_inf(y), bs::Pio_2<rtype>(), i);
      i = bs::if_neg( ltzia0,i);
      return {r, i};
    }
  };

} } }

#endif
