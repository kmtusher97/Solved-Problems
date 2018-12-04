#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

const int MX = 1123456;
int n, trie_node, trie[MX][2];

class mybitset {
public:
  bool binry[34];
  void make_binary( int x ) {
    for(int i=0; i<34; i++) {
      x&1 ? binry[i] = 1 : binry[i] = 0;
      x /= 2;
    }
  }
};

void insrt( int x ) {
  mybitset bt;
  bt.make_binary(x);

  int crnt_node = 0;
  for(int i=30; i>=0; i--) {
    if( trie[crnt_node][bt.binry[i]] == -1 ) {
      trie[crnt_node][bt.binry[i]] = ++trie_node;
      crnt_node = trie_node;
    }
    else {
      crnt_node = trie[crnt_node][bt.binry[i]];
    }
  }
}

int query_max( int x ) {
  mybitset bt;
  bt.make_binary(x);

  int crnt_node = 0, vlu = 0;
  for(int i=30; i>=0; i--) {
    if( trie[crnt_node][!(bt.binry[i])] == -1 ) {
      crnt_node = trie[crnt_node][bt.binry[i]];
    }
    else {
      crnt_node = trie[crnt_node][!(bt.binry[i])];
      vlu += (1<<i);
    }
  }
  return vlu;
}

int query_min( int x ) {
  mybitset bt;
  bt.make_binary(x);

  int crnt_node = 0, vlu = 0;
  for(int i=30; i>=0; i--) {
    if( trie[crnt_node][bt.binry[i]] != -1 ) {
      crnt_node = trie[crnt_node][bt.binry[i]];
    }
    else {
      crnt_node = trie[crnt_node][!(bt.binry[i])];
      vlu += (1<<i);
    }
  }
  return vlu;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    int mn = INT_MAX, mx = INT_MIN, sm = 0;
    memset(trie, -1, sizeof trie);
    trie_node = 0;
    insrt(0);
    for(int i=0, a; i<n; i++) {
      scanf("%d", &a);
      sm ^= a;
      mx = max(mx, query_max(sm));
      mn = min(mn, query_min(sm));
      insrt(sm);
    }
    printf("Case %d: %d %d\n", ++caseno, mx, mn);
  }
}
