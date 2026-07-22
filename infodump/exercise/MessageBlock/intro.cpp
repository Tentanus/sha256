#include "MessageBlock.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    // const char str[] = "abcd    ";
    const char str[] = "aaaa    aaaa    aaaa    aaaa    aaaa    aaaa    aaaa  ";
    // const char str[] = "aaaabbbbccccddddaaaabbbbccccddddaaaabbbbccccddddaaaabbbb";
    const uint64_t bytes = sizeof(str); // sizeof() gives length + 1

    std::cout << "size: " << sizeof(str) << std::endl;
    const MessageBlock block = MessageBlock(str, bytes * 8);
    // todo: we should pass the length in bits not bytes.

    std::cout << block << std::endl;
}