#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t N, k, mask, max=0;
    scanf("%d %d", &N, &k);
    mask = (1U<<k)-1;

    for(int i=0; i <= 32-k; i++){
        uint32_t tmp = (N & (mask<<i))>>i;
        if(max < tmp)
            max = tmp;
    }

    printf("%u\n", max);

    return 0;
}