#include <gtest/gtest.h>

#include "sha256.hpp"

static void testMessageBlockConstructor(const char *str,
                                        const uint64_t totalbytes,
                                        const uint32_t* expected_words)
{
    MessageBlock block(str, totalbytes);

    for (size_t i = 0; i < WORD_BLOCKS; i++)
        EXPECT_EQ(block[i], expected_words[i]) << "Mismatch at word: i = " << i;
}

static void testMessageBlockConstructor(const char* str, 
                                        const uint32_t readbytes,
                                        const uint64_t totalbytes,
                                        const uint32_t* expected_words) 
{
    MessageBlock block(str, readbytes, totalbytes);

    for (size_t i = 0; i < WORD_BLOCKS; i++)
        EXPECT_EQ(block[i], expected_words[i]) << "Mismatch at word: i = " << i;
}

// ? Message blocks currently don't support passing more bytes being passed then bytes in the string
TEST(sha256, MessageBlock_Construction_Length)
{
    // Test empty inputs.
    testMessageBlockConstructor("", 0, 0, 
                        (const uint32_t[]){ 0x80000000, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0 });
    testMessageBlockConstructor("abcd", 4, 32, 
                        (const uint32_t[]){ 0x61626364, 0x80000000, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x20 });
    testMessageBlockConstructor("abcdefgh", 8, 64, 
                        (const uint32_t[]){ 0x61626364, 0x65666768, 0x80000000, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x40 });
    testMessageBlockConstructor("aaaa    aaaa    aaaa    aaaa    aaaa    aaaa    aaaa   ", 55, 440, 
                        (const uint32_t[]){ 0x61616161, 0x20202020, 0x61616161, 0x20202020,
                                            0x61616161, 0x20202020, 0x61616161, 0x20202020,
                                            0x61616161, 0x20202020, 0x61616161, 0x20202020,
                                            0x61616161, 0x20202080, 0x00000000, 0x000001B8 });
}

TEST(sha256, MessageBlock_Construction_NoLength)
{
    // Test empty inputs.
    testMessageBlockConstructor("", 0, 
                        (const uint32_t[]){ 0x80000000, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0 });
    testMessageBlockConstructor("abcd", 32, 
                        (const uint32_t[]){ 0x61626364, 0x80000000, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x20 });
    testMessageBlockConstructor("abcdefgh", 64, 
                        (const uint32_t[]){ 0x61626364, 0x65666768, 0x80000000, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x0,
                                            0x0, 0x0, 0x0, 0x40 });
    testMessageBlockConstructor("aaaa    aaaa    aaaa    aaaa    aaaa    aaaa    aaaa   ", 440, 
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