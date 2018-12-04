/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;
const int MX_N = 16;
intl n, m, a[MX_N];

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%lld %lld", &n, &m);
    for(int i=0; i<m; i++) scanf("%lld", a+i);

    intl res = n;
    for(int mask=1, lim=(1<<m); mask<lim; mask++) {
      intl tmp = 1LL, cnt = 0LL;
      for(int i=0; i<m; i++) {
        if( !(mask&(1<<i)) ) continue;
        tmp = (tmp * a[i]) / __gcd(tmp, a[i]), cnt++;
      }
      if( cnt&1 ) res -= (n/tmp);
      else res += (n/tmp);
    }
    printf("Case %d: %lld\n", ++caseno, res);
  }
  return 0;
}
