/*
<-- Encoding -->
Encode(DATAWORD using KEY) ==> CODEWORD

DATAWORD needs to be encoded using the KEY(k) bits obtained from generator polynominal(k bits is the divisor)
1. Take DATAWORD bits as input and append (k-1) 0 bits to it.
2. Perform modulo-2 binary division to divide the binary data by key.
3. Repeat step 2 but start division from the leading 1. Stop the division when no. of bits from the leading 1 in the dividend is less than k bits.
4. Replace the earlier appended bits to the DATAWORD with remainder(i.e. CRC... we will get k-1 bits) to form the CODEWORD.

<-- Decoding -->
Perform modulo-2 division for the CODEWORD again and if the SYNDROME(remainder) is 0, then there are no errors.
*/

#include <stdio.h>
#include <string.h>

char key[100];
int keyLen;

void divider()
{
    char inp[100]; // dataWord
    printf("Enter input data:- ");
    scanf("%s", inp);
    int inpLen = strlen(inp);
    
    // Appending (k-1) 0 bits to the input
    for (int i = 0; i < keyLen - 1; ++i)
        inp[inpLen + i] = '0';
    inp[inpLen + keyLen - 1] = '\0';

    inpLen = strlen(inp); // Updating inpLen after appending 0s

    char encodedInp[inpLen]; // encodedInp = inp + last3BitsOfInp
    for (int i = 0; i < inpLen; ++i)
    {
        encodedInp[i] = inp[i];
    }
    encodedInp[inpLen] = '\0';

    for (int i = 0; i < inpLen - keyLen + 1;)
    {
        // perform XOR for every bit
        for (int j = 0; j < keyLen; ++j)
        {   
            // printf("Performing xor of %c ^ %c\n", inp[i+j], key[j]);
            inp[i + j] = (inp[i + j] == key[j] ? '0' : '1');
        }

        // Find the index i such that MSB=1 i.e. skipping all 0's.
        // Since, there is no need of performing division when MSB of inp is 0
        while (i < inpLen && inp[i] == '0')
        {
            // printf("%s the char at i=%d is %c hence skipping\n", inp, i, inp[i]);
            ++i;
        }
    }

    for (int i = inpLen - keyLen + 1; i < inpLen; ++i)
        encodedInp[i] = inp[i];
    
    printf("Encoded input is %s", encodedInp); // codeWord
}

int main()
{
    printf("Enter the key(divisor):- ");
    scanf("%s", key);
    keyLen = strlen(key);
    divider();
    return 0;
}