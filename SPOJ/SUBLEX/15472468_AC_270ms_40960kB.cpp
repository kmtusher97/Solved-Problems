/*  ~*BISMILLAHIR  RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;
#define MX_N 200000

struct SuffixAutomata {
        struct State {
            int len, link;
            int next[26];

            State() { }
            void clr() { memset(next, 0, sizeof next); }
        };

        int sz, last;
        State st[MX_N];

        intl ff[MX_N];
        intl K;
        string kthsubstr;

        void init() {
          sz = last = 0;
          st[0].len = 0;
          st[0].link = -1;
          st[0].clr();
          memset(ff, 0, sizeof ff);
        }

        void Insert( int c ) { /* Insert into the tree */
          int cur = ++sz, p;
          st[cur].clr();
          st[cur].len = st[last].len + 1;
          for(p = last; ~p && !st[p].next[c]; p = st[p].link)
            st[p].next[c] = cur;

          if( !(p + 1) )
            st[cur].link = 0;
          else {
            int q = st[p].next[c];
            if( st[q].len == st[p].len + 1 )
              st[cur].link = q;
            else {
              int clone = ++sz;
              st[clone].len = st[p].len + 1;
              st[clone].link = st[q].link;
              for(int i = 0; i < 26; i++)
                st[clone].next[i] = st[q].next[i];

              for(; ~p && st[p].next[c] == q; p = st[p].link)
                st[p].next[c] = clone;

              st[cur].link = st[q].link = clone;
            }
          }
          last = cur;
        }

        intl dfs( int u ) { /* number of distinct substrings */
          intl& ret = ff[u];
          if( ret ) return ret;

          ret = 1;
          for(int v = 0; v < 26; v++)
            if( st[u].next[v] )
              ret += dfs( st[u].next[v] );

          return ff[u] = ret;
        }

        void dfs_kth( int u ) { /* Lexicographically k th sub string */
          for(int i = 0; i < 26; i++) {
            if( !K || !st[u].next[i] ) continue;
            intl have = ff[st[u].next[i]];
            if( have < K ) K -= have;
            else {
              kthsubstr += (char)(i + 'a');
              K--;
              dfs_kth( st[u].next[i] );
              break;
            }
          }
        }

        void lexicographicallykthSubstr( int k ) {
          K = k;
          kthsubstr = "";
          dfs_kth( 0 );
          for(int i = 0; kthsubstr[i]; i++)
            printf("%c", kthsubstr[i]);
          printf("\n");
        }
};

const int MX = 90005;
char T[MX];
SuffixAutomata SA;

int main() {
  int Q, k;
  scanf("%s", T);
  SA.init();
  for(int i = 0; T[i]; i++)
    SA.Insert( T[i] - 'a' );

  SA.dfs( 0 );
  scanf("%d", &Q);
  while( Q-- ) {
    scanf("%d", &k);
    SA.lexicographicallykthSubstr( k );
  }
  return 0;
}
