#include <stdio.h>

int main(void)
{
    unsigned int N, res;
    int k;
    scanf("%d %d", &N, &k);

    res = (N>>k) | (N<<(32-k));
    printf("%u\n", res);
    return 0;
}