#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define modulo 1000000007
#define MX 75700

bool vis[MX];
vector<LL> prim;

void sieve() {
        prim.push_back(2);

        for(LL i=3; i<MX; i+=2)
                if( !vis[i] ) {
                        prim.push_back(i);
                        for(LL j=i; j<MX; j+=(i+i)) vis[j] = true;

} }

LL BigMod(LL b, LL p) {
        if( !p ) return 1;

        LL x = BigMod(b, p/2);
        x = ( (x%modulo) * (x%modulo) ) % modulo;
        if( p&1 ) {
                x = ( (b%modulo) * (x%modulo) ) % modulo;
        }

        return x;
}

LL sod(LL x, LL m) {
        LL i, j, sz = prim.size(), SOD = 1, lim = sqrt(x), mdd, mm;

        for(i=0; i<sz && prim[i] <= lim; i++) {
                if( x%prim[i] == 0 ) {
                        LL a = prim[i], pp = 0;
                        while( x%a == 0 ) {
                                pp++;
                                x/=a;
                        }
                        mm =  BigMod( a, (pp*m) + 1 );
                        mm = ( mm - 1 + modulo ) % modulo;
                        mdd = ( (mm % modulo) * ( BigMod( (a-1), modulo-2 ) % modulo ) ) % modulo;
                        SOD = ( (SOD % modulo) * (mdd % modulo) ) % modulo;
                }
        }

        if( x > 1 ) {
                mm =  BigMod( x, m + 1 );
                mm = ( mm - 1 + modulo ) % modulo;
                mdd = ( ( mm % modulo ) * ( BigMod( (x-1), modulo-2 ) % modulo ) ) % modulo;
                SOD = ( (SOD%modulo) * (mdd % modulo) ) % modulo;
        }

        return SOD;
}

main() {
        //freopen("OUTPUT.txt", "w", stdout);

        sieve();

        int cases, caseno = 0;
        LL n, m;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%lld %lld", &n, &m);
                LL nn = sod( n, m );
                printf("Case %d: %lld\n", ++caseno, nn);
        }
}
