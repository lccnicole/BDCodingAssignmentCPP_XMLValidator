# CMakeLists.txt (root)

cmake_minimum_required(VERSION 3.10)
project(XmlValidatorTestProject)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Download and include Google Test using FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make Google Test available
FetchContent_MakeAvailable(googletest)

# Add main executable for the main program
add_executable(checker src/main.cpp src/simple_validator.cpp)
target_include_directories(checker PRIVATE src)

# Add the tests subdirectory
add_subdirectory(tests)
