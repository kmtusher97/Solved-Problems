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

const int MX = 10000067;
bool vis[10];
int n, m, cnt, a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
vector<piii> cndsn;

bool is_valid( int *tmp ) {
  for(int i=0, sz=cndsn.size(), p1, p2; i<sz; i++) {
    for(int j=0; j<n; j++) {
      if( tmp[j] == cndsn[i].first.first ) p1 = j;
      if( tmp[j] == cndsn[i].first.second ) p2 = j;
    }
    if( cndsn[i].second < 0 && abs(p1-p2) < -cndsn[i].second ) {
      return false;
    }
    if( cndsn[i].second >= 0 && abs(p1-p2) > cndsn[i].second ) {
      return false;
    }
  }
  return true;
}

void permutation( int *tmp, int pos ) {
  if( pos == n ) {
    if( is_valid( tmp ) ) cnt++;
    return;
  }
  for(int i=0; i<n; i++) {
    if( !vis[i] ) {
      tmp[pos] = a[i], vis[i] = true;
      permutation( tmp, pos+1 );
      vis[i] = false;
    }
  }
}

int main() {
  while( scanf("%d %d", &n, &m) == 2 ) {
    if( !n && !m ) break;
    cndsn.clear();
    while( m-- ) {
      int a1, b1, c1;
      scanf("%d %d %d", &a1, &b1, &c1);
      cndsn.pb( mk_pr( mk_pr(a1, b1), c1 ) );
    }
    cnt = 0;
    int t[10];
    permutation( t, 0 );
    printf("%d\n", cnt);
  }
  return 0;
}
