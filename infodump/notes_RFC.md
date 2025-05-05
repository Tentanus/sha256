Notation for Bit Strings and Integers

The following terminology related to bit strings and integers will be
used:

a. A hex digit is an element of the set {0, 1, ... , 9, A, ... , F}.
   A hex digit is the representation of a 4-bit string. Examples: 

    7 = 0111, A = 1010.

b. A word equals a 32-bit or 64-bit string that may be represented
as a sequence of 8 or 16 hex digits, respectively.  To convert a
word to hex digits, each 4-bit string is converted to its hex
equivalent as described in (a) above.  Example:

    1010 0001 0000 0011 1111 1110 0010 0011 = A103FE23.

Throughout this document, the "big-endian" convention is used when
expressing both 32-bit and 64-bit words, so that within each word
the most significant bit is shown in the leftmost bit position.

c. An integer may be represented as a word or pair of words.

An integer between 0 and 2^32 - 1 inclusive may be represented as
a 32-bit word.  The least significant four bits of the integer are
represented by the rightmost hex digit of the word representation.
Example: 

    the integer: 291 =>
      0000 0000 0000 0000 0000 0001 0010 0011 =>
      2^8+2^5+2^1+2^0 => 
      256+32+2+1 is represented as
      00000123.

The same holds true for an integer between 0 and 2^64-1 inclusive,
which may be represented as a 64-bit word.

If Z is an integer, 0 <= z < 2^64, then z = (2^32)x + y where
0 <= x < 2^32 and 0 <= y < 2^32.  Since x and y can be represented
as words X and Y, respectively, z can be represented as the pair
of words (X,Y).

Again, the "big-endian" convention is used and the most
significant word is in the leftmost word position for values
represented by multiple-words.

d. block = 512-bit or 1024-bit string.  A block (e.g., B) may be
represented as a sequence of 32-bit or 64-bit words.

Preprocessing:
4.1.  Padding SHA-256

Suppose a message has length L < 2^64.  Before it is input to the
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
    01100001 01100010 01100011 01100100 01100101        (length: 40)
After step (a) this gives
    01100001 01100010 01100011 01100100 01100101 1

Since L = 40, the number of bits in the above is 41 and K = 407
"0"s are appended, making the total now 448.  This gives the
following in hex:

         61626364 65800000 00000000 00000000
         00000000 00000000 00000000 00000000
         00000000 00000000 00000000 00000000
         00000000 00000000

      The 64-bit representation of L = 40 is hex 00000000 00000028.
      Hence the final padded message is the following hex

         61626364 65800000 00000000 00000000
         00000000 00000000 00000000 00000000
         00000000 00000000 00000000 00000000
         00000000 00000000 00000000 00000028
