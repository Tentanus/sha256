#include <gtest/gtest.h>
#include "sha256.hpp"

TEST(sha256, sha256_operations_ROTL) {
    // Simple Test cases
    EXPECT_EQ(ROTL(0, 1), 0);
    EXPECT_EQ(ROTL(1, 1), 2);

    EXPECT_EQ(ROTL(1073741824, 1), -2147483648);
    EXPECT_EQ(ROTL(-2147483648, 1), 1);
    EXPECT_EQ(ROTL(1431655765, 1), -1431655766);
}

TEST(sha256, sha256_operations_ROTR) {
    // Simple Test cases
    EXPECT_EQ(ROTR(0, 1), 0);
    EXPECT_EQ(ROTR(2, 1), 1);
    EXPECT_EQ(ROTR(1, 1), -2147483648);
    EXPECT_EQ(ROTR(-2147483648, 1), 1073741824);
    EXPECT_EQ(ROTL(1431655765, 1), -1431655766);

}