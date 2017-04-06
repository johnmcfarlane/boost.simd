//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_BOOLEAN_HPP_INCLUDED
#define BOOST_SIMD_BOOLEAN_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-boolean Boolean functions

      These functions provide SIMD algorithms for logical operations and branching
      in SIMD mode, their use is possible but not encouraged on scalars entries.

      All these functions can be included individually or all of them just by including <boost/simd/boolean.hpp>

      - **Logical operators**

        These functions return boost::simd::logical values, do not support short-circuiting
        and act in an elementwise way on SIMD vectors.

       <center>
         |                                            |                                            |                                       |
         |:------------------------------------------:|:------------------------------------------:|:-------------------------------------:|
         | [logical_and](@ref real-logical_and)       | [logical_andnot](@ref real-logical_andnot) | [logical_not](@ref real-logical_not)  |
         | [logical_notand](@ref real-logical_notand) | [logical_notor](@ref real-logical_notor)   | [logical_or](@ref real-logical_or)    |
         | [logical_ornot](@ref real-logical_ornot)   | [logical_xor](@ref real-logical_xor)       | [mask2logical](@ref real-mask2logical)|
        </center>

        Masks are pattern of bits all zeros or all ones that can allow masking
        using bitwise operations.  [mask2logical](@ref real-mask2logical) provides a way to transform a mask vector
        into a logical vector.

        Logical types are architecture dependant,  for instance on intel sse or avx
        logical types are mask valued simd vectors.

      - **Branching utilities**

        Be aware that using SIMD and branching are quite antagonist.

        For instance if a SIMD vector contains more than one element (!) a test on the
        elements will simultaneouly return true for some and false
        for others: so branching in simd may be described as 'compute all branches and select the
        pertinent results...'

        The functors listed above are of interest when one of the branches is much cheaper
        than the other.

        All branching utilities begin by if_ or ifnot_. The first parameter is a SIMD test
        pack which may be of any available type. This test pack is used to determine which branch
        will be selected for each element of the result vector. Non-zero elements are considered as true
        and zero elements as false. The result of each branch is given in the following parameters
        either implicitly or explicitly.

        These functors will generally compute all possible outcomes and then select the
        correct one. If each branch has the same cost (notwithstanding the cost of the test
        and the inner pipelining of the processor) the cost of the branching operation may
        be twice as expensive as the cost of evaluating one of the branches.
        It is for this reason that these functions are of greatest interest when the cardinal of
        the simd vector is greater than 2.

       <center>
         |                                                 |                                                         |                                          |                                                   |
         |:-----------------------------------------------:|:-------------------------------------------------------:|:----------------------------------------:| :------------------------------------------------:|
         |  [if_allbits_else](@ref real-if_allbits_else)   |  [if_allbits_else_zero](@ref real-if_allbits_else_zero) |  [if_dec](@ref real-if_dec)              |  [if_else_allbits](@ref real-if_else_allbits)     |
         |  [if_else](@ref real-if_else)                   |  [if_else_nan](@ref real-if_else_nan)                   |  [if_else_zero](@ref real-if_else_zero)  |  [if_inc](@ref real-if_inc)                       |
         |  [if_minus](@ref real-if_minus)                 |  [if_nan_else](@ref real-if_nan_else)                   |  [if_neg](@ref real-if_neg)              |  [if_one_else_zero](@ref real-if_one_else_zero)   |
         |  [if_plus](@ref real-if_plus)                   |  [if_zero_else_allbits](@ref real-if_zero_else_allbits) |  [if_zero_else](@ref real-if_zero_else)  |  [if_zero_else_one](@ref real-if_zero_else_one)   |
         |  [ifnot_dec](@ref real-ifnot_dec)               |  [ifnot_inc](@ref real-ifnot_inc)                       |  [ifnot_minus](@ref real-ifnot_minus)    |  [ifnot_neg](@ref real-ifnot_neg)                 |
         |  [ifnot_plus](@ref real-ifnot_plus)             |                                                         |                                          |                                                   |
       </center>

  **/

} }

#include <boost/simd/function/if_allbits_else.hpp>
#include <boost/simd/function/if_allbits_else_zero.hpp>
#include <boost/simd/function/if_else_allbits.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_else_nan.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/ifnot_plus.hpp>
#include <boost/simd/function/ifnot_dec.hpp>
#include <boost/simd/function/ifnot_inc.hpp>
#include <boost/simd/function/ifnot_minus.hpp>
#include <boost/simd/function/if_one_else_zero.hpp>
#include <boost/simd/function/if_zero_else_allbits.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/if_zero_else_one.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/logical_notand.hpp>
#include <boost/simd/function/logical_notor.hpp>
#include <boost/simd/function/logical_ornot.hpp>
#include <boost/simd/function/logical_xor.hpp>
#include <boost/simd/function/mask2logical.hpp>
#include <boost/simd/function/if_neg.hpp>
#include <boost/simd/function/ifnot_neg.hpp>
#include <boost/simd/function/if_plus.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <boost/simd/function/if_minus.hpp>

#endif
