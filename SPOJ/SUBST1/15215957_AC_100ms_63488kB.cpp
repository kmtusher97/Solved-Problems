/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;

struct suffix_automata {
        static const int MX_N = 100005;
        struct state {
          int len, link;
          int next[58];

          state() {
            len = 0, link = -1;
            memset(next, -1, sizeof next);
          }
          void init() {
            len = 0, link = -1;
            memset(next, 0, sizeof next);
          }
        };
        state tree[MX_N * 2];
        int sz, last;
        intl distinct[MX_N];

        void initialize() {
          sz = last = 0;
          tree[0].init();
          memset(distinct, 0, sizeof distinct);
        }

        int ID( char c ) { return c - 'A'; }

        void Insert( char c ) {
          int now = ++sz, p;
          tree[now].init();
          tree[now].len = tree[last].len + 1;

          for(p = last; ~p && !tree[p].next[ID(c)]; p = tree[p].link)
            tree[p].next[ID(c)] = now;

          if( !(p + 1) ) {
            tree[now].link = 0;
          }
          else {
            int q = tree[p].next[ID(c)];
            if( tree[p].len + 1 == tree[q].len ) {
              tree[now].link = q;
            }
            else {
              int clone = ++sz;
              tree[clone].init();
              tree[clone].len = tree[p].len + 1;
              tree[clone].link = tree[q].link;
              for(int i = 0; i < 58; i++)
                tree[clone].next[i] = tree[q].next[i];

              for(; ~p && tree[p].next[ID(c)] == q; p = tree[p].link)
                tree[p].next[ID(c)] = clone;

              tree[q].link = tree[now].link = clone;
            }
          }
          last = now;
        }

        intl dfs_distinct( int u ) {
          intl& ret = distinct[u];
          if( ret ) return ret;

          ret = 1;
          for(int i = 0; i < 58; i++)
            if( tree[u].next[i] )
              ret += dfs_distinct( tree[u].next[i] );

          return distinct[u] = ret;
        }
} SA;

const int MX = 50005;
int n;
char T[MX];

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%s", T);
    n = strlen(T);
    SA.initialize();

    for(int i = 0; i < n; i++)
      SA.Insert( T[i] );

    intl res = SA.dfs_distinct( 0 );
    printf("%lld\n", res - 1);
  }
  return 0;
}
