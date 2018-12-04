/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;

intl a, b, n, m, MOD;
struct matrix {
        intl mm[2][2] = { { 0, 1 },
                         { 1, 1 } };

        void init() { memset(mm, 0, sizeof mm); }

        matrix operator * ( matrix o ) const {
          matrix t; t.init();
          for(int i=0; i<2; i++)
          for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
              t.mm[i][j] = ( t.mm[i][j] + (mm[i][k] * o.mm[k][j]) % MOD ) % MOD;
          return t;
        }
};

intl expo( intl p ) {
  matrix B, I; I.init();
  I.mm[0][0] = I.mm[1][1] = 1;

  for(; p>0; p>>=1) {
    if( p&1 ) I = I * B;
    B = B * B;
  }
  return (b*I.mm[1][1] + a*I.mm[1][0]) % MOD;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
    MOD = 1LL;
    for(int i=0; i<m; i++) MOD *= 10LL;

    intl res = expo( n-1 );
    if( n==0 ) res = a;
    printf("Case %d: %lld\n", ++caseno, res%MOD);
  }
  return 0;
}
