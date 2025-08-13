#include "MessageBlock.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    const MessageBlock block = MessageBlock("a\0a\0");

    std::cout << block << std::endl;
}