include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Build the test executable
add_executable(sha256_test
    sha256_operations_test.cpp
    sha256_options_test.cpp
)

# Link tests against GoogleTest and the factorial library
target_link_libraries(sha256_test
    PRIVATE
      sha
      GTest::gtest_main
)

# Register the test
add_test(NAME factorial_test COMMAND factorial_test)
