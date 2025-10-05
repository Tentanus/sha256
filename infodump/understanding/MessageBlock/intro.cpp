#include "MessageBlock.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    const char str[] = "";
    // const char str[] = "aaaabbbbccccddddaaaabbbbccccddddaaaabbbbccccddddaaaabbbb";
    // const uint64_t bytes = sizeof(str) - 1; // sizeof() gives length + 1

    std::cout << "size: " << sizeof(str) << std::endl;
    const MessageBlock block = MessageBlock(str, 0, 0);

    std::cout << block << std::endl;
}