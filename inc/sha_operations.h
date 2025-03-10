#ifndef SHA_OPERATIONS_H
#define SHA_OPERATIONS_H

#define ROTL(x, n) ((x << n) | (x >> (WORD_SIZE - n)))
#define ROTR(x, n) ((x >> n) | (x << (WORD_SIZE - n)))

#endif // !#ifndef SHA_OPERATIONS_H
