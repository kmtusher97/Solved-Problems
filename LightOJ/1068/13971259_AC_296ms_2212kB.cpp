/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

#define MX_K 10002

char a[12], b[12];
int n, L, R, K, nm[12], ff[10][2][82][82];

void tostring( int x ) {
  n = 0;
  memset(nm, 0, sizeof nm);
  while( x>0 ) {
    nm[n++] = x%10, x /= 10;
  }
}

int dfs( int pos, int chk, int rmndr1, int rmndr2 ) {
  if( pos==n ) {
    return ( !rmndr1 && !rmndr2 ) ? 1 : 0;
  }
  int& ret = ff[pos][chk][rmndr1][rmndr2];
  if( ~ret ) return ret;

  ret = 0;
  if( chk ) {
    for(int dgt=0; dgt<=9; dgt++) {
      ret += dfs( pos+1, 1, (rmndr1*10+dgt)%K, (rmndr2+dgt)%K );
    }
  }
  else {
    for(int dgt=0; dgt<nm[n-pos-1]; dgt++) {
      ret += dfs( pos+1, 1, (rmndr1*10+dgt)%K, (rmndr2+dgt)%K );
    }
    ret += dfs( pos+1, 0, (rmndr1*10+nm[n-pos-1])%K, (rmndr2+nm[n-pos-1])%K );
  }
  return ff[pos][chk][rmndr1][rmndr2] = ret;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d %d", &L, &R, &K);
    printf("Case %d: ", ++caseno);
    if( K>81 )
    {
      printf("0\n");
      continue;
    }
    tostring( R );
    memset(ff, -1, sizeof ff);
    int res = dfs( 0, 0, 0, 0 );
    tostring( L-1 );
    memset(ff, -1, sizeof ff);
    res -= dfs( 0, 0, 0, 0 );
    printf("%d\n", res);
  }
  return 0;
}
