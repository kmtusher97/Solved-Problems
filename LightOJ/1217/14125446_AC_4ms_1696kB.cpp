/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 1005
int n, a[MX_N], ff[MX_N];

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", a+i);
    ff[1] = a[1];
    for(int i=2; i<n; i++) {
      ff[i] = max(ff[i-1], a[i]+ff[i-2]);
    }
    int res = ff[n-1];
    ff[1] = 0;
    for(int i=2; i<=n; i++) {
      ff[i] = max(ff[i-1], a[i]+ff[i-2]);
    }
    res = max(res, ff[n]);
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
