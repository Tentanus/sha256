#include "sha256.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(sha256, operations)
{
	// Simple Test cases for ROTL
	EXPECT_EQ(ROTL(0x00000000, 1), 0x00000000);		// check if 0 stays 0
	EXPECT_EQ(ROTL(0x00000001, 1), 0x00000002);		// standard check
	EXPECT_EQ(ROTL(0x40000000, 1), 0x80000000);		// standard check higher value

	EXPECT_EQ(ROTL(0x80000000, 1), 0x00000001);		// overflow the input
	EXPECT_EQ(ROTL(0x55555555, 1), 0xAAAAAAAA);		// overflow the input

	EXPECT_EQ(ROTL(0xFFFFFFFF, 1), 0xFFFFFFFF);		// see if -1 stays -1
	EXPECT_EQ(ROTL(0xFFFFFFFF, 20), 0xFFFFFFFF);	// see if -1 stays -1

	EXPECT_EQ(ROTL(0x00000001, 32), 0x00000001);	// overflow the rotation

	// Simple Test cases for ROTR
	EXPECT_EQ(ROTR(0x00000000, 1), 0x00000000);		// check if 0 stays 0
	EXPECT_EQ(ROTR(0x00000002, 1), 0x00000001);		// standard check
	EXPECT_EQ(ROTR(0x80000000, 1), 0x40000000);		// standard check higher value

	EXPECT_EQ(ROTR(0x00000001, 1), 0x80000000);		// overflow the input
	EXPECT_EQ(ROTR(0xAAAAAAAA, 1), 0x55555555);		// overflow the input

	EXPECT_EQ(ROTR(0xFFFFFFFF, 1), 0xFFFFFFFF);		// see if -1 stays -1
	EXPECT_EQ(ROTR(0xFFFFFFFF, 20), 0xFFFFFFFF);	// see if -1 stays -1

	EXPECT_EQ(ROTR(0x00000001, 32), 0x00000001);	// overflow the rotation
}

TEST(sha256, functions)
{
	// Simple Test cases for Ch
	EXPECT_EQ(Ch(0x00000000, 0x00000000, 0x00000000), 0x00000000);	// check if 0 stays 0
	EXPECT_EQ(Ch(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF), 0xFFFFFFFF);	// check if -1 stays -1
	EXPECT_EQ(Ch(0xFFFFFFFF, 0x00000000, 0x00000000), 0x00000000);
	EXPECT_EQ(Ch(0xFFFFFFFF, 0xFFFFFFFF, 0x00000000), 0xFFFFFFFF);
	EXPECT_EQ(Ch(0xFFFFFFFF, 0x00000000, 0xFFFFFFFF), 0x00000000);
}
