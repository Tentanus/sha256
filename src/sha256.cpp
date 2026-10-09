#include "sha256.hpp"

void sha256::setupSchedule(uint32_t* W, MessageBlock& block)
{
    for (size_t i = 0; i < SCHEDULE_SIZE ; i++)
        W[i] = 0x00000000;
    block.setupSchedule(W);
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

char *sha256(const char *str, uint64_t size)
{
    std::cout << "sha256\n";
    std::vector<MessageBlock> list = preprocessor(str, size);

    showBlocks(list);

    return (NULL);
}