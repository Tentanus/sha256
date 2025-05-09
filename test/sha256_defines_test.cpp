#include "sha256.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(sha256, operations)
{
	// Test cases for ROTL
	EXPECT_EQ(ROTL(0x00000000, 1), 0x00000000);		// check if 0 stays 0
	EXPECT_EQ(ROTL(0xFFFFFFFF, 1), 0xFFFFFFFF);		// check if -1 stays -1
	EXPECT_EQ(ROTL(0xFFFFFFFF, 20), 0xFFFFFFFF);	// check if -1 stays -1
	EXPECT_EQ(ROTL(0x00000001, 1), 0x00000002);		// standard check
	EXPECT_EQ(ROTL(0x40000000, 1), 0x80000000);		// standard check higher value

	EXPECT_EQ(ROTL(0x80000000, 1), 0x00000001);		// overflow the input
	EXPECT_EQ(ROTL(0x55555555, 1), 0xAAAAAAAA);		// overflow the input

	EXPECT_EQ(ROTL(0x00000001, 32), 0x00000001);	// overflow the rotation

	// Test cases for ROTR
	EXPECT_EQ(ROTR(0x00000000, 1), 0x00000000);		// check if 0 stays 0
	EXPECT_EQ(ROTR(0xFFFFFFFF, 1), 0xFFFFFFFF);		// check if -1 stays -1
	EXPECT_EQ(ROTR(0xFFFFFFFF, 20), 0xFFFFFFFF);	// check if -1 stays -1
	EXPECT_EQ(ROTR(0x00000002, 1), 0x00000001);		// standard check
	EXPECT_EQ(ROTR(0x80000000, 1), 0x40000000);		// standard check higher value

	EXPECT_EQ(ROTR(0x00000001, 1), 0x80000000);		// overflow the input
	EXPECT_EQ(ROTR(0xAAAAAAAA, 1), 0x55555555);		// overflow the input

	EXPECT_EQ(ROTR(0x00000001, 32), 0x00000001);	// overflow the rotation
}

TEST(sha256, sha1_functions)
{
	// Test cases for Ch
	EXPECT_EQ(Ch(0, 0, 0), 0);
	EXPECT_EQ(Ch(1, 0, 0), 0);
	EXPECT_EQ(Ch(0, 1, 0), 0);
	EXPECT_EQ(Ch(0, 0, 1), 1);
	EXPECT_EQ(Ch(1, 1, 0), 1);
	EXPECT_EQ(Ch(1, 0, 1), 0);
	EXPECT_EQ(Ch(0, 1, 1), 1);
	EXPECT_EQ(Ch(1, 1, 1), 1);

	// Test cases for Maj
	EXPECT_EQ(Maj(0, 0, 0), 0);
	EXPECT_EQ(Maj(1, 0, 0), 0);
	EXPECT_EQ(Maj(0, 1, 0), 0);
	EXPECT_EQ(Maj(0, 0, 1), 0);
	EXPECT_EQ(Maj(1, 1, 0), 1);
	EXPECT_EQ(Maj(1, 0, 1), 1);
	EXPECT_EQ(Maj(0, 1, 1), 1);
	EXPECT_EQ(Maj(1, 1, 1), 1);
}

TEST(sha256, sha256_functions)
{
	// Test cases for BSIG0
	EXPECT_EQ(BSIG0(0x00000000), 0x00000000);
	EXPECT_EQ(BSIG0(0xFFFFFFFF), 0xFFFFFFFF);

	EXPECT_EQ(BSIG0(0x0000007F), 0xC3F9FC1F);
	EXPECT_EQ(BSIG0(0x0000184F), 0x02193A13);
	EXPECT_EQ(BSIG0(0x01343CAC), 0x35DFB68E);
	EXPECT_EQ(BSIG0(0x0202E912), 0xC3B4E25B);
	EXPECT_EQ(BSIG0(0x26DE0C36), 0x90366D66);

	// Test cases for BSIG1
	EXPECT_EQ(BSIG1(0x00000000), 0x00000000);
	EXPECT_EQ(BSIG1(0xFFFFFFFF), 0xFFFFFFFF);

	EXPECT_EQ(BSIG1(0x0000007F), 0xF3E03F81);
	EXPECT_EQ(BSIG1(0x0000184F), 0x35EC27E2);
	EXPECT_EQ(BSIG1(0x01343CAC), 0xBF9AA075);
	EXPECT_EQ(BSIG1(0x0202E912), 0x6B3CC2F8);
	EXPECT_EQ(BSIG1(0x26DE0C36), 0x3159B8E2);

}
