#include "sha256.hpp"

void sha256::setupSchedule(uint32_t* W, MessageBlock& block)
{
    for (size_t i = 0; i < SCHEDULE_SIZE ; i++)
        W[i] = 0x00000000;
    block.setupSchedule(W);
}

char *sha256(const char *str, uint64_t size)
{
    std::cout << "sha256\n";
    std::vector<MessageBlock> MsgBlk;

    //TODO: propperly implement multiple MessageBlocks
    //-     Currently i don't this works correctly when a blocks is longer then 448 bits
    for (int i = 0 ; size + 1 > 448 ;  i =+ SHA256_MESSAGE_SIZE)
    {
        std::cout << "i = " << i << std::endl;
        
        MessageBlock block(&str[i], size, i);
        std::cout << block;
        MsgBlk.emplace_back(block);
    }

    showBlocks(MsgBlk);

    return (NULL);
}

const std::string sha256::process(std::vector<MessageBlock> input)
{
    uint32_t W[SCHEDULE_SIZE];
    uint32_t a,b,c,d,e,f,g,h;

    for (MessageBlock &block : input)
    {
        setupSchedule(W, block);
    }
}

void showBlocks(std::vector<MessageBlock> list)
{
    std::cout << "showBlocks\n";
    
    for (size_t i = 0 ; i < list.size() ; i++)
    {
        MessageBlock &block = list[i];
        std::cout << block << std::endl;
    }
}