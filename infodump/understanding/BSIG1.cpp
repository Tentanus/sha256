// C++ Code to perform left and right rotations 
// on the binary representation of a 32-bit integer
#include <bits/stdc++.h>
#include <iostream>

// Function to perform right rotation
uint32_t rightRotate(uint32_t n, uint32_t d) {
    
    // Rotation of 32 is same as rotation of 0
    d = d % 32;
    
    // Picking the leftmost d bits
    int mask = (1 << d) - 1;
    int shift = (n & mask);
    
    // Moving the remaining bits to their new location
    n = (n >> d);
    
    // Adding removed bits at rightmost end
    n += (shift << (32 - d));

    // Ensuring 32-bit constraint
    return n & ((1 << 32) - 1);
}

void showBSIG1(uint32_t x)
{
    uint32_t r1 = 6, r2 = 11, r3 = 25;
    
    uint32_t res1 = rightRotate(x, r1);
    uint32_t res2 = rightRotate(x, r2);
    uint32_t res3 = rightRotate(x, r3);
    
    uint32_t result = res1 ^ res2 ^ res3;
    
    //   std::cout << std::setiosflags (std::ios::showbase | std::ios::uppercase);
    std::cout << std::hex << std::setiosflags (std::ios::uppercase) <<
        std::setw(10) << x << "\n\t" <<
        std::setw(10) << res1 << "\n\t" <<
        std::setw(10) << res2 << "\n\t" <<
        std::setw(10) << res3 << "\n" <<
        "\t------------\n\t" << 
        std::setw(10) << result << "\n" << std::endl;

    return ;
}

// Driver code
int main() {
    
    uint32_t size = 4;
    uint32_t n[] = {
        0x000007FF,
        0x007FFFFF,
        0x1FFFFFFF
    };

    for (uint32_t i = 0 ; i < size ; i++)
    {
        showBSIG1(n[i]);
    }


    return 0;
}