#include "ARIA/ARIA.h"

#include <boost/ut.hpp>

using namespace ARIA;
using namespace boost::ut;

namespace {

suite<"ARIA"> _ = [] {
  "Aliases"_test = [] {
    static_assert(sizeof(i8) == 1);
    static_assert(sizeof(u8) == 1);
    static_assert(sizeof(i16) == 2);
    static_assert(sizeof(u16) == 2);
    static_assert(sizeof(i32) == 4);
    static_assert(sizeof(u32) == 4);
    static_assert(sizeof(i64) == 8);
    static_assert(sizeof(u64) == 8);

    static_assert(std::is_signed_v<i8>);
    static_assert(!std::is_signed_v<u8>);
    static_assert(std::is_signed_v<i16>);
    static_assert(!std::is_signed_v<u16>);
    static_assert(std::is_signed_v<i32>);
    static_assert(!std::is_signed_v<u32>);
    static_assert(std::is_signed_v<i64>);
    static_assert(!std::is_signed_v<u64>);

    static_assert(sizeof(f32) == 4);
    static_assert(sizeof(f64) == 8);

    static_assert(std::is_signed_v<f32>);
    static_assert(std::is_signed_v<f64>);

    static_assert(std::is_same_v<Real, f32> || std::is_same_v<Real, f64>);
  };

  //
  //
  //
  "Policies"_test = [] { static_assert(!std::is_same_v<ThreadSafe, ThreadUnsafe>); };

  //
  //
  //
  "Functions"_test = [] {
    static_assert(Pow<0>(0) == 1);
    static_assert(Pow<0>(1) == 1);
    static_assert(Pow<0>(2U) == 1U);
    static_assert(Pow<0>(3.3F) == 1.0F);
    static_assert(Pow<0>(4.44) == 1.0);

    expect(Pow<0>(0) == 1);
    expect(Pow<0>(1) == 1);
    expect(Pow<0>(2U) == 1U);
    expect(Pow<0>(3.3F) == 1.0F);
    expect(Pow<0>(4.44) == 1.0);

    static_assert(Pow<1>(0) == 0);
    static_assert(Pow<1>(1) == 1);
    static_assert(Pow<1>(2U) == 2U);
    static_assert(Pow<1>(3.3F) == 3.3F);
    static_assert(Pow<1>(4.44) == 4.44);

    expect(Pow<1>(0) == 0);
    expect(Pow<1>(1) == 1);
    expect(Pow<1>(2U) == 2U);
    expect(Pow<1>(3.3F) == 3.3F);
    expect(Pow<1>(4.44) == 4.44);

    static_assert(Pow<2>(0) == 0);
    static_assert(Pow<2>(1) == 1);
    static_assert(Pow<2>(2U) == 4U);
    static_assert(Pow<2>(3.3F) == 3.3F * 3.3F);
    static_assert(Pow<2>(4.44) == 4.44 * 4.44);

    expect(Pow<2>(0) == 0);
    expect(Pow<2>(1) == 1);
    expect(Pow<2>(2U) == 4U);
    expect(Pow<2>(3.3F) == 3.3F * 3.3F);
    expect(Pow<2>(4.44) == 4.44 * 4.44);

    static_assert(Pow<3>(0) == 0);
    static_assert(Pow<3>(1) == 1);
    static_assert(Pow<3>(2U) == 8U);
    static_assert(Pow<3>(3.3F) == 3.3F * 3.3F * 3.3F);
    static_assert(Pow<3>(4.44) == 4.44 * 4.44 * 4.44);

    expect(Pow<3>(0) == 0);
    expect(Pow<3>(1) == 1);
    expect(Pow<3>(2U) == 8U);
    expect(Pow<3>(3.3F) == 3.3F * 3.3F * 3.3F);
    expect(Pow<3>(4.44) == 4.44 * 4.44 * 4.44);

    static_assert(Pow<4>(0) == 0);
    static_assert(Pow<4>(1) == 1);
    static_assert(Pow<4>(2U) == 16U);
    static_assert(Pow<4>(3.3F) == 3.3F * 3.3F * 3.3F * 3.3F);
    static_assert(Pow<4>(4.44) == 4.44 * 4.44 * 4.44 * 4.44);

    expect(Pow<4>(0) == 0);
    expect(Pow<4>(1) == 1);
    expect(Pow<4>(2U) == 16U);
    expect(Pow<4>(3.3F) == 3.3F * 3.3F * 3.3F * 3.3F);
    expect(Pow<4>(4.44) == 4.44 * 4.44 * 4.44 * 4.44);

    static_assert(Pow<5>(0) == 0);
    static_assert(Pow<5>(1) == 1);
    static_assert(Pow<5>(2U) == 32U);
    static_assert(Pow<5>(3.3F) == 3.3F * 3.3F * 3.3F * 3.3F * 3.3F);
    static_assert(Pow<5>(4.44) == 4.44 * 4.44 * 4.44 * 4.44 * 4.44);

    expect(Pow<5>(0) == 0);
    expect(Pow<5>(1) == 1);
    expect(Pow<5>(2U) == 32U);
    expect(Pow<5>(3.3F) == 3.3F * 3.3F * 3.3F * 3.3F * 3.3F);
    expect(Pow<5>(4.44) == 4.44 * 4.44 * 4.44 * 4.44 * 4.44);
  };
};

} // namespace
