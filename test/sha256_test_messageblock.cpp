#include <gtest/gtest.h>

#include "sha256.hpp"

static void validateBlock(const MessageBlock &block, const uint32_t words[]) {
    for (size_t i = 0; i < WORD_BLOCKS; i++)
        EXPECT_EQ(block[i], words[i]) << "Mismatch at word index " << i;
}

TEST(sha256, MessageBlock_construction) 
{
    // Testcases for MessageBlock Construction
    const char str[] = "abcdefgh";  // passed bytes : 8
    MessageBlock block(str, 8, 8);
    
    // Fill expected_words with the correct values for "abcdefgh" + padding
    uint32_t expected_words[WORD_BLOCKS] = {
        0x61626364,
        0x65666768,
        0x80000000,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    validateBlock(block, expected_words);
}

TEST(MessageBlock, OperatorOutOfBounds) {
    const char str[] = "abc";
    MessageBlock block(str, 3, 3);
    EXPECT_DEATH(block[WORD_BLOCKS], "out of bound");
}