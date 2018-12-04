#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int TC, T=1;
    scanf("%d", &TC);
    while(TC--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("Case %d: %d\n", T++, a+b);
    }

    return 0;
}


