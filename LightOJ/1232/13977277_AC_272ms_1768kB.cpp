/** BISMILLAHIR RAHMANIR RAHIM **/

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

const int MX = 10005;
const intl mod = 100000007;
intl n, K, coin[102], ff[MX];

int main() {
    int cases, caseno = 0;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%lld %lld", &n, &K);
        for(int i=1; i<=n; i++) scanf("%lld", &coin[i]);
        memset(ff, 0, sizeof ff);
        ff[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=K; j++) {
                if( j>=coin[i] ) ff[j] = (ff[j]+ff[j-coin[i]])%mod;
            }
        }
        printf("Case %d: %lld\n", ++caseno, (ff[K]+mod)%mod);
    }
}
