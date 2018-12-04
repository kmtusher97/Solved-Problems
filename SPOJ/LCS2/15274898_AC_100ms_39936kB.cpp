/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
#define MX_N 200050

struct Suffix_Automata {
        struct State {
            int len, link;
            int next[26];

            State() { }
            void clr() { memset(next, 0, sizeof next); }
        };

        State st[MX_N];
        int sz, last, maxMatch[MX_N], LCS[MX_N];

        void init() {
          sz = last = 0;
          st[0].clr();
          st[0].len = 0;
          st[0].link = -1;
          for(int i = 0; i < MX_N; i++)
            LCS[i] = INT_MAX;
        }

        int ID( char c ) { return c - 'a'; }

        void Insert( char ch ) {
          int now = ++sz, p, c = ID( ch );
          st[now].len = st[last].len + 1;
          st[now].clr();
          for(p = last; ~p && !st[p].next[c]; p = st[p].link)
            st[p].next[c] = now;

          if( !(p + 1) )
            st[now].link = 0;
          else {
            int q = st[p].next[c];
            if( st[p].len + 1 == st[q].len )
              st[now].link = q;
            else {
              int clone = ++sz;
              st[clone].len = st[p].len + 1;
              st[clone].link = st[q].link;
              memcpy(st[clone].next, st[q].next, sizeof st[q].next);

              for(; ~p && st[p].next[c] == q; p = st[p].link)
                st[p].next[c] = clone;

              st[q].link = st[now].link = clone;
            }
          }
          last = now;
        }

        void findLCS( char p[] ) {
          memset(maxMatch, 0, sizeof maxMatch);
          int now = 0, L = 0;
          for(int i = 0, c; p[i]; i++) {
            c = ID( p[i] );
            while( now && !st[now].next[c] ) {
              now = st[now].link;
              L = st[now].len;
            }
            if( st[now].next[c] )
              now = st[now].next[c], ++L;
            maxMatch[now] = max(maxMatch[now], L);
          }

          for(int i = sz; i > 0; i--)
            maxMatch[i] = max(maxMatch[i], maxMatch[st[i].link]);
          for(int i = 0; i <= sz; i++)
            LCS[i] = min(LCS[i], maxMatch[i]);
        }

        int longestCommonSubstr() {
          int ret = 0;
          for(int i = 0; i <= sz; i++)
            ret = max(ret, LCS[i]);
          return ret;
        }
};

Suffix_Automata SA;
char S[MX_N];

int main() {
  SA.init();
  scanf("%s", S);
  for(int i = 0; S[i]; i++)
    SA.Insert( S[i] );
  while( ~scanf("%s", S) ) {
    SA.findLCS( S );
  }
  int res = SA.longestCommonSubstr();
  printf("%d\n", res);

  return 0;
}
