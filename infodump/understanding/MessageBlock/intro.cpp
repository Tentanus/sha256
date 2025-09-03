#include "MessageBlock.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    const char str[] = "babad";
    // const char str[] = "aaaabbbbccccddddaaaabbbbccccddddaaaabbbbccccddddaaaabbb";
    const uint64_t bytes = sizeof(str);

    std::cout << "size: " << sizeof(str) - 1 << std::endl;
    const MessageBlock block = MessageBlock(str, bytes);

    std::cout << block << std::endl;
}