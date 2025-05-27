#include "ARIA/detail/Macros.h"

#include <boost/ut.hpp>

using namespace boost::ut;

namespace {

suite<"Macros"> _ = [] {
  "Compilers"_test = [] {
    static_assert((ARIA_CLANG ? 1 : 0) + (ARIA_ICC ? 1 : 0) + (ARIA_MSVC ? 1 : 0) + (ARIA_GCC ? 1 : 0) == 1);
  };

  //
  //
  //
  "Keywords"_test = [] {
    static_assert(ARIA_NUM_OF(a) == 1);
    static_assert(ARIA_NUM_OF(a, b) == 2);
    static_assert(ARIA_NUM_OF(a, b, c) == 3);

    static_assert(ARIA_CONCAT(233, 466) == 233466);

    static_assert(ARIA_ANON(999) == 99924);

    static_assert(ARIA_COND(1, 5, 6) == 5);
    static_assert(ARIA_COND(0, 5, 6) == 6);
    static_assert(ARIA_COND(true, 5, 6) == 5);
    static_assert(ARIA_COND(false, 5, 6) == 6);

    std::string str;
    ARIA_IF(1, str = "1");
    expect(str == "1");
    ARIA_IF(0, str = "0");
    expect(str == "0");
    ARIA_IF(true, str = "true");
    expect(str == "true");
    ARIA_IF(false, str = "false");
    expect(str == "true");
  };

  //
  //
  //
  "Assertions"_test = [] {
    auto unimplemented = [] { ARIA_UNIMPLEMENTED; };

    int a = 1;
    ARIA_ASSERT(a == 1);
    ARIA_ASSERT(a == 1, "`a` does not equal to 1");

    ARIA_EXPECT(a == 1);
    ARIA_EXPECT(a == 1, "`a` does not equal to 1");
  };
};

} // namespace
