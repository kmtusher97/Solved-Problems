#include <bits/stdc++.h>

using namespace std;

#define MX 100005

main()
{
    int n, i, j, sd, ar[MX], m, sm;
    while( scanf("%d %d", &n, &m) == 2 ) {
        for(i=1; i<=n; i++) scanf("%d", &ar[i]);
        int mx = INT_MAX;
        for(i=1, sd = 0, sm = 0; i<=n; i++) {
            sm+=ar[i];
            sd++;
            if( sm>=m ) {
                while( sm>=m ) {
                    mx = min(sd, mx);
                    sd--;
                    sm-=(ar[ i-sd ]);
                }
            }
        }
        if( mx == INT_MAX ) mx = 0;
        printf("%d\n", mx);
    }
}
