project(${PROJECT_NAME}-Tests LANGUAGES CXX)

file(GLOB SRC_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE
  ARIA
  Boost::ut
)
