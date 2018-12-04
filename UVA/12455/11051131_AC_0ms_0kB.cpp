#include <bits/stdc++.h>
using namespace std;

const int MX = 1123456;
int b[25], dp[1234];

int main() {
  int n, L, cases;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &L, &n);
    for(int i=0; i<n; i++) {
      scanf("%d", b+i);
    }
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i=0; i<n; i++) {
      for(int j=L; j>=0; j--) {
        if( j >= b[i] ) dp[j] |= dp[j-b[i]];
      }
    }
    dp[L] ? printf("YES\n") : printf("NO\n");
  }
  return 0;
}
