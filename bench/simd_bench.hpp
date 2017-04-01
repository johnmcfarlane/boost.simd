//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef SIMD_BENCH_HPP_INCLUDED
#define SIMD_BENCH_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/pack.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <ns/bench.hpp>
#include <ns/bench/type_id.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/meta/is_scalar.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/simd/detail/nsm.hpp>

namespace ns { namespace bench {

 namespace tt = nsm::type_traits;

template <typename T, std::size_t N>
struct format_type<boost::simd::pack<T, N>>
{
  static std::string to_string()
  {
    std::stringstream ss;

    ss << "pack<" << format_type<T>::to_string() << ", " << N << ">";
    return ss.str();
  }
};

template <typename T, template < typename > class C, std::size_t N>
struct format_type<C<boost::simd::pack<T, N>>>
{
  static std::string to_string()
  {
    std::stringstream ss;

    ss << "complex < pack<" << format_type<T>::to_string() << " > , " << N << ">";
    return ss.str();
  }
};
} }

namespace ns { namespace bench { namespace generators {

  namespace bs = boost::simd;

template <typename T, std::size_t N>
struct rand<boost::simd::pack<T, N>>
{
  using pack_type = bs::pack<T, N>;
  using value_type = typename pack_type::value_type;

  template <typename U>
  rand( U min = static_cast<U>(std::numeric_limits<value_type>::min())
      , U max = static_cast<U>(std::numeric_limits<value_type>::max())
      ) : min_(min), max_(max), r(min, max)
  {
  }

  inline pack_type operator()() {
    std::array<value_type, sizeof(pack_type) / sizeof(value_type)> v;
    std::transform(v.begin(), v.end(), v.begin(), [this](value_type const&) { return r.random(); });
    return {v.begin(), v.end()};
  }

  std::string description() const {
    std::stringstream ss;
    ss << "rand<pack<" << format_type<pack_type>::to_string() << ", " << N
       << ">>[(" << format(rmin()) << ", " << format(rmax()) << ")]";
    return ss.str();
  }
   value_type const& rmin() const { return min_; }
   value_type const& rmax() const { return max_; }

  private :
  value_type min_, max_;
  rand<value_type> r;
};


template <typename T, std::size_t N>
struct rand<bs::complex<bs::pack<T, N>>>
{
  using complex_type = bs::complex<bs::pack<T, N>>;
  using pack_type = bs::pack<T, N>;
  using value_type = typename pack_type::value_type;

   template <typename U, typename V>
   rand( U rmin = static_cast<U>(std::numeric_limits<value_type>::min())
       , U rmax = static_cast<U>(std::numeric_limits<value_type>::max())
       , V imin = static_cast<V>(std::numeric_limits<value_type>::min())
       , V imax = static_cast<V>(std::numeric_limits<value_type>::max())
       ) : rmin_(rmin), rmax_(rmax), imin_(imin), imax_(imax)
         , r(rand<value_type>(rmin_, rmax_))
         , i(rand<value_type>(imin_, imax_))
  { }

  template <typename U>
  rand( U rmin = static_cast<U>(std::numeric_limits<value_type>::min())
      , U rmax = static_cast<U>(std::numeric_limits<value_type>::max())
      ) :rmin_(rmin), rmax_(rmax), imin_(rmin), imax_(rmax),
         r(rand<value_type>(rmin_, rmax_)),
         i(rand<value_type>(rmin_, rmax_))
  { }


  complex_type random()
  {
    std::array<value_type, sizeof(value_type) / sizeof(value_type)> v, w;
    std::transform(v.begin(), v.end(), v.begin(), [this](value_type const&) { return r.random(); });
    std::transform(w.begin(), w.end(), w.begin(), [this](value_type const&) { return i.random(); });
    return {pack_type{v.begin(), v.end()}, pack_type{w.begin(), w.end()}};
  }
  /// Generate the next value
  inline complex_type operator()() {
    return random();
  }
   value_type const& rmin() const { return rmin_; }
   value_type const& rmax() const { return rmax_; }
   value_type const& imin() const { return imin_; }
   value_type const& imax() const { return imax_; }

  std::string description() const {
    std::stringstream ss;
    ss << "rand<complex<pack<" << format_type<value_type>::to_string() << ", " << N
       << ">>>[(" << format(rmin()) << ", " << format(rmax()) << "), ("
       <<           format(imin()) << ", " << format(imax()) << ")]";
    return ss.str();
  }

  private :
  value_type rmin_, rmax_, imin_, imax_;
  rand<value_type> r, i;
};

template <typename T>
struct rand<bs::complex<T>>
{
  using complex_type = bs::complex<T>;
  using value_type = T;

   template <typename U, typename V>
   rand( U rmin = static_cast<U>(std::numeric_limits<value_type>::min())
       , U rmax = static_cast<U>(std::numeric_limits<value_type>::max())
       , V imin = static_cast<V>(std::numeric_limits<value_type>::min())
       , V imax = static_cast<V>(std::numeric_limits<value_type>::max())
       ) : rmin_(rmin), rmax_(rmax), imin_(imin), imax_(imax)
         , r(rand<value_type>(rmin_, rmax_))
         , i(rand<value_type>(imin_, imax_))
  { }

  template <typename U>
  rand( U rmin = static_cast<U>(std::numeric_limits<value_type>::min())
      , U rmax = static_cast<U>(std::numeric_limits<value_type>::max())
      ) :rmin_(rmin), rmax_(rmax), imin_(rmin), imax_(rmax),
         r(rand<value_type>(rmin_, rmax_)),
         i(rand<value_type>(rmin_, rmax_))
  { }


   /// Generate a random value between `min` and `max`
   complex_type random() {
     return { r.random(), i.random()};
   }

  /// Generate the next value
  inline complex_type operator()() {
    return random();
  }
   value_type const& rmin() const { return rmin_; }
   value_type const& rmax() const { return rmax_; }
   value_type const& imin() const { return imin_; }
   value_type const& imax() const { return imax_; }

  std::string description() const {
    std::stringstream ss;
    ss << "rand<complex<" << format_type<value_type>::to_string()
       << ">>[(" << format(rmin()) << ", " << format(rmax()) << "), ("
       <<           format(imin()) << ", " << format(imax()) << ")]";
    return ss.str();
  }

  private :
  value_type rmin_, rmax_, imin_, imax_;
  rand<value_type> r, i;
};

template <typename T>
struct rand<std::complex<T>>
{
  using complex_type = std::complex<T>;
  using value_type = T;

   template <typename U, typename V>
   rand( U rmin = static_cast<U>(std::numeric_limits<value_type>::min())
       , U rmax = static_cast<U>(std::numeric_limits<value_type>::max())
       , V imin = static_cast<V>(std::numeric_limits<value_type>::min())
       , V imax = static_cast<V>(std::numeric_limits<value_type>::max())
       ) : rmin_(rmin), rmax_(rmax), imin_(imin), imax_(imax)
         , r(rand<value_type>(rmin_, rmax_))
         , i(rand<value_type>(imin_, imax_))
  { }

  template <typename U>
  rand( U rmin = static_cast<U>(std::numeric_limits<value_type>::min())
      , U rmax = static_cast<U>(std::numeric_limits<value_type>::max())
      ) :rmin_(rmin), rmax_(rmax), imin_(rmin), imax_(rmax),
         r(rand<value_type>(rmin_, rmax_)),
         i(rand<value_type>(rmin_, rmax_))
  { }


   /// Generate a random value between `min` and `max`
   complex_type random() {
     return { r.random(), i.random()};
   }

  /// Generate the next value
  inline complex_type operator()() {
//     std::cout << ns::bench::type_id<complex_type>() << std::endl;
//     std::cout << ns::bench::type_id<value_type>()<< std::endl;
    return random();
  }
   value_type const& rmin() const { return rmin_; }
   value_type const& rmax() const { return rmax_; }
   value_type const& imin() const { return imin_; }
   value_type const& imax() const { return imax_; }

  std::string description() const {
    std::stringstream ss;
    ss << "rand<<std::complex<" << format_type<value_type>::to_string()
       << ">>[(" << format(rmin()) << ", " << format(rmax()) << "), ("
       <<           format(imin()) << ", " << format(imax()) << ")]";
    return ss.str();
  }

  private :
  value_type rmin_, rmax_, imin_, imax_;
  rand<value_type> r, i;
};

} } }

// -------------------------------------------------------------------------------------------------

namespace nsb = ns::bench;
namespace nsbg = nsb::generators;

inline nsb::setup setup()
{
  return nsb::default_setup();
}

inline nsb::results& results()
{
  static nsb::results r;
  return r;
}

inline bool is_quiet()
{
  return nsb::args_map().get<bool>("quiet", false);
}

inline void display()
{
  std::cout << results() << std::endl;
}

inline std::string sanitized_simd()
{
  namespace ba = boost::algorithm;
  auto s = nsb::type_id<BOOST_SIMD_DEFAULT_SITE>();
  ba::ierase_all(s, "boost::simd::");
  ba::trim_right_if(s,boost::is_any_of("_"));
  return s;
}

template <typename F>
inline std::string sanitized_function()
{
  namespace ba = boost::algorithm;
  auto s = nsb::type_id<F>();
  ba::ierase_all(s, "boost::dispatch::functor");
  ba::ierase_all(s, "boost::simd::tag::");
  ba::ierase_all(s, "<");
  ba::ierase_all(s, ">");
  ba::replace_all(s, "_,", ", ");
  ba::trim_right_if(s,boost::is_any_of("_"));
  ba::ierase_all(s, " ");
  auto i = s.find(",");
  if (i != std::string::npos) {
    s = s.substr(0, i);
  }
  return "boost::simd::" + s;
}

inline void describe()
{
  if (!is_quiet()) {
    std::cout << ":: --------------------------------------------------------------------------------------------------------------------------------------------------";
    std::cout << std::endl;
    std::cout << ":: Compiler: " << BOOST_COMPILER << std::endl;
    std::cout << ":: Platform: " << BOOST_PLATFORM << std::endl;
    std::cout << ":: SIMD:     " << sanitized_simd() << std::endl;
    std::cout << ":: --------------------------------------------------------------------------------------------------------------------------------------------------";
    std::cout << std::endl;
  }
}

// -------------------------------------------------------------------------------------------------

template <typename T> struct experiment_size_of {
  enum { value = 1 };
};

template <typename T, std::size_t N>
struct experiment_size_of<boost::simd::pack<T, N>>  {
  enum { value = N };
};

template <typename T, std::size_t N>
struct experiment_size_of<boost::simd::complex<boost::simd::pack<T, N>>>  {
  enum { value = N };
};

// -------------------------------------------------------------------------------------------------

template <typename T, typename F, typename... Args>
void run(std::string const& name, F f, Args&&... args)
{
  enum { N = experiment_size_of<T>::value };
  if (!is_quiet()) {
    std::cout << ":: [T = " << nsb::type_id<T>() << "]" << std::endl;
    std::cout << ":: [N = " << N << "]" << std::endl;
  }
  nsb::run(results(), setup(), name, nsb::make_sized_function(N, f), std::forward<Args>(args)...);
}

template <typename T, typename F, typename... Args>
void run(F f, Args&&... args)
{
  run<T>(sanitized_function<F>(), f, std::forward<Args>(args)...);
}

// -------------------------------------------------------------------------------------------------

#define DEFINE_BENCH_MAIN()                                                                        \
  void main2();                                                                                    \
  int main(int argc, char** argv)                                                                  \
  {                                                                                                \
    nsb::parse_args(argc, argv);                                                                   \
    main2();                                                                                       \
    describe();                                                                                    \
    results().add_optional_info("simd", sanitized_simd());                                         \
    display();                                                                                     \
    return 0;                                                                                      \
  }                                                                                                \
  void main2()                                                                                     \
/**/

namespace ns { namespace bench { namespace generators {



} } }
#endif
