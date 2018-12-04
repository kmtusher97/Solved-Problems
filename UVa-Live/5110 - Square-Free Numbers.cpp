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

const int MX = 1000056;
bool mark[MX+100];
vector<ll> sqnm;
vi divs;

void precal() {
  for(ll i=2; i*i<=MX; i++) {
    sqnm.pb(i*i);
  }
  for(int i=0, sz=sqnm.size(); i<sz; i++) {
    for(ll j=1LL; j*sqnm[i]<=(ll)MX; j++) {
      mark[(ll)(j*sqnm[i])] = true;
    }
  }
}

int fndmx( int x ) {
  divs.clear();
  for(int i=2; i<=sqrt(x)+2; i++) {
    if( x%i == 0 ) {
      divs.pb(i);
      if( i != x/i ) divs.pb(x/i);
    }
  }
  int mx = 0;
  for(int i=0; i<divs.size(); i++) {
    if( !mark[divs[i]] ) mx = max(mx, divs[i]);
  }
  return mx;
}


int main() {
  precal();

  int cases, n;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    int cnt = 0, lim = sqrt(n)+10;
    if( !mark[n] ) {
      printf("1\n");
      continue;
    }
    while( true ) {
      int x = fndmx(n);
      cnt++;
      if( !mark[n/x] ) {
        cnt++; break;
      }
      else n /= x;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
