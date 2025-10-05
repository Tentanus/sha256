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
    // validateBlock(block, expected_words);
}

TEST(sha256, MessageBlock_construction) 
{
    // Test empty inputs.
    // ! causes segfault in constructor
    testMessageBlock("", 0, 0, (const uint32_t[]){  0x0, 0x0, 0x0, 0x0,
                                                    0x0, 0x0, 0x0, 0x0,
                                                    0x0, 0x0, 0x0, 0x0,
                                                    0x0, 0x0, 0x0, 0x0 });
    // testMessageBlock("", 1, 0, (const uint32_t[]){  0x0, 0x0, 0x0, 0x0,
    //                                                 0x0, 0x0, 0x0, 0x0,
    //                                                 0x0, 0x0, 0x0, 0x0,
    //                                                 0x0, 0x0, 0x0, 0x0 });
    // testMessageBlock("", 0, 1, (const uint32_t[]){  0x0, 0x0, 0x0, 0x0,`
                                                    // 0x0, 0x0, 0x0, 0x0,`
                                                    // 0x0, 0x0, 0x0, 0x0,`
                                                    // 0x0, 0x0, 0x0, 0x1 });`

    testMessageBlock("abcdefgh", 8, 8, 
        (const uint32_t[]){ 0x61626364, 0x65666768, 0x80000000, 0x0,
                            0x0, 0x0, 0x0, 0x0,
                            0x0, 0x0, 0x0, 0x0,
                            0x0, 0x0, 0x0, 0x8 }
    );
}

TEST(MessageBlock, OperatorOutOfBounds) {
    const char str[] = "abc";
    MessageBlock block(str, 3, 3);
    EXPECT_DEATH(block[WORD_BLOCKS], "out of bound");
}