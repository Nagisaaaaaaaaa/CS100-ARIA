#pragma once

/// \file
/// \brief This file contains a collection of commonly used macros.

//
//
//
//
//
#include <cassert>
#include <iostream>

// Compilers.

/// \brief Whether clang is compiling the code.
#ifdef __clang__
  #define ARIA_CLANG __clang_major__
#else
  #define ARIA_CLANG 0
#endif // __clang__

/// \brief Whether ICC (Intel C++ Compiler) is compiling the code.
#ifdef __INTEL_COMPILER
  #define ARIA_ICC __INTEL_COMPILER
#else
  #define ARIA_ICC 0
#endif // __INTEL_COMPILER

/// \brief Whether MSVC is compiling the code.
#if defined(_MSC_VER) && !ARIA_CLANG && !ARIA_ICC
  #define ARIA_MSVC _MSC_VER
#else
  #define ARIA_MSVC 0
#endif

/// \brief Whether gcc is compiling the code.
#if defined(__GNUC__) && !ARIA_CLANG && !ARIA_ICC
  #define ARIA_GCC __GNUC__
#else
  #define ARIA_GCC 0
#endif

//
//
//
//
//
// Helper macros.
#define __ARIA_EXPAND(x) x

#define __ARIA_NUM_OF_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _, ...) _
#define __ARIA_CONCAT_HELPER(x, y)                                                                          x##y

#define __ARIA_COND_0(x, y)     y
#define __ARIA_COND_1(x, y)     x
#define __ARIA_COND_false(x, y) y
#define __ARIA_COND_true(x, y)  x

//
//
//
/// \brief Get number of the given args.
///
/// \example ```c
/// static_assert(ARIA_NUM_OF(a) == 1);
/// static_assert(ARIA_NUM_OF(a, b) == 2);
/// static_assert(ARIA_NUM_OF(a, b, c) == 3);
/// ```
///
/// \warning It is dangerous to call `ARIA_NUM_OF` with no arguments.
/// Never do that.
#define ARIA_NUM_OF(...)                                                                                               \
  __ARIA_EXPAND(__ARIA_NUM_OF_HELPER(__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))

/// \brief Concatenate `x` and `y`.
///
/// \example ```c
/// static_assert(ARIA_CONCAT(233, 466) == 233466);
/// ```
#define ARIA_CONCAT(x, y) __ARIA_CONCAT_HELPER(x, y)

/// \brief Create an anonymous name based on x.
///
/// \example ```c
/// struct ARIA_ANON(Name) {
/// ...
/// };
/// ```
#define ARIA_ANON(x) ARIA_CONCAT(x, __LINE__)

/// \brief Create a precompile-time `cond ? x : y`.
///
/// \example ```c
/// static_assert(ARIA_COND(1, 5, 6) == 5);
/// static_assert(ARIA_COND(0, 5, 6) == 6);
/// static_assert(ARIA_COND(true, 5, 6) == 5);
/// static_assert(ARIA_COND(false, 5, 6) == 6);
/// ```
#define ARIA_COND(cond, x, y) __ARIA_EXPAND(ARIA_CONCAT(__ARIA_COND_, cond))(x, y)

/// \brief Create a precompile-time `if (cond) x`.
///
/// \example ```c
/// ARIA_IF(1, printf("This message will be printed\n"));
/// ARIA_IF(0, printf("This message will not be printed\n"));
/// ARIA_IF(true, printf("This message will be printed\n"));
/// ARIA_IF(false, printf("This message will not be printed\n"));
/// ```
#define ARIA_IF(cond, x) ARIA_COND(cond, x, )

//
//
//
//
//
/// \brief Mark unimplemented code.
///
/// \example ```c
/// void SomeUnimplementedFunction(void) {
///   ARIA_UNIMPLEMENTED;
/// }
/// ```
#define ARIA_UNIMPLEMENTED                                                                                             \
  do {                                                                                                                 \
    fprintf(stderr, "Reached unimplemented code at [%s:%d]\n", __FILE__, __LINE__);                                    \
    abort();                                                                                                           \
  } while (0)

#if !defined(NDEBUG)
  #define __ARIA_ASSERT1(cond)                                                                                         \
    do {                                                                                                               \
      if (!(cond)) {                                                                                                   \
        fprintf(stderr, "Assertion (%s) failed at [%s:%d]\n", #cond, __FILE__, __LINE__);                              \
        assert(false);                                                                                                 \
      }                                                                                                                \
    } while (0)

  #define __ARIA_ASSERT2(cond, explanation)                                                                            \
    do {                                                                                                               \
      if (!(cond)) {                                                                                                   \
        fprintf(stderr, "Assertion (%s) failed at [%s:%d] (" explanation ")\n", #cond, __FILE__, __LINE__);            \
        assert(false);                                                                                                 \
      }                                                                                                                \
    } while (0)

  /// \brief Assert that the condition is true in debug mode.
  ///
  /// \example ```c
  /// ARIA_ASSERT(a == 1);
  /// ARIA_ASSERT(a == 1, "`a` does not equal to 1");
  /// ```
  #define ARIA_ASSERT(...)                                                                                             \
    __ARIA_EXPAND(__ARIA_EXPAND(ARIA_CONCAT(__ARIA_ASSERT, ARIA_NUM_OF(__VA_ARGS__)))(__VA_ARGS__))
#else
  /// \brief Do nothing in release mode.
  ///
  /// \example ```c
  /// ARIA_ASSERT(a == 1);
  /// ARIA_ASSERT(a == 1, "`a` does not equal to 1");
  /// ```
  #define ARIA_ASSERT(...) ((void)0)
#endif // !defined(NDEBUG)
