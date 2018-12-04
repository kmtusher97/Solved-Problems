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
bool prime[MX], mark[MX];

void seive() {
  prime[0] = prime[1] = true;
  for(ll i=2; i<=sqrt(MX); i++)
    if( !prime[i] ) {
      for(ll j=i*2; j<MX; j+=i) prime[j] = true;
    }

  for(int i=0; i<11234; i++) {
    int cnt = 0;
    for(int j=1; j<=sqrt(i); j++) {
      if( i%j == 0 ) {
        cnt++;
        if( j != i/j ) cnt++;
      }
    }
    if( !prime[cnt] ) mark[i] = true;
  }
}

int main() {
  seive();
  int cases, a, b;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &a, &b);
    vi v;
    for(int i=a; i<=b; i++) {
      if( mark[i] ) {
        v.pb(i);
      }
    }
    if( !v.size() ) {
      printf("-1\n");
      continue;
    }
    printf("%d", v[0]);
    for(int i=1; i<v.size(); i++) {
      printf(" %d", v[i]);
    }
    printf("\n");
  }
  return 0;
}
