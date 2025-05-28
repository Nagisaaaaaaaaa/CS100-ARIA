cmake_minimum_required(VERSION 3.25.2)
project(ARIA LANGUAGES CXX)

option(ARIA_ENABLE_TESTING "Build ARIA testing suite" ON)
option(ARIA_ENABLE_DEPENDENCIES "Automatically download dependency libraries if they are not present" ON)

if(ARIA_ENABLE_DEPENDENCIES AND NOT COMMAND CPMAddPackage)
  include(FetchContent)
  FetchContent_Declare(
    CPM
    GIT_REPOSITORY https://github.com/cpm-cmake/CPM.cmake.git
    GIT_TAG v0.42.0
  )
  FetchContent_MakeAvailable(CPM)
endif()

if(ARIA_ENABLE_DEPENDENCIES AND NOT TARGET glm::glm)
  CPMAddPackage(
    NAME glm
    GITHUB_REPOSITORY g-truc/glm
    GIT_TAG 1.0.1
  )
endif()

if(ARIA_ENABLE_DEPENDENCIES AND NOT TARGET Boost::ut)
  CPMAddPackage(
    NAME ut
    GITHUB_REPOSITORY boost-ext/ut
    GIT_TAG v2.3.1
  )
endif()

add_subdirectory(${PROJECT_NAME})
