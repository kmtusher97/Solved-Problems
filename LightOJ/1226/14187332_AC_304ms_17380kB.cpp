/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;
const int MX_N = 1002;
const intl MOD = 1000000007;
int n, a[MX_N];
intl fct[MX_N*MX_N], inv[MX_N*MX_N];

intl big_Mod( intl b, intl p ) {
  intl x = 1LL;
  for(; p>0; p>>=1) {
    if( p&1 ) x = (x*b) % MOD;
    b = (b*b) % MOD;
  }
  return x;
}

intl nCr( intl n, intl r ) {
  return ((fct[n]*inv[r]) % MOD * inv[n-r]) % MOD;
}

int main() {
  fct[0] = fct[1] = inv[0] = inv[1] = 1LL;
  for(intl i=2; i<MX_N*MX_N; i++) {
    fct[i] = (i*fct[i-1]) % MOD;
    inv[i] = big_Mod(fct[i], MOD-2) % MOD;
  }

  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    intl res = 1LL, sum = 0LL;
    for(int i=1; i<=n; i++) {
      scanf("%d", a+i);
      sum += a[i];
      res = (res * nCr(sum-1, a[i]-1)) % MOD;
    }
    printf("Case %d: %lld\n", ++caseno, res);
  }
  return 0;
}
