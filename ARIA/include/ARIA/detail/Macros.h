#pragma once

/// \file
/// \brief This file contains a collection of commonly used macros.

//
//
//
//
//
// Assertions and exceptions.

/// \brief A wrapper for `static_assert(false, message)`.
///
/// \example ```cpp
/// ARIA_STATIC_ASSERT_FALSE("This line should not compile");
/// ```
///
/// \note Suppose you want to write something like this:
/// `void Func() { if constexpr (false) { static_assert(false, ...); } }`,
/// the code will always get compile error, even if this branch is never reached.
/// So, template is used to postpone it to the instantiation time.
/// That is where this macro can be very helpful.
#define ARIA_STATIC_ASSERT_FALSE(message)                                                                              \
  []<bool assertion>() { static_assert(assertion, message); }.template operator()<false>()
