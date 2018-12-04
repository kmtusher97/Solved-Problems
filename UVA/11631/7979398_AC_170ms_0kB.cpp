#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define MX 200003

int parnt[MX];

struct data { int x, y, c; } ar[MX];

bool cmp(data X, data Y)
{
    if( X.c < Y.c ) return true;
    return false;
}

int bossfind(int x)
{
    if( parnt[x] == x ) return x;
    return parnt[x] = bossfind( parnt[x] );
}



main()
{
    int m, n, i, j, k;
    while( scanf("%d %d", &m, &n) == 2)
    {
        if( m == 0 && n == 0 ) break;
        LL TT = 0;
        for(i=0; i<n; i++) {
            scanf("%d %d %d", &ar[i].x, &ar[i].y, &ar[i].c);
            TT += ar[i].c;
        }
        for(i=0; i<m; i++) {
            parnt[i] = i;
        }
        sort(ar, ar+n, cmp);
        LL sum = 0, cnter = 0;

        for(i=0; i<n; i++) {
            int uu = bossfind( ar[i].x );
            int vv = bossfind( ar[i].y );

            if( uu != vv ) {
                parnt[ vv ] = uu;
                sum += ar[i].c;
                cnter++;
            }
            if( cnter == m-1 ) break;
        }

        printf("%lld\n", TT-sum);
    }

}
