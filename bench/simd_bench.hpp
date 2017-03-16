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
#include <ns/bench.hpp>
#include <boost/simd/type/complex.hpp>

namespace ns { namespace bench {

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

} }

namespace ns { namespace bench { namespace generators {

// template <typename T, std::size_t N>
// struct rand<boost::simd::pack<T, N>>
// {
//   using pack_type = boost::simd::pack<T, N>;
//   using value_type = typename pack_type::value_type;

//   template <typename U>
//   rand( U min = static_cast<U>(std::numeric_limits<value_type>::min())
//       , U max = static_cast<U>(std::numeric_limits<value_type>::max())
//       ) : r(min, max)
//   {
//   }

//   inline pack_type operator()() {
//     std::array<value_type, sizeof(pack_type) / sizeof(value_type)> v;
//     std::transform(v.begin(), v.end(), v.begin(), [this](value_type const&) { return r.random(); });
//     return {v.begin(), v.end()};
//   }

//   std::string description() const {
//     return "TODO";
//   }

//   private :
//   rand<value_type> r;
// };

template <typename C>
struct rand_complex_base {
  using complex_type = C;
  using value_type = typename complex_type::value_type;

  template <typename U>
  rand_complex_base( U pmin = static_cast<U>(std::numeric_limits<value_type>::min())
                   , U pmax = static_cast<U>(std::numeric_limits<value_type>::max())
                   ) : rmin_(pmin), rmax_(pmax), rmin_(pmin), rmax_(pmax)
  {
    if (std::is_unsigned<value_type>::value) {
      pmin = std::abs(pmin);
      pmax = std::abs(pmax);
    }
    if (pmin > pmax) std::swap(pmin, pmax);
    if (pmin == pmax) pmin = value_type(0);
    imin_ = rmin_ = pmin;
    imax_ = rmax_ = pmax;
  }

  template <typename U, typename V>
  rand_complex_base( U rmin = static_cast<U>(std::numeric_limits<value_type>::min())
                   , U rmax = static_cast<U>(std::numeric_limits<value_type>::max())
                   , V imin = static_cast<V>(std::numeric_limits<value_type>::min())
                   , V imax = static_cast<V>(std::numeric_limits<value_type>::max())
                   ) : rmin_(rmin), rmax_(rmax), imin_(imin), imax_(imax)
  {
    if (std::is_unsigned<value_type>::value) {
      rmin = std::abs(rmin);
      rmax = std::abs(rmax);
      imin = std::abs(imin);
      imax = std::abs(imax);
    }
    if (rmin > rmax) std::swap(rmin, rmax);
    if (rmin == rmax) rmin = value_type(0);
    rmin_ = rmin;
    rmax_ = rmax;
    if (imin > imax) std::swap(imin, imax);
    if (imin == imax) imin = value_type(0);
    imin_ = imin;
    imax_ = imax;

  }
  /// Generate a random value between `min` and `max`
  complex_type random() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dist(0.0, 1.0);
    double f = (rmax_ - rmin_);
    double g = (imax_- imin_);
    return { rmin_ + f * dist(gen),  imin_+ g * dist(gen)};
  }

  /// Generate the next value
  inline complex_type operator()() {
    return random();
  }

  /// Get the description of the generator
  std::string description() const {
    std::stringstream ss;
    ss << "rand<" << format_type<value_type>::to_string()
       << ">[ (" << format(rmin()) << ", " << format(rmax()) << "),  ("
       <<           format(imin()) << ", " << format(imax()) << ") ]";
    return ss.str();
  }

  value_type const& rmin() const { return rmin_; }
  value_type const& rmax() const { return rmax_; }
  value_type const& imin() const { return imin_; }
  value_type const& imax() const { return imax_; }

  private:
  value_type rmin_, rmax_, imin_, imax_;
};

template <typename T>
struct rand<boost::simd::complex<T>> : rand_complex_base<boost::simd::complex<T>> {
  using rand_complex_base<boost::simd::complex<T>>::rand_complex_base;
};

template <typename T>
struct rand<std::complex<T>> : rand_complex_base<std::complex<T>> {
  using rand_complex_base<std::complex<T>>::rand_complex_base;
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
  ba::ierase_all(s, "_");
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
  ba::ierase_all(s, "_");
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
