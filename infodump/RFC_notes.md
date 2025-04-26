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
