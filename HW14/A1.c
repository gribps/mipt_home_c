#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t N;
    scanf("%d ", &N);

    char c;
    while ((c=getchar())!= '\n')
    {
        if(c>='A' && c<='Z')
            putchar( (c-0x41+N)%26 + 0x41 );
        else if(c>='a' && c<='z')
            putchar( (c-0x61+N)%26 + 0x61 );
        else
            putchar(c);
    }

    return 0;
}