/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;
#define MX_N 1123456
int n, N, C[4], ff[MX_N];

int main() {
  scanf("%d %d %d", C+2, C+3, &n), C[1] = 1;
  for(int i=0; i<n; i++) {
    scanf("%d", &N);
    memset(ff, 0, sizeof ff);
    ff[1] = ff[C[2]] = ff[C[3]] = 1;
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=3; j++) {
        ff[i] |= ( i>=C[j] && ff[i-C[j]]%2==0 );
      }
    }
    ( ff[N]&1 ) ? printf("A") : printf("B");
  }
  printf("\n");
  return 0;
}
