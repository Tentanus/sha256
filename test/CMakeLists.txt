include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

# Build the test executable
add_executable(test_sha256
    sha256_test_defines.cpp
    sha256_test_preprocessor.cpp
    sha256_test_options.cpp
    sha256_test_messageblock.cpp
)

# Link tests against GoogleTest and the sha library
target_link_libraries(test_sha256
    PRIVATE
      sha
      GTest::gtest_main
)

# Register the test
add_test(NAME test_sha256 COMMAND test_sha256)
