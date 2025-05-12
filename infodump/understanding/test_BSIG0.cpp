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


// Driver code
int main() {
    
    uint32_t n = 0x1FFFFFFF;
	uint32_t r1 = 2, r2 = 13, r3 = 22;
	
	uint32_t res1 = rightRotate(n, r1);
	uint32_t res2 = rightRotate(n, r2);
	uint32_t res3 = rightRotate(n, r3);

    uint32_t result = res1 ^ res2 ^ res3;

    //   std::cout << std::setiosflags (std::ios::showbase | std::ios::uppercase);
    std::cout << std::hex << std::setiosflags (std::ios::uppercase) <<
        std::setw(10) << n << "\n\n" <<
        std::setw(10) << res1 << "\n" <<
        std::setw(10) << res2 << "\n" <<
        std::setw(10) << res3 << "\n\n" <<
        std::setw(10) << result << std::endl;    
    return 0;
}