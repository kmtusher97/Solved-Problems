/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/
#include <bits/stdc++.h>

using namespace std;

#define sc scanf
#define pf printf
#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long intl;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;
typedef queue<pii> qii;

#define read freopen("INPUT.txt", "r", stdin)
#define write freopen("OUTPUT.txt", "w", stdout)
#define FasterIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MX = 702;
pii pp[MX];
map<pii, int> mp;

int main() {
  ///read, write;
  ///FasterIO;
  int cases, caseno = 0, n;
  sc("%d", &cases);
  while( cases-- ) {
    sc("%d", &n);
    for(int i=0; i<n; i++) {
      sc("%d %d", &pp[i].first, &pp[i].second);
    }

    int cnt = 0, mx = 1;
    for(int i=1; i<n; i++) {
      mp.clear();
      for(int j=0; j<n; j++) if( i!=j ) {
        pii p( pp[j].first-pp[i].first, pp[j].second-pp[i].second );
        int g = __gcd(abs(p.first), abs(p.second));
        if( g!=0 ) {
          p.first /= g;
          p.second /= g;
        }
        if( mp.find(p)==mp.end() ) {
          mp[p] = 2;
          mx = max(mx, mp[p]);
        }
        else {
          mp[p]++;
          mx = max(mx, mp[p]);
        }
      }
    }

    pf("Case %d: %d\n", ++caseno, mx);
  }

  return 0;
}
