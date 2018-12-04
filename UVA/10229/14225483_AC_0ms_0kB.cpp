/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

intl n, m, MOD;

struct matrix {
        intl mm[3][3];

        matrix() { memset(mm, 0, sizeof mm); }

        matrix operator * ( matrix o ) const {
          matrix p;
          for(int i=1; i<=2; i++)
          for(int j=1; j<=2; j++)
            for(int k=1; k<=2; k++)
              p.mm[i][j] = ( p.mm[i][j] + (mm[i][k]*o.mm[k][j])%MOD ) % MOD;

          return p;
        }
};

matrix big_mod_expo( intl p ) {
  matrix b, x; MOD = 1<<m;
  b.mm[1][1] = 0, b.mm[1][2] = 1;
  b.mm[2][1] = 1, b.mm[2][2] = 1;

  x.mm[1][1] = 1, x.mm[1][2] = 0;
  x.mm[2][1] = 0, x.mm[2][2] = 1;

  for(; p>0; p/=2) {
    if( p&1 ) x = x*b;
    b = b*b;
  }
  return x;
}

int main() {
  while( ~scanf("%lld %lld", &n, &m) ) {
    matrix x = big_mod_expo( n );
    printf("%lld\n", x.mm[1][2]);
  }
  return 0;
}
