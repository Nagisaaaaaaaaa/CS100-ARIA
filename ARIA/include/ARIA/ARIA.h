#pragma once

/// \file
/// \warning "Higher beings, these words are for you alone.
/// Beyond this point you enter the land of ARIA.
/// Step across this threshold and obey our laws."

//
//
//
//
//
#include "ARIA/detail/Macros.h"

#include <cstdint>

namespace ARIA {

// Aliases for arithmetic types.

using i8 = int8_t;
using u8 = uint8_t;

using i16 = int16_t;
using u16 = uint16_t;

using i32 = int32_t;
using u32 = uint32_t;

using i64 = int64_t;
using u64 = uint64_t;

using f32 = float;
using f64 = double;
using Real = f32;

//
//
//
// Commonly-used policies.

/// \brief A commonly-used policy, means the type is thread-unsafe.
struct ThreadUnsafe {};

/// \brief A commonly-used policy, means the type is thread-safe.
struct ThreadSafe {};

//
//
//
/// \brief Compute `a^n`, where `n` is determined at compile-time.
template <u32 n, typename T>
[[nodiscard]] static constexpr T Pow(const T &a) {
  if constexpr (n == 0)
    return static_cast<T>(1);

  T half = Pow<n / 2>(a);
  if constexpr (n % 2)
    return half * half * a;
  else
    return half * half;
}

}; // namespace ARIA
