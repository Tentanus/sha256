#include <iostream>
#include "inc/sha256.hpp"

void showWork(uint32_t i, uint32_t x) {
    uint32_t rot6 = ROTR(i, 6);
    uint32_t rot11 = ROTR(i, 11);
    uint32_t rot25 = ROTR(i, 25);

    std::cout <<    "Show:\t\t" << std::hex <<
                    rot6 << "\n\t\t" <<
                    rot11 << "\n\t\t" <<
                    rot25  << std::endl;
    std::cout  << std::hex << "=>\t\t" << x << std::dec << std::endl;
}

int main(int argc, char *argv[]) {
    (void)argv; // Suppress unused parameter warning
    (void)argc; // Suppress unused parameter warning

    uint32_t nbrs[3] = {
        // 0x0000007F,
        // 0x0000184F,
        0x01343CAC,
        0x0202E912,
        0x26DE0C36,
    };

    for (uint32_t i = 0; i < 3; i++) {
        uint32_t x = BSIG1(nbrs[i]);
        if (!x) {std::cout << "skip(" << i << ")" << std::endl; continue; }// Skip if x is 0
        showWork(nbrs[i], x);
    }

    return 0;
}