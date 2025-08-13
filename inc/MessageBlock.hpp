#ifndef MESSAGE_BLOCK_HPP
#define MESSAGE_BLOCK_HPP

#include <cstdint>
#include <iostream>
#include <string>

// 1 message block
// 512 bits  
// 64 bytes  (16 x 4)

class MessageBlock
{
private:
    uint32_t _word[16];

public:
    MessageBlock(const char *inp);
    MessageBlock(const MessageBlock &rhs);
    ~MessageBlock();

    // Utility for debuggin
    const uint32_t &operator[](size_t idx) const;

};

const uint32_t &MessageBlock::operator[](size_t idx) const
{
    if (idx >= 16) { std::cout << "MessageBlock Operator out of bound" << std::endl; exit(0);} 
    return _word[idx]; 
}

static void printBits(uint32_t word)
{
    for (int j = 0; j < 8; j++)
    {   
        std::cout << ((word >> (32 - j - 1)) & 1);
    }
    std::cout << " ";
}

std::ostream &operator<<(std::ostream &os, const MessageBlock &block)
{
    os << "MsgBlk\n";
    for( size_t idx = 0 ; idx < 16 ; idx++ )
    {
        printBits(block[idx]);
        if (idx % 4 == 3) std::cout << "\n";
    }

    os << std::dec << std::endl;
    return (os);
}

MessageBlock::MessageBlock(const char *inp) 
{
    for (int i = 0 ; i < 16 ; i++)
    {
        _word[i] = 0;
        _word[i] =  ((uint32_t) inp[i    ] << 24 ) + 
                    ((uint32_t) inp[i + 1] << 16 ) + 
                    ((uint32_t) inp[i + 2] << 8  ) + 
                    ((uint32_t) inp[i + 3] << 0  );
    }
}

MessageBlock::~MessageBlock() 
{

}

#endif // MESSAGE_BLOCK_HPP