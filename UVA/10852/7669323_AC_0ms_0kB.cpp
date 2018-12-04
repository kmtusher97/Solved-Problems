#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>

#define PI acos(-1)
#define i64 long long
#define ui64 unsigned long long
#define d64 double
#define dd64 long double
#define MX 10000

using namespace std;

bool vis[MX+5];

void sieve()
{
    int i, j, lim=sqrt(MX);

    vis[0]=vis[1]=true;

    for(i=2; i<=lim; i++)
        if(!vis[i]) {
            for(j=i; i*j<=MX; j++) vis[i*j]=true;
        }
}


main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    sieve();

    
    int tc, N, p, i, j, mx, x, ans=0;
    
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &N);

        x=N/2;
        p=x;
        j=0;

        while(p<N) {
            if(!vis[p] && p*2>N) { ans=p; break; }
            else p=x+(j++);
        }

        printf("%d\n", ans);
    }
}
