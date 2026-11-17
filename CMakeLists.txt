cmake_minimum_required(VERSION 3.14)
project(smoothsort)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test_heapsort
  tests/test_heapsort.cpp
  src/heapsort.cpp
)
target_link_libraries(
  test_heapsort
  GTest::gtest_main
)

target_compile_definitions(test_heapsort PRIVATE UNIT_TESTING)


include(GoogleTest)
gtest_discover_tests(test_heapsort)