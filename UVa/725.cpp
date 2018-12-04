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

const int MX = 98765;
bool mark[MX+50];
vi a;
vii ans;

bool duplicates( int x ) {
  int frq[10];
  for(int i=0; i<10; i++) frq[i] = 0;
  while(x) {
    frq[x%10]++;
    if(frq[x%10] > 1) return false;
    x /= 10;
  }
  return true;
}

bool similar( int x, int y ) {
  int frq[10];
  for(int i=0; i<10; i++) frq[i] = 0;
  if( x/10000 == 0 ) ++frq[0];
  if( y/10000 == 0 ) ++frq[0];
  while(x) {
    ++frq[x%10], x /= 10;
  }
  while(y) {
    ++frq[y%10], y /= 10;
  }
  for(int i=0; i<10; i++) {
    if( frq[i] > 1 ) return true;
  }
  return false;
}

void precal() {
  for(int i=1234; i<=MX; i++) {
    if( !duplicates( i ) ) {
      a.pb(i);
    }
  }
}

int main() {
  precal();
  int n, caseno = 0;
  while( scanf("%d", &n) && n ) {
    ans.clear();
    memset( mark, false, sizeof mark );
    for(int i=1234; i<=MX; i++) {
      if( !mark[i] && i*n <= MX && !mark[i*n] && !similar( i, i*n ) ) {
        ans.pb( mk_pr(i*n, i) );
      }
    }
    if( 0 < caseno++ ) printf("\n");
    if( !ans.size() ) {
      printf("There are no solutions for %d.\n", n);
    }
    else {
      for(int i=0, sz=ans.size(); i<sz; i++) {
        ( ans[i].first/10000 == 0 ) ? printf("0%d / ", ans[i].first) : printf("%d / ", ans[i].first);
        ( ans[i].second/10000 == 0 ) ? printf("0%d = %d\n", ans[i].second, n) : printf("%d = %d\n", ans[i].second, n);
      }
    }
  }
  return 0;
}
