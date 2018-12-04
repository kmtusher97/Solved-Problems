#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 1123456;
char D[20][20];
ll dp[(1<<8)+100];

ll bit_mask_DP( int *a, int n ) {
  memset(dp, 0LL, sizeof dp);
  dp[0] = 1LL;
  for(int mask=1; mask<( 1<<n ); mask++)
    for(int i=0; i<n; i++)
      if( mask&(1<<i) ) {
        bool flg = true;
        for(int j=0; j<n; j++) if( mask&(1<<j) ) {
          if( D[a[i]][a[j]] == 'Y' ) {
            flg = false; break;
          }
        }
        if( flg ) dp[mask] += dp[mask^(1<<i)];
      }

  return dp[(1<<n)-1];
}

int main() {
  int cases, N;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &N);
    for(int i=0; i<(2*N); i++) {
      scanf("%s", &D[i]);
    }

    ll ans = 0;
    for(int i=0; i<( 1<<(2*N) ); i++) {
      if( __builtin_popcount(i) != N ) continue;
      int g1[N+5], g2[N+5], k1 = 0, k2 = 0;
      for(int j=0; j<2*N; j++) {
        ( i&(1<<j) ) ? g1[k1++] = j : g2[k2++] = j;
      }
      bool flg = true;
      for(int j=0; j<N; j++)
        for(int k=0; k<N; k++)
          if( D[g1[j]][g2[k]] == 'Y' || D[g2[k]][g1[j]] == 'Y' ) {
            flg = false;
            break;
          }
      if( !flg ) continue;
      ll p = bit_mask_DP( g1, N );
      ll q = bit_mask_DP( g2, N );
      ans += (p*q);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
