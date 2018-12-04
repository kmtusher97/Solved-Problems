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

const int MX = 3123456;
int n, tri_node, trie[MX][2];
ll a[MX];

struct mybitset {
  bool bitptrn[35];

  void set_vlu( ll x ) {
    for(int i=0; i<35; i++) {
      x%2LL ? bitptrn[i] = 1 : bitptrn[i] = 0;
      x /= 2;
    }
  }
};

void insrt( ll x ) {
  mybitset bt;
  bt.set_vlu(x); /// bit pattern of x

  int cur_node = 0;
  for(int i=31; i>=0; i--) {
    if( trie[cur_node][bt.bitptrn[i]] == -1 ) {
      trie[cur_node][bt.bitptrn[i]] = ++tri_node;
      cur_node = tri_node;
    }
    else {
      cur_node = trie[cur_node][bt.bitptrn[i]];
    }
  }
}

ll srch( ll x ) {
  mybitset bt;
  bt.set_vlu(x); /// bit pattern of x

  int cur_node = 0;
  ll v = 0;
  for(int i=31; i>=0; i--) {
    if( bt.bitptrn[i] == 1 ) {
      if( trie[cur_node][0] != -1 ) {
        cur_node = trie[cur_node][0];
        v += (1LL<<i);
      }
      else {
        cur_node = trie[cur_node][1];
      }
    }
    else {
      if( trie[cur_node][1] != -1 ) {
        cur_node = trie[cur_node][1];
        v += (1LL<<i);
      }
      else {
        cur_node = trie[cur_node][0];
      }
    }
  }
  return v;
}

ll solution() {
  memset(trie, -1, sizeof trie);
  tri_node = 0;
  ll mx = INT_MIN, sm = 0LL;
  insrt(0LL);
  for(int i=0; i<n; i++) {
    sm ^= a[i];
    mx = max(mx, srch(sm));
    insrt(sm);
  }
  return mx;
}

int main() {
  int cases;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
      scanf("%lld", a+i);
    }
    printf("%lld\n", solution());
  }
  return 0;
}
