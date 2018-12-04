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
int dp[200];
vector<piii> blck;

bool check( piii a, piii b ) {
  if( a.first < b.first && a.second.first < b.second.first ) return true;
  return false;
}

int solution( int n ) {
  sort(blck.begin(), blck.end());
  for(int i=0; i<n; i++) {
    dp[i] = blck[i].second.second;
  }
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if( check( blck[i], blck[j] ) && dp[j] < dp[i]+blck[j].second.second ) {
        dp[j] = dp[i]+blck[j].second.second;
      }
    }
  }
  int mx = 0;
  for(int i=0; i<n; i++) {
    mx = max(mx, dp[i]);
  }
  return mx;
}

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int caseno = 0, n;
  while( cin >> n && n ) {
    blck.clear();
    for(int i=0, l, w, h; i<n; i++) {
      cin >> l >> w >> h;
      blck.pb( mk_pr( l, mk_pr(w, h) ) );
      blck.pb( mk_pr( l, mk_pr(h, w) ) );
      blck.pb( mk_pr( w, mk_pr(l, h) ) );
      blck.pb( mk_pr( w, mk_pr(h, l) ) );
      blck.pb( mk_pr( h, mk_pr(l, w) ) );
      blck.pb( mk_pr( h, mk_pr(w, l) ) );
    }
    int ans = solution( n*6 );
    cout << "Case " << ++caseno << ": maximum height = " << ans << endl;
  }
  return 0;
}
