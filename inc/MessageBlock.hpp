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
    MessageBlock(const char *inp);
    MessageBlock(const char *inp, const uint64_t length);
    ~MessageBlock();

    // Utility for debuggin
    const uint32_t &operator[](size_t idx) const;

};

const uint32_t &MessageBlock::operator[](size_t idx) const
{
    if (idx >= WORD_BLOCKS)
    { 
        std::cout << 
        "MessageBlock Operator out of bound [" << idx << "]" << std::endl; 
        exit(0);
    } 
    return _word[idx]; 
}

static void printWordBits(uint32_t word)
{
    for (int j = 0; j < 32; j++)
    {   
        std::cout << ((word >> (32 - j - 1)) & 1);
        if (j % 8 == 7) std::cout << " ";
    }
}
// static void printWordChar(uint32_t word)
// {
//     std::cout << "0x" << std::hex;
//     for (int j = 0; j < 4; j++)
//     {
//         uint8_t byte = (word >> (24 - j * 8)) & 0xFF;
//         std::cout <<  (int)byte << " ";
//     }
//     std::cout << std::dec;
// }

std::ostream &operator<<(std::ostream &os, const MessageBlock &block)
{
    os << "MsgBlk: \n";
    for( size_t idx = 0 ; idx < WORD_BLOCKS ; idx++ )
    {
        std::cout << "[" << idx << "]\t";
        printWordBits(block[idx]);
        std::cout << ": " << std::hex << block[idx] << std::dec << std::endl;
    }

    os << std::dec << std::endl;
    return (os);
}

MessageBlock::MessageBlock(const char *inp, const uint64_t length) 
{
    (void) length;
    for (int i = 0 ; i < WORD_BLOCKS ; i++)
    {
        _word[i] = 0;
        _word[i] =  ((uint32_t) inp[(i * 4)    ] << 24 ) + 
                    ((uint32_t) inp[(i * 4) + 1] << 16 ) + 
                    ((uint32_t) inp[(i * 4) + 2] << 8  ) + 
                    ((uint32_t) inp[(i * 4) + 3] << 0  );
    }
}

MessageBlock::~MessageBlock() 
{

}

#endif // MESSAGE_BLOCK_HPP