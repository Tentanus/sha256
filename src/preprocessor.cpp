
#include "sha256.hpp"
#include <string.h>

std::vector<MessageBlock> preprocessor(const char *inp, const uint64_t size)
{
    //  [x] get length of message
    // ~[ ] determine the amount of blocks
    //  [ ] write inp to the numbers
    //  [ ] add extra 1 behind message
    //  [ ] add padding (K '0') till last messageBlock is 448
    //  [ ] add 
    std::vector<MessageBlock> msgs;
    uint64_t remainingSize = size;

    for (int i = 0 ; remainingSize + 1 > 448 ;  i =+ SHA256_MESSAGE_SIZE)
    {
        MessageBlock block(&inp[i], remainingSize, i);
        
        msgs.emplace_back(block);
    }
    return msgs;
}