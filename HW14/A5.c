#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t N, sum=0;
    scanf("%d", &N);

    for(int i=0; i<=31; i++)
        if(N & (1U<<i))
            sum++;
    
    printf("%u\n", sum);
    return 0;
}