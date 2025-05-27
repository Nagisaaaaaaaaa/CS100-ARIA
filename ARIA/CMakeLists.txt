add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_23)

target_link_libraries(${PROJECT_NAME} INTERFACE
  glm::glm
)

if(ARIA_ENABLE_TESTING)
  add_subdirectory(tests)
endif()
