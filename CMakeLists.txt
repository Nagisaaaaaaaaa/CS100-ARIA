cmake_minimum_required(VERSION 3.25.2)
project(ARIA LANGUAGES CXX)

option(ARIA_ENABLE_TESTING "Build ARIA testing suite" ON)

include(FetchContent)
FetchContent_Declare(
  CPM
  GIT_REPOSITORY https://github.com/cpm-cmake/CPM.cmake.git
  GIT_TAG v0.42.0
)
FetchContent_MakeAvailable(CPM)

CPMAddPackage(
  NAME ut
  GITHUB_REPOSITORY boost-ext/ut
  GIT_TAG v2.3.1
)

CPMAddPackage(
  NAME glm
  GITHUB_REPOSITORY g-truc/glm
  GIT_TAG 1.0.1
)

add_subdirectory(${PROJECT_NAME})
