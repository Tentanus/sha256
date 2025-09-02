#include "MessageBlock.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    const MessageBlock block = MessageBlock("a\0a\0b\0b\0");

    std::cout << block << std::endl;
}