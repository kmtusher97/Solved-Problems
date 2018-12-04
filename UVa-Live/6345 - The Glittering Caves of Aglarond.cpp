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

const int MX = 112345;

int main() {
  int cases, n, m, k;
  scanf("%d", &cases);
  while( cases-- ) {
    priority_queue<pii> pq;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<n; i++) {
      char s[m+10];
      scanf("%s", s);
      int cnt = 0;
      for(int j=0; j<m; j++) {
        if( s[j] == '.' ) cnt++;
      }
      pq.push( mk_pr(cnt, m-cnt) );
    }

    while( k ) {
      pii tmp = pq.top(); pq.pop();
      pq.push( mk_pr( tmp.second, tmp.first ) );
      k--;
    }

    int sm = 0, mn = INT_MAX;
    while( !pq.empty() ) {
      sm += pq.top().second;
      mn = min(mn, pq.top().second);
      pq.pop();
    }

    if( k&1 ) {
      sm -= mn;
      sm += (m-mn);
    }

    printf("%d\n", sm);
  }
  return 0;
}
