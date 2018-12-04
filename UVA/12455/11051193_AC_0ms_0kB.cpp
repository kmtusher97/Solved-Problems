#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

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
