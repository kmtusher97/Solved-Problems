/*  ~*BISMILLAHIR RAHMARNIR RAHIM *~  */
#include <bits/stdc++.h>
using namespace std;

#define MX_N 202
int n, w[MX_N], b[MX_N];

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", w+i);
    int res = 0;
    for(int i=0; i<n; i++) {
      scanf("%d", b+i);
      res ^= abs(b[i]-w[i]-1);
    }
    printf("Case %d: ", ++caseno);
    if( res!=0 ) printf("white wins\n");
    else printf("black wins\n");
  }
  return 0;
}
