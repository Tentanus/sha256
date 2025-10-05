#ifndef MESSAGE_BLOCK_HPP
#define MESSAGE_BLOCK_HPP

#include <cstdint>
#include <iostream>
#include <string>

// 1 message block
// 512 bits  
// 64 bytes  (16 x 4)

#define WORD_BLOCKS 16

class MessageBlock
{
private:
    uint32_t _word[WORD_BLOCKS];

public:
    // Constructors
    MessageBlock(const char *inp, const uint64_t length, const uint64_t total);
    MessageBlock(const MessageBlock &rhs);
    ~MessageBlock();

    // Utility for debuggin
    const uint32_t &operator[](size_t idx) const;

};

#endif // MESSAGE_BLOCK_HPP