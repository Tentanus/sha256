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
        std::cerr << 
        "MessageBlock Operator out of bound [" << idx << "]" << std::endl; 
        exit(1);
    } 
    return _word[idx]; 
}

static void printWordBits(const uint32_t word)
{
    for (int j = 0; j < 32; j++)
    {   
        std::cout << ((word >> (32 - j - 1)) & 1);
        if (j % 8 == 7) std::cout << " ";
    }
}
static void printWordHex(const uint32_t word) {
    std::cout << std::hex << word << std::dec;
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
        printWordBits(block[idx]); // print word in bits
        std::cout << ": "; 
        printWordHex(block[idx]); // print word in Hex
        // std::cout << "\t: ";
        // printWordChar 
        std::cout << "\n";
        
    }

    return (os);
}

MessageBlock::MessageBlock(const char *inp, const uint64_t length)
{
    // variable to keep track of position in input string
    size_t idx;

    // go over each word block
    for (size_t i = 0 ; i < WORD_BLOCKS ; i++)
    {
        // null the word block
        _word[i] =  0;

        // go over the next 4 bytes in the string
        for (size_t j = 0 ; j < 4 && i * 4 + j < length ; j++)
        {
            // save the position in the string for later use
            idx = (i * 4) + j;
    
            // and fill the byte into the word
            _word[i] += ((uint32_t) inp[(i * 4) + j] << ((3 - j) * 8));
        }
    }
    
    // go to the next posistion
    idx++;
    
    // set the terminating byte
    _word[(idx >> 2)] += (0x80 << (3 - (idx & 0x3)) * 8);

    // is this the final messageblock
    if (idx >> 2 < WORD_BLOCKS - 2) 
        return ;// the block will be filled entirely

    else
    { // the block will be the final block
        // todo: finalize block
        std::cout << "we need to finalize" << std::endl;
    
        return ;
    }
}

MessageBlock::~MessageBlock() 
{

}

#endif // MESSAGE_BLOCK_HPP