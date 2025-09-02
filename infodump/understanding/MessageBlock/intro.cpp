#include "MessageBlock.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    const char str[] = "bbbbaaaa";
    const uint64_t bytes = sizeof(str);

    std::cout << "size: " << sizeof(str) << std::endl; // so size gives plus 1
    const MessageBlock block = MessageBlock(str, bytes);

    std::cout << block << std::endl;
}