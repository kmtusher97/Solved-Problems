/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 102
const int inf = 1234567;
int n, a[MX_N], ff[MX_N][MX_N];

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", a+i);
    memset(ff, 0, sizeof ff);
    for(int i=0; i<=n; i++)
    for(int j=1; j<=n; j++) {
      if( i+j>n ) continue;
      int sum = 0, res = -inf;
      for(int k=j; k<=i+j; k++) {
        sum += a[k];
        res = max(res, sum-ff[k+1][i+j]);
      }
      sum = 0;
      for(int k=i+j; k>=j; k--) {
        sum += a[k];
        res = max(res, sum-ff[j][k-1]);
      }
      ff[j][i+j] = res;
    }
    printf("Case %d: %d\n", ++caseno, ff[1][n]);
  }
  return 0;
}
