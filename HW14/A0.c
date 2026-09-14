#include <stdio.h>

int main(void)
{
    int N, val, cnt=0;
    int val_max = 1<<31;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &val);
        if(val > val_max){
            val_max = val;
            cnt=0;
        }
        else if(val==val_max && i!=0)
            cnt++;
    }

    printf("%d\n", cnt+1);
    return 0;
}