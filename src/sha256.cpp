#include "sha256.hpp"

void sha256::setupSchedule(uint32_t* W, MessageBlock& block)
{
    for (size_t i = 0; i < SHA256_SCHEDULE_SIZE ; i++)
        W[i] = 0x00000000;
    block.setupSchedule(W);
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

    return (process(MsgBlk));
}

// TODO: Write tests for process method
const std::string sha256::process(std::vector<MessageBlock> input)
{
    uint32_t W[SHA256_SCHEDULE_SIZE];
    uint32_t a,b,c,d,e,f,g,h, temp1, temp2;
    uint32_t H[8] = {
        sha256::f_const[0],
        sha256::f_const[1],
        sha256::f_const[2],
        sha256::f_const[3],
        sha256::f_const[4],
        sha256::f_const[5],
        sha256::f_const[6],
        sha256::f_const[7]
    };

    // Go over each Message Block
    for (MessageBlock &block : input) {

        // Add the Message blocks to the schedule
        setupSchedule(W, block);

        // Fill in the rest of the schedule
        for (int t = 16; t < SHA256_SCHEDULE_SIZE; t++)
            W[t] = SSIG1(W[t-2]) + W[t - 7] + SSIG0(W[t-15]) + W[t-16];

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
    
        // Separate the indiviual Hex letter values
        for (int hex = 0 ; hex < 8 ; hex++) {

            // write the letter to the resulting string
            res[idxH * 8 + hex] = (H[idxH] << (7 - hex) * 8) & 0xFF; 
        }
    }

    const std::string str(res);

    return (str);
}

// --------------------   Debug Methods   --------------------

void showBlocks(std::vector<MessageBlock> list)
{
    std::cout << "showBlocks\n";

    for (size_t i = 0 ; i < list.size() ; i++) {

        MessageBlock &block = list[i];
        std::cout << block << std::endl;
    }
}