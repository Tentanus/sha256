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
    size_t i;

    // go over each word block
    for (i = 0 ; i < WORD_BLOCKS  ; i++)
    {
        // null the word
        _word[i] =  0;

        // go over the next 4 bytes in the string
        for (size_t idx = 0 ; idx < 4 && i * 4 + idx < length ; idx++)

            // and fill the byte into the word
            _word[i] += ((uint32_t) inp[(i * 4) + idx] << ((3 - idx) * 8));
    }

    // will this message block be fully filled
    if (length >= 55 ) 
    { // the block will be filled entirely
        return ;
    }
    else
    { // the block will be the final block
        // todo finalize the block
        
    }
}

MessageBlock::~MessageBlock() 
{

}

#endif // MESSAGE_BLOCK_HPP