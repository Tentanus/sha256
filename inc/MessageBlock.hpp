#ifndef MESSAGE_BLOCK_HPP
#define MESSAGE_BLOCK_HPP

#include <cstdint>

// 1 message block
// 512 bits  
// 64 bytes  (16 x 4)

typedef struct MessageBlock
{
    uint32_t data[16];  // 16 x 32 bits = 512

}   MessageBlock;


#endif // MESSAGE_BLOCK_HPP