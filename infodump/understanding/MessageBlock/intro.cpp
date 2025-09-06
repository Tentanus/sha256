#include "MessageBlock.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    const char str[] = "babaisab";
    // const char str[] = "aaaabbbbccccddddaaaabbbbccccddddaaaabbbbccccddddaaaabbbb";
    const uint64_t bytes = sizeof(str) - 1; // sizeof() gives length + 1

    std::cout << "size: " << sizeof(str) << std::endl;
    const MessageBlock block = MessageBlock(str, bytes, bytes);

    std::cout << block << std::endl;
}