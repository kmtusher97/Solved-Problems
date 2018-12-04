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
char s[MX];

int main() {
  int cases, n, k;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    bool flg = false;
    int sm = 0;
    for(int i=0; i<n; i++) {
      int j = i, cnt = 0;
      for( ; j<n; j++) {
        if( s[j] != s[i] ) break;
        else cnt++;
      }

      if( cnt >= k ) {
        flg = true;
        sm += cnt/k;
        if( cnt%k ) sm++;
      }
      else {
        sm++;
      }
      i = j-1;
    }

    flg ? printf("%d\n", sm) : printf("-1\n");
  }
  return 0;
}
