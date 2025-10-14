#include <gtest/gtest.h>

#include "sha256.hpp"

static void validateBlock(const MessageBlock &given_block, const uint32_t expected_words[]) {
    for (size_t i = 0; i < WORD_BLOCKS; i++)
        EXPECT_EQ(given_block[i], expected_words[i]) << "Mismatch at word: i = " << i;
}

static void testMessageBlock(  const char* str, 
                               const uint32_t readbytes,
                               const uint64_t totalbytes,
                               const uint32_t* expected_words) 
{
    MessageBlock block(str, readbytes, totalbytes);
    validateBlock(block, expected_words);
}

// ? Message blocks currently don't support passing more bytes being passed then bytes in the string
TEST(sha256, MessageBlock_construction)
{
    // Test empty inputs.
    testMessageBlock("", 0, 0, 
                        (const uint32_t[]){ 0x80000000, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0 });
    testMessageBlock("abcd", 4, 4, 
                        (const uint32_t[]){ 0x61626364, 0x80000000, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x4 });
    testMessageBlock("abcdefgh", 8, 8, 
                        (const uint32_t[]){ 0x61626364, 0x65666768, 0x80000000, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x8 });
    testMessageBlock("aaaa    aaaa    aaaa    aaaa    aaaa    aaaa    aaaa   ", 440, 440, 
                        (const uint32_t[]){ 0x61616161, 0x20202020, 0x61616161, 0x20202020,
                                            0x61616161, 0x20202020, 0x61616161, 0x20202020,
                                            0x61616161, 0x20202020, 0x61616161, 0x20202020,
                                            0x61616161, 0x20202080, 0x00000000, 0x000001B8 });
}

TEST(MessageBlock, OperatorOutOfBounds) {
    const char str[] = "abc";
    MessageBlock block(str, 3, 3);
    EXPECT_DEATH(block[WORD_BLOCKS], "out of bound");
}