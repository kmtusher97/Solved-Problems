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

const int MX = 1123456;
bool mark[MX];

int main() {
  int cases, n, m;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &m);
    while( m-- ) {
      int x, y;
      scanf("%d %d", &x, &y);
      mark[y] = true;
    }

    if( !mark[n] ) {
      printf("2 %d\n", n);
      continue;
    }
    bool flg = false;
    for(int i=n; i>0; i--) {
      if( !mark[i] ) {
        printf("1\n");
        flg = true; break;
      }
    }
    if( !flg ) printf("-1\n");
  }
  return 0;
}
