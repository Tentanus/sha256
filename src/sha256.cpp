#include <cstdint>
#include <stdio.h>

#include "sha256.hpp"

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