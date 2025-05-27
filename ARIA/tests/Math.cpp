#include "ARIA/Math.h"

#include <boost/ut.hpp>

using namespace ARIA;
using namespace boost::ut;

namespace {

suite<"Math"> _ = [] {
  "Aliases"_test = [] {
    static_assert(std::is_same_v<Mat2i, glm::mat<2, 2, i32, glm::defaultp>>);
    static_assert(std::is_same_v<Mat2u, glm::mat<2, 2, u32, glm::defaultp>>);
    static_assert(std::is_same_v<Mat2r, glm::mat<2, 2, Real, glm::defaultp>>);

    static_assert(std::is_same_v<Mat3i, glm::mat<3, 3, i32, glm::defaultp>>);
    static_assert(std::is_same_v<Mat3u, glm::mat<3, 3, u32, glm::defaultp>>);
    static_assert(std::is_same_v<Mat3r, glm::mat<3, 3, Real, glm::defaultp>>);

    static_assert(std::is_same_v<Mat4i, glm::mat<4, 4, i32, glm::defaultp>>);
    static_assert(std::is_same_v<Mat4u, glm::mat<4, 4, u32, glm::defaultp>>);
    static_assert(std::is_same_v<Mat4r, glm::mat<4, 4, Real, glm::defaultp>>);

    static_assert(std::is_same_v<Vec2i, glm::vec<2, i32, glm::defaultp>>);
    static_assert(std::is_same_v<Vec2u, glm::vec<2, u32, glm::defaultp>>);
    static_assert(std::is_same_v<Vec2r, glm::vec<2, Real, glm::defaultp>>);

    static_assert(std::is_same_v<Vec3i, glm::vec<3, i32, glm::defaultp>>);
    static_assert(std::is_same_v<Vec3u, glm::vec<3, u32, glm::defaultp>>);
    static_assert(std::is_same_v<Vec3r, glm::vec<3, Real, glm::defaultp>>);

    static_assert(std::is_same_v<Vec4i, glm::vec<4, i32, glm::defaultp>>);
    static_assert(std::is_same_v<Vec4u, glm::vec<4, u32, glm::defaultp>>);
    static_assert(std::is_same_v<Vec4r, glm::vec<4, Real, glm::defaultp>>);

    static_assert(std::is_same_v<Quati, glm::qua<i32, glm::defaultp>>);
    static_assert(std::is_same_v<Quatu, glm::qua<u32, glm::defaultp>>);
    static_assert(std::is_same_v<Quatr, glm::qua<Real, glm::defaultp>>);
  };
};

} // namespace
