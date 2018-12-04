/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;
#define MX_N 105
int n;
bool prim[MX_N], vis[20];

void dfs( int idx, int last, int a[] ) {
  if( idx == n ) {
    if( prim[a[0] + a[n - 1]] ) return;
    printf("%d", a[0]);
    for(int i = 1; i < n; i++)
      printf(" %d", a[i]);

    printf("\n");
    return;
  }

  for(int i = 1; i < n; i++)
    if( !vis[i] && !prim[last + i + 1] ) {
      vis[i] = 1, a[idx] = i + 1;
      dfs( idx + 1, i + 1, a );
      vis[i] = 0;
    }
}

int main() {
  prim[0] = prim[1] = 1;
  for(int i = 2; i < MX_N; i++)
    if( !prim[i] )
      for(int j = i + i; j < MX_N; j += i)
        prim[j] = 1;

  int caseno = 0;
  while( ~scanf("%d", &n) ) {
    if( caseno ) printf("\n");
    memset(vis, 0, sizeof vis);
    printf("Case %d:\n", ++caseno);
    int a[20];
    vis[0] = a[0] = 1;
    dfs( 1, 1, a );
  }
  return 0;
}
