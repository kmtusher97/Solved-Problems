/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;

#define MX_N 200050
string T;


struct suffix_automata {
        struct state {
          int len, link, next[60];
        };
        state tree[MX_N];
        int sz, last;

        intl distinct[MX_N];

        void initialize() {
          sz = last = 0;
          tree[0].len = 0, tree[0].link = -1;
          memset(tree[0].next, -1, sizeof tree[0].next);
          memset(distinct, 0, sizeof distinct);
        }

        void Insert( int c ) {
          int now = ++sz, p;
          tree[now].len = tree[last].len + 1;
          memset(tree[now].next, -1, sizeof tree[now].next);

          for(p = last; ~p && !(tree[p].next[c] + 1); p = tree[p].link)
            tree[p].next[c] = now;

          if( !(p + 1) ) {
            tree[now].link = 0;
          }
          else {
            int q = tree[p].next[c];
            if( tree[p].len + 1 == tree[q].len ) {
              tree[now].link = q;
            }
            else {
              int clone = ++sz;
              tree[clone].len = tree[p].len + 1;
              tree[clone].link = tree[q].link;
              for(int j = 0; j < 60; j++)
                tree[clone].next[j] = tree[q].next[j];

              for(; ~p && tree[p].next[c] == q; p = tree[p].link)
                tree[p].next[c] = clone;

              tree[q].link = tree[now].link = clone;
            }
          }
          last = now;
        }

        intl dfs_distinct( int u ) {
          intl ret = 1LL;
          if( distinct[u] )
            return distinct[u];

          for(int i = 0; i < 60; i++)
            if( ~tree[u].next[i] )
              ret += dfs_distinct( tree[u].next[i] );

          return distinct[u] = ret;
        }
} SA;


int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin >> cases;
  while( cases-- ) {
    SA.initialize();
    cin >> T;
    for(int i = 0; T[i]; i++)
      SA.Insert( T[i] - 'A' );

    intl res = SA.dfs_distinct( 0 );
    cout << res - 1 << endl;
  }
  return 0;
}
