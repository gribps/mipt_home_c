#include <stdio.h>
#include <inttypes.h>

typedef union 
{
    uint32_t N;
    struct
    {
        uint32_t byte_1_3 : 24; 
        uint32_t byte_4 : 8;
    };
} num;

int main(void)
{
    num N;
    scanf("%d", &N);
    N.byte_4 = ~N.byte_4;
    printf("%u\n", N);
    return 0;
}