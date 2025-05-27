#pragma once

#include "ARIA/ARIA.h"

#include <glm/glm.hpp>

namespace ARIA {

template <typename T>
using Mat2 = glm::mat<2, 2, T, glm::defaultp>;
using Mat2i = Mat2<i32>;
using Mat2u = Mat2<u32>;
using Mat2r = Mat2<Real>;

template <typename T>
using Mat3 = glm::mat<3, 3, T, glm::defaultp>;
using Mat3i = Mat3<i32>;
using Mat3u = Mat3<u32>;
using Mat3r = Mat3<Real>;

template <typename T>
using Mat4 = glm::mat<4, 4, T, glm::defaultp>;
using Mat4i = Mat4<i32>;
using Mat4u = Mat4<u32>;
using Mat4r = Mat4<Real>;

//
//
//
template <typename T>
using Vec2 = glm::vec<2, T, glm::defaultp>;
using Vec2i = Vec2<i32>;
using Vec2u = Vec2<u32>;
using Vec2r = Vec2<Real>;

template <typename T>
using Vec3 = glm::vec<3, T, glm::defaultp>;
using Vec3i = Vec3<i32>;
using Vec3u = Vec3<u32>;
using Vec3r = Vec3<Real>;

template <typename T>
using Vec4 = glm::vec<4, T, glm::defaultp>;
using Vec4i = Vec4<i32>;
using Vec4u = Vec4<u32>;
using Vec4r = Vec4<Real>;

//
//
//
template <typename T>
using Quat = glm::qua<T, glm::defaultp>;
using Quati = Quat<i32>;
using Quatu = Quat<u32>;
using Quatr = Quat<Real>;

} // namespace ARIA
