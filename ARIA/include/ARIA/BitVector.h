#pragma once

/// \file
/// \brief A `BitVector` is a policy-based owning vector containing bits, which
/// is similar to `std::vector<bool>`, but can be optionally thread-safe.

//
//
//
//
//
#include "ARIA/ARIA.h"

namespace ARIA {

/// \brief A `BitVector` is a policy-based owning vector containing bits, which
/// is similar to `std::vector<bool>`, but can be optionally thread-safe.
///
/// \example ```cpp
/// using Bits = BitVector<ThreadSafe>;
///
/// Bits bits(10);
/// size_t size = bits.size();
/// bits.resize(100);
///
/// bits.Fill(0);
/// bits.Clear(0);
/// bits.Flip(99);
///
/// bool bit0 = bits[99];
/// bits[99] = false;
/// bool bit1 = bits.at(99);
/// bits.at(99) = true;
/// ```
///
/// \warning `at` and `operator[]` are never atomic even though the `ThreadSafe` policy is set.
/// Since setting a bit requires twice the efforts than filling, clearing, or flipping a bit,
/// developers should try to use `Fill`, `Clear`, and `Flip` instead.
template <typename TThreadSafety>
class BitVector {
  // TODO: Implement this.
};

} // namespace ARIA
