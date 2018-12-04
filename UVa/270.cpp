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

const int MX = 1000;
vii pnt;

double triangle_area( pii a, pii b, pii c ) {
  double x1 = a.first, y1 = a.second, x2 = b.first, y2 = b.second, x3 = c.first, y3 = c.second;
  return 0.5 * ( (x1-x2)*(y2-y3) - (y1-y2)*(x2-x3) );
}

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  string s;
  cin >> cases;
  cin.ignore();
  cin.ignore();
  while( cases-- ) {
    pnt.clear();
    while( getline(cin, s) ) {
      if( s == "" ) break;
      stringstream ss(s);
      int x, y;
      ss >> x, ss >> y;
      pnt.pb( mk_pr(x, y) );
    }
    int mx = 0;
    for(int i=0, cnt, sz=pnt.size(); i<sz; i++) {
      for(int j=i+1; j<sz; j++) {
        cnt = 2;
        for(int k=j+1; k<sz; k++) {
          if( triangle_area( pnt[i], pnt[j], pnt[k] ) == 0 ) cnt++;
        }
        mx = max(mx, cnt);
      }
    }
    cout << mx << endl;
    if( cases ) cout << endl;
  }
  return 0;
}
