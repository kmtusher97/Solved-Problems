#include <stdio.h>

int main()
{
    int N;
    while(scanf("%d", &N)) {
        if(N == 42) break;
        else printf("%d\n", N);
    }


    return 0;
}
