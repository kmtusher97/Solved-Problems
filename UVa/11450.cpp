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

const int MX = 112345;
bool dp[234][23];

int main() {
  int cases, M, N;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &M, &N);
    vi cst[23];
    for(int i=0, k; i<N; i++) {
      scanf("%d", &k);
      for(int j=0, a; j<k; j++) {
        scanf("%d", &a);
        cst[i].pb(a);
      }
    }
    memset(dp, false, sizeof dp);
    for(int i=0; i<cst[0].size(); i++) {  /// base cases
      if( M >= cst[0][i] ) dp[M-cst[0][i]][0] = true;
    }
    for(int i=1; i<N; i++) {
      for(int j=0; j<=M; j++) {
        if( dp[j][i-1] ) {
          for(int k=0, sz=cst[i].size(); k<sz; k++) {
            if( j >= cst[i][k] ) dp[j-cst[i][k]][i] = true;
          }
        }
      }
    }
    bool flg = false;
    for(int i=0; i<=M; i++) {
      if( dp[i][N-1] ) {
        printf("%d\n", M-i);
        flg = true; break;
      }
    }
    if( flg ) continue;
    printf("no solution\n");
  }
  return 0;
}
