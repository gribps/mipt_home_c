#include <stdio.h>

int main(void)
{
    unsigned int N, k;
    scanf("%d %d", &N, &k);
    printf("%u\n", ((1U<<k)-1) & N);
    return 0;
}