
#include "sha256.hpp"
#include <string.h>

//? private method in messagebock
int validateInput(const char *inp)
{
    // check if is given
    if (!inp) return FAILURE;

    // go over values to see if 
    int i = 0;
    while (i < 16) if (inp[i++]) return FAILURE;
}

//? could be public method for MessageBlock 
int writeMessageBlock(MessageBlock &block, const char *inp)
{
    if (validateInput(inp)) 
        return FAILURE;

    for (int i = 0 ; i < 11 ; i += 4)
    {
        block.data[i] = (uint32_t) inp[i] << 24 + 
                        (uint32_t) inp[i + 1] << 16 + 
                        (uint32_t) inp[i + 2] << 8 + 
                        (uint32_t) inp[i + 3] << 0;
    }
}

std::vector<MessageBlock> preprocessor(const char *inp, const uint64_t size)
{
    //  [x] get length of message
    // ~[ ] determine the amount of blocks
    //  [ ] write inp to the numbers
    //  [ ] add extra 1 behind message
    //  [ ] add padding (K)
    std::vector<MessageBlock> msgs;
    uint64_t remainingSize = size;

    // keep the loop going till last block is given
    // L + 1 + K = 448
    for (int i = 0 ; remainingSize + 1 + 64 > 448 ;  i =+ 512)
    {
        MessageBlock block;
        writeMessageBlock(block, &inp[i]);
    }


}