#include <stdio.h>
#include <string.h>

char key[100];
int keyLen;

void divider()
{
    char inp[100]; // encoded input
    printf("Enter the encoded input data:- ");
    scanf("%s", inp);
    int inpLen = strlen(inp);

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
    int k = 0;
    char syndrome[keyLen];
    for (int i = inpLen - keyLen + 1; i < inpLen; ++i, ++k)
    {
        syndrome[k] = inp[i];
    }
    syndrome[k] = '\0';

    printf("Syndrome is %s\n", syndrome);
    for (int i = 0; i <= keyLen - 1; ++i) {
        if(syndrome[i] == '1') {
            printf("Dataword is rejected");
            return;
        }
    }
    printf("Dataword is accepted");
}

int main()
{
    printf("Enter the key(divisor):- ");
    scanf("%s", key);
    keyLen = strlen(key);
    divider();
    return 0;
}