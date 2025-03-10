#include <gtest/gtest.h>

extern "C"
{
#include "sha_operations.h"
}

TEST(ROTR, basic)
{
	EXPERCT_EQ(ROTR(0, 0), 0);
	EXPERCT_EQ(ROTR(1, 0), 1);
	EXPERCT_EQ(ROTR(0, 1), 0);
	EXPERCT_EQ(ROTR(1, 1), 2);
	// NOTE: add case for overflow from and two max
}

TEST(ROTL, basic)
{
	EXPERCT_EQ(ROTL(0, 0), 0);
	EXPERCT_EQ(ROTL(1, 0), 1);
	EXPERCT_EQ(ROTL(0, 1), 0);
	EXPERCT_EQ(ROTL(2, 1), 1);
	// NOTE: add case for overflow from and two max
}
