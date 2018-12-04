#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, tc=0, N, i, sum, d;

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);

        for(i=0, sum=0; i<N; i++) {
            scanf("%d", &d);

            if(d>0) sum+=d;
        }


        printf("Case %d: %d\n", ++tc, sum);
    }


    return 0;
}
