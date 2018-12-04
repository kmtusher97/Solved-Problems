/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX 1000005

typedef long long intl;
const int MX_N = 1002;
const intl MOD = 1000000007;
int n, a[MX_N];
intl fct[MX], inv[MX], sum[MX_N];

intl big_Mod( intl b, intl p ) {
  intl x = 1LL;
  for(; p>0; p/=2) {
    if( p&1 ) x = (b*x) % MOD;
    b = (b*b) % MOD;
  }
  return x;
}

inline intl nCr( intl nn, intl rr ) {
  return ( (fct[nn]*inv[rr]) % MOD * inv[nn-rr] ) % MOD;
}

int main() {
  fct[0] = fct[1] = inv[0] = inv[1] = 1LL;
  for(intl i=2; i<MX; i++) {
    fct[i] = (i * fct[i-1]) % MOD;
    inv[i] = big_Mod( fct[i], MOD-2 );
  }

  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
      scanf("%d", a+i);
      sum[i] = sum[i-1]+a[i];
    }

    intl res = 1LL;
    for(int i=1; i<=n; i++) {
      res = (res * nCr( sum[i]-1, a[i]-1 ) ) % MOD;
    }
    printf("Case %d: %lld\n", ++caseno, res%MOD);
  }
  return 0;
}
