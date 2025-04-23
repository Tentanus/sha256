#include <gtest/gtest.h>
#include "sha256.hpp"

TEST(sha256, sha256_operations_ROTR) {
    // Simple Test cases
    EXPECT_EQ(ROTL(0, 1), 0);
    EXPECT_EQ(ROTL(1, 1), 2);

    EXPECT_EQ(ROTL(1073741824, 1), -2147483648);
    EXPECT_EQ(ROTL(-2147483648, 1), 1);
    EXPECT_EQ(ROTL(1431655765, 1), -1431655766);
    // EXPECT_EQ(ROTL(1431655765, 3), -1431655766);
}