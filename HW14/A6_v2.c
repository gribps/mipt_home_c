#include <stdio.h>
#include <inttypes.h>

typedef union 
{
    uint32_t val;
    uint8_t bytes[4];
} num;

int main(void)
{
    num N;
    scanf("%d", &N);
    N.bytes[3] ^= 0xFF;
    printf("%u\n", N);
    return 0;
}