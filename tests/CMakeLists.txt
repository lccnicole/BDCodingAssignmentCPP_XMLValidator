# tests/CMakeLists.txt

# Add test executable
add_executable(test_checker test_main.cpp test_simple_validator.cpp ../src/simple_validator.cpp)
target_include_directories(test_checker PRIVATE ../src)
target_link_libraries(test_checker gtest gtest_main)

# Register the test with CTest
add_test(NAME test_checker COMMAND test_checker)
