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


/*
///complete search, bit mask 
int b[25];
int main() {
  int n, L, cases;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &L, &n);
    for(int i=0; i<n; i++) {
      scanf("%d", b+i);
    }
    bool flg = false;
    for(int i=0, lim=1<<n; i<=lim; i++) {
      int sm = 0, x = i, bt = 0;
      while( x ) {
        if( x&1 ) sm += b[bt];
        x /= 2, bt++;
      }
      if( sm == L ) {
        printf("YES\n");
        flg = true; break;
      }
    }
    if( !flg ) printf("NO\n");
  }
  return 0;
}
*/
