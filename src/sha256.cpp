#include "sha256.hpp"


// Constants
static const uint32_t k_const[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4,
    0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe,
    0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f,
    0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
    0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
    0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116,
    0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7,
    0xc67178f2
};

static const uint32_t f_const[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19,
};

// --------------------    Debug Methods    --------------------

void showBlocks(std::vector<MessageBlock> list)
{
    std::cout << "showBlocks: \n";

    for (size_t i = 0 ; i < list.size() ; i++) {

        MessageBlock &block = list[i];
        std::cout << block << std::endl;
    }
}

// --------------------   SHA256 Methods   --------------------

static void setupSchedule(uint32_t* W, MessageBlock& block)
{
    // All words are set to zero
    for (size_t i = 0; i < SHA256_SCHEDULE_SIZE ; i++)
        W[i] = 0x00000000;

    // fill in our own hash values form the MessageBlock
    block.setupSchedule(W);

    // Fill/Generate the rest of the schedule
    for (int t = 16; t < SHA256_SCHEDULE_SIZE; t++)
        W[t] = SSIG1(W[t-2]) + W[t - 7] + SSIG0(W[t-15]) + W[t-16];
}

// TODO: Write tests for process method
const std::string process(std::vector<MessageBlock> input)
{
    uint32_t W[SHA256_SCHEDULE_SIZE];
    uint32_t a,b,c,d,e,f,g,h, temp1, temp2;
    uint32_t H[8] = {
        f_const[0],
        f_const[1],
        f_const[2],
        f_const[3],
        f_const[4],
        f_const[5],
        f_const[6],
        f_const[7]
    };

    // Go over each Message Block
    for (MessageBlock &block : input) {

        // Add the Message blocks to the schedule
        setupSchedule(W, block);

        // set the initial values
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h = H[7];

        // perform the main hash computation
        for (int t = 0; t < SHA256_SCHEDULE_SIZE; t++) {
            temp1 = h + BSIG1(e) + Ch(e, f, g) + k_const[t] + W[t];
            temp2 = BSIG0(a) + Maj(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // Add the hashes to H(i)
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    // finalize the string
    char res[65];
    res[64] = '\0';

    // Go over each resulting Hash value
    for (int idxH = 0 ; idxH < 8 ; idxH++) {
    
        // Separate the indiviual Hex letter values in H[i] (uint32_t)
        for (int hex = 0 ; hex < 8 ; hex++) {

            // Extract the letter from H[i] and add the appropriate char shift 
            res[idxH * 8 + hex] =   (( H[idxH] >> (8 - hex) * 4) & 0xF) +
                                    (((H[idxH] >> (8 - hex) * 4) & 0xF) > 9 ? '7' : '0');
        }
    }

    return (std::string (res));
}

const std::string sha256::hash(const char *str, uint64_t size)
{
    std::cout << "sha256\n";
    std::vector<MessageBlock> MsgBlk;

    //TODO: propperly implement multiple MessageBlocks
    //-     Currently i don't this works correctly when a blocks is longer then 448 bits
    for (int i = 0 ; size + 1 > 448 ;  i =+ SHA256_MESSAGE_SIZE) {
        std::cout << "i = " << i << std::endl;

        MessageBlock block(&str[i], size, i);
        std::cout << block;
        MsgBlk.emplace_back(block);
    }

    showBlocks(MsgBlk);

    const std::string res = process(MsgBlk);

    std::cout << "hashed input: " << res << std::endl;

    return (res);
}