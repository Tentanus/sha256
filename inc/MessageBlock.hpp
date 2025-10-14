#ifndef MESSAGE_BLOCK_HPP
#define MESSAGE_BLOCK_HPP

#include <cstdint>
#include <iostream>
#include <string>

// 1 message block
// 512 bits  
// 64 bytes  (16 x 4)

#define WORD_BLOCKS 16

/**
 *  MessageBlock
 *  
 * 
 *  @param      inp     const char *        the input string to parse
 *  @param      length  const uint64_t      the length required to still be parsed in bytes
 *  @param      total   const uint64_t      the the total lenght of parsed input in bytes
 * 
 *  @attention      
 *  Messageblock constructor doesn't support passing more bytes. This is undefined behaviour.
 *  
 *  @author         Tentanus  
 *  @date           14-10-2025
 */
class MessageBlock
{
private:
    uint32_t _word[WORD_BLOCKS];

public:
    // Constructors
    MessageBlock(const char *inp, const uint64_t length, const uint64_t total); 
    // todo: we should pass the length in bits not bytes.
    // 
    // ? Is it possible to do all this with just one block?
    // ? and just have an array of ints that we can do stuff with.
    MessageBlock(const MessageBlock &rhs);
    ~MessageBlock();

    // Utility for debuggin
    const uint32_t &operator[](size_t idx) const;

};

std::ostream &operator<<(std::ostream &os, const MessageBlock &block);

#endif // MESSAGE_BLOCK_HPP