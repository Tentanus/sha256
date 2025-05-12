### Notation for Bit Strings and Integers

This section defines terminology for bit strings and integers:

- **Hex Digit**: A hex digit is one of {0, 1, ..., 9, A, ..., F}, representing a 4-bit string.  
  Examples:  
  - `7 = 0111`  
  - `A = 1010`

- **Word**: A word is a 32-bit or 64-bit string, represented as a sequence of 8 or 16 hex digits, respectively.  
  Conversion to hex digits involves converting each 4-bit string to its hex equivalent.  
  Example:  
  - `10100001 00000011 11111110 00100011 = A103FE23`

  The "big-endian" convention is used, meaning the most significant bit is on the leftmost position within a word.

- **Integer Representation**:  
  - A 32-bit word can represent integers between `0` and `2^32 - 1`.  
    The least significant 4 bits of the integer correspond to the rightmost hex digit.  
    Example:  
    - Integer `291` is represented as:  
      ```
      0000 0000 0000 0000 0000 0001 0010 0011 => 00000123
      ```
  - A 64-bit word can represent integers between `0` and `2^64 - 1`.  
    For an integer `Z` where `0 <= Z < 2^64`, it can be expressed as `Z = (2^32)x + y`, where `0 <= x, y < 2^32`.  
    `x` and `y` can be represented as words `X` and `Y`, respectively, making `Z` a pair of words `(X, Y)`.  
    The "big-endian" convention applies, with the most significant word on the left.

- **Block**: A block is a 512-bit or 1024-bit string, represented as a sequence of 32-bit or 64-bit words.

### Preprocessing:
4.1.  Padding SHA-256

Suppose a message has length L < 2^64. Before it is input to the
hash function, the message is padded on the right as follows:
a. "1" is appended.  Example: if the original message is "01010000",
   this is padded to "010100001".
b. K "0"s are appended where K is the smallest, non-negative solution
   to the equation
      ( L + 1 + K ) mod 512 = 448
c. Then append the 64-bit block that is L in binary representation.
   After appending this block, the length of the message will be a
   multiple of 512 bits.
   
Example: Suppose the original message is the bit string
ASCII   a  b  c  d  e
HEX     61 62 63 64 65
BIN     01100001 01100010 01100011 01100100
        01100101  
                                              (length: 40)
After step (a) this gives
        01100001 01100010 01100011 01100100 
        01100101 1  
                                              (length: 41)


Since L = 40, the number of bits in the above is 41 and K = 407
"0"s are appended, making the total now 448.  This gives the
following in hex:

HEX     61626364 65000000 00000000 00000000   128
        00000000 00000000 00000000 00000000   256
        00000000 00000000 00000000 00000000   384
        00000000 00000000                     512

    The 64-bit representation of L = 40 is hex 00000000 00000028.
    Hence the final padded message is the following hex

HEX     61626364 65800000 00000000 00000000   128
        00000000 00000000 00000000 00000000   256
        00000000 00000000 00000000 00000000   384
        00000000 00000000 00000000 00000028   512
