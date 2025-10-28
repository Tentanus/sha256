#include "MessageBlock.hpp"

// --------------------   Constructors   --------------------   

/**
 *  Constructor
 *  This constructor parses the input string into messageblocks of 512 bits long,,
 *  skipping null terminators
 *  
 *  @param  inp     const char *        C-str with to be hashed info (this could contain '\0')
 *  @param  lenght  const uint64_t      Amount of bytes of the string to hash
 *  @param  total   const uint64_t      Total amount of bits that has been hashed
 */
MessageBlock::MessageBlock(const char *inp, const uint64_t length, const uint64_t total)
{
    // variable to keep track of position in input string
    size_t lastSetByte = 0;

    // go over each word block
    for (size_t wordIndex = 0 ; wordIndex < WORD_BLOCKS ; wordIndex++)
    {
        // null the word block
        _word[wordIndex] = 0;

        // go over the next 4 bytes in the string
        for (size_t wordSubIndex = 0 ; wordSubIndex < 4 && wordIndex * 4 + wordSubIndex < length ; wordSubIndex++)
        {
            // save the position in the string for later use
            lastSetByte = wordIndex * 4 + wordSubIndex;

            // and fill the byte into the word
            _word[wordIndex] += ((uint32_t) inp[(wordIndex * 4) + wordSubIndex] << ((3 - wordSubIndex ) * 8));
        }
    }

    // go to the next posistion in the word only if we have actually moved
    if (length) lastSetByte++;

    // set the terminating byte
    _word[(lastSetByte >> 2)] += (0x80 << (3 - (lastSetByte & 0x3)) * 8);

    // When this is the final messageblock
    if (lastSetByte >> 2 < WORD_BLOCKS - 2)
    {

        // add the total length to the final messageblock
        _word[WORD_BLOCKS - 2] = (total >> 32) & 0xFFFFFFFF;
        _word[WORD_BLOCKS - 1] = (total      ) & 0xFFFFFFFF;
    }
}

/**
 *  Constructor
 *  This constructor parses the input and terminates at a null terminator
 *  
 *  @param  inp     const char *        C-str with to be hashed info
 *  @param  total   const uint64_t      Total amount of bits that has been hashed
 */
MessageBlock::MessageBlock(const char *inp, const uint64_t total)
{
    // return if we don't even have an input string
    // ? make an exception for this
    if (!inp) return ;

    // variable to keep track of position in input string
    size_t  lastSetByte = 0;

    // go over each word block
    for (size_t wordIndex = 0 ; wordIndex < WORD_BLOCKS ; wordIndex++)
    {
        // null the word block
        _word[wordIndex] = 0;
     
        // skip setting bytes is we don't have a string
        if (inp[lastSetByte] == '\0') continue;
        
        // go over the next 4 bytes in the string
        for (lastSetByte = wordIndex * 4 ; lastSetByte < (wordIndex * 4 + 4) ; lastSetByte++)
        {
            // and fill the byte into the word
            _word[wordIndex] += ((uint32_t) inp[lastSetByte] << ((3 -(lastSetByte & 0x3)) * 8));

            std::cout << "lastsetByte: " << lastSetByte << std::endl;
            if (inp[lastSetByte] == '\0') break;
        }
    }

    // check if we have even set any bytes
    if (!lastSetByte) return ;

    // set the terminating byte
    _word[(lastSetByte >> 2)] += (0x80 << (3 - (lastSetByte & 0x3)) * 8);

    // When this is the final messageblock
    if (lastSetByte >> 2 < WORD_BLOCKS - 2)
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

