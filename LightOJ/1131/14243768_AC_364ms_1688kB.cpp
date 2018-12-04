/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

intl n, Q, a[2], b[2], c[2], f[4], g[4], MOD;

struct matrix {
        intl mm[6][6] = { { 0, 1, 0, 0, 0, 0 },
                          { 0, 0, 1, 0, 0, 0 },
                          { 0, 9, 9, 9, 0, 0 },
                          { 0, 0, 0, 0, 1, 0 },
                          { 0, 0, 0, 0, 0, 1 },
                          { 9, 0, 0, 0, 9, 9 } };

        void init() { memset(mm, 0, sizeof mm); }

        matrix operator * ( matrix o ) const {
          matrix p; p.init();
          for(int i=0; i<6; i++)
          for(int j=0; j<6; j++)
          for(int k=0; k<6; k++)
            p.mm[i][j] = ( p.mm[i][j] + (mm[i][k]*o.mm[k][j])%MOD ) % MOD;

          return p;
        }
};

matrix expo() {
  matrix B, I; I.init();
  B.mm[2][1] = b[0], B.mm[2][2] = a[0], B.mm[2][3] = c[0];
  B.mm[5][4] = b[1], B.mm[5][5] = a[1], B.mm[5][0] = c[1];
  for(int i=0; i<6; i++) I.mm[i][i] = 1;
  for(intl p=n; p>0; p/=2) {
    if( p&1 ) I = I * B;
    B = B * B;
  }
  return I;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%lld %lld %lld", a+0, b+0, c+0);
    scanf("%lld %lld %lld", a+1, b+1, c+1);
    for(int i=0; i<3; i++) scanf("%lld", f+i);
    for(int i=0; i<3; i++) scanf("%lld", g+i);
    scanf("%lld %lld", &MOD, &Q);
    printf("Case %d:\n", ++caseno);
    while( Q-- ) {
      scanf("%lld", &n);
      matrix res = expo();
      intl resf = 0, resg = 0;
      for(int i=0; i<3; i++) {
        resf = (resf + res.mm[0][i]*f[i]) % MOD;
        resg = (resg + res.mm[3][i]*f[i]) % MOD;
      }
      for(int i=3; i<6; i++) {
        resf = (resf + res.mm[0][i]*g[i-3]) % MOD;
        resg = (resg + res.mm[3][i]*g[i-3]) % MOD;
      }

      if( !n ) printf("%lld %lld\n", f[0]%MOD, g[0]%MOD);
      else printf("%lld %lld\n", resf%MOD, resg%MOD);
    }
  }
  return 0;
}
