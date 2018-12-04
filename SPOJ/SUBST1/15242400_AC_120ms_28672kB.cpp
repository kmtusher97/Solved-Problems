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
          map<char, int> next;
        };
        State st[MX_N];
        int sz, last;

        intl distinct[MX_N];

        void init() {
          sz = last = 0;
          st[0].len = 0;
          st[0].link = -1;
          st[0].next.clear();
          memset(distinct, 0, sizeof distinct);
        }

        void add_State( char c ) {
          int now = ++sz, p;
          st[now].len = st[last].len + 1;
          st[now].next.clear();

          for(p = last; ~p && !st[p].next.count(c); p = st[p].link)
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
              st[clone].next = st[q].next;
              st[clone].link = st[q].link;
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
          for(auto it = st[u].next.begin(); it != st[u].next.end(); it++)
            ret += dfs_distict( it -> S );

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
