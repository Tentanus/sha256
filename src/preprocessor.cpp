
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
        MessageBlock block(&inp[i], remainingSize);
        
        msgs.emplace_back(block);
    }


}