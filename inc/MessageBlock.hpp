#ifndef MESSAGE_BLOCK_HPP
#define MESSAGE_BLOCK_HPP

#include <cstdint>

// 1 message block
// 512 bits  
// 64 bytes  (16 x 4)

class MessageBlock
{
private:
    uint32_t _word[16];

public:
    MessageBlock(const char *inp, uint64_t &size);
    MessageBlock(const MessageBlock &rhs);
    ~MessageBlock();

};

MessageBlock::MessageBlock(const char *inp, uint64_t &size) {
    if (size > 448)
    {
        for (int i = 0 ; i < 15 ; i++)
        {
            _word[i] =  (uint32_t) inp[i]       << 24 + 
                        (uint32_t) inp[i + 1]   << 16 + 
                        (uint32_t) inp[i + 2]   << 8 + 
                        (uint32_t) inp[i + 3]   << 0;
        }
    }
}

#endif // MESSAGE_BLOCK_HPP