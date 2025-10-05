#include "MessageBlock.hpp"

// --------------------   Constructors   --------------------   

MessageBlock::MessageBlock(const char *inp, const uint64_t length,const uint64_t total)
{
    // variable to keep track of position in input string
    size_t idx;

    // go over each word block
    for (size_t i = 0 ; i < WORD_BLOCKS ; i++)
    {
        // null the word block
        _word[i] = 0;

        // go over the next 4 bytes in the string
        for (size_t j = 0 ; j < 4 && i * 4 + j < length ; j++)
        {
            // save the position in the string for later use
            idx = (i * 4) + j;
    
            // and fill the byte into the word
            _word[i] += ((uint32_t) inp[(i * 4) + j] << ((3 - j) * 8));
        }
    }
    
    // go to the next posistion in the word
    idx++;
    
    // set the terminating byte
    _word[(idx >> 2)] += (0x80 << (3 - (idx & 0x3)) * 8);

    // When this is the final messageblock
    if (idx >> 2 < WORD_BLOCKS - 2)
    {

        // add the total length to the final messageblock
        _word[WORD_BLOCKS - 2] = (total >> 32) & 0xFFFFFFFF;
        _word[WORD_BLOCKS - 1] = (total      ) & 0xFFFFFFFF;
    }
}

MessageBlock::~MessageBlock() 
{

}

// --------------------    Operators    --------------------   

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
std::ostream &operator<<(std::ostream &os, const MessageBlock &block)
{
    os << "MsgBlk: \n";
    for( size_t idx = 0 ; idx < WORD_BLOCKS ; idx++ )
    {
        std::cout << "[" << idx << "]\t";
        printWordBits(block[idx]); // print word in bits
        std::cout << ": "; 
        printWordHex(block[idx]); // print word in Hex
        std::cout << "\n";
    }
   return (os);
}

