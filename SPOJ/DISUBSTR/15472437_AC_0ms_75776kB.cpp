/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long intl;
#define MX_N 100050

struct Suffix_Automata {
        struct State {
          int len, link;
          int next[150];
          State() { }
          void clr() { memset(next, 0, sizeof next); }
        };
        State st[MX_N];
        int sz, last;

        intl distinct[MX_N];

        void init() {
          sz = last = 0;
          st[0].len = 0;
          st[0].link = -1;
          st[0].clr();
          memset(distinct, 0, sizeof distinct);
        }

        void add_State( char c ) {
          int now = ++sz, p;
          st[now].len = st[last].len + 1;
          st[now].clr();

          for(p = last; ~p && !st[p].next[c]; p = st[p].link)
            st[p].next[c] = now;

          if( !(p + 1) )
            st[now].link = 0;
          else {
            int q = st[p].next[c];
            if( st[q].len == st[p].len + 1 )
              st[now].link = q;
            else {
              int clone = ++sz;
              st[clone].len = st[p].len + 1;
              st[clone].link = st[q].link;
              for(int i = 0; i < 150; i++)
                st[clone].next[i] = st[q].next[i];

              for(; ~p && st[p].next[c] == q; p = st[p].link)
                st[p].next[c] = clone;

              st[q].link = st[now].link = clone;
            }
          }
          last = now;
        }

        intl dfs_distict( int u ) {
          intl& ret = distinct[u];
          if( ret ) return ret;

          ret = 1;
          for(int v = 0; v < 150; v++)
            if( st[u].next[v] )
              ret += dfs_distict( st[u].next[v] );

          return distinct[u] = ret;
        }
} SA;

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin >> cases;
  while( cases-- ) {
    SA.init();
    string s;
    cin >> s;
    for(auto i : s)
      SA.add_State( i );
    cout << SA.dfs_distict( 0 ) - 1 << endl;
  }
  return 0;
}
