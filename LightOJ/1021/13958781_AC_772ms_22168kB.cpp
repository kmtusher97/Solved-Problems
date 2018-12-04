/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

#define MX_N 17

typedef long long intl;

intl n, b, k, a[MX_N], ff[1<<MX_N][20];
char nm[MX_N];

intl dp( int mask, intl rmndr )
{
    if( mask==(1<<n)-1 )
    {
        if( rmndr%k==0 ) return 1LL;
        return 0LL;
    }
    intl& ret = ff[mask][rmndr];
    if( ~ret ) return ret;

    ret = 0LL;
    for(int i=0; i<n; i++)
    {
        if( mask&(1<<i) ) continue;
        ret += dp( mask|(1<<i), (a[i] + (b*rmndr))%k );
    }
    return ff[mask][rmndr] = ret;
}

int main()
{
    int cases, caseno = 0;
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%lld %lld %s", &b, &k, nm);
        n = strlen(nm);
        bool ok = true;
        for(int i=0; i<n; i++)
        {
            if( nm[i]>='0' && nm[i]<='9' ) a[i] = nm[i]-'0';
            else a[i] = nm[i]-55;
            if( a[i]>=b ) ok = false;
        }
        sort(a, a+n);
        printf("Case %d: ", ++caseno);
        if( !ok )
        {
            printf("0\n");
            continue;
        }
        memset(ff, -1, sizeof ff);
        intl res = dp( 0, 0 );
        printf("%lld\n", res);
    }
    return 0;
}
