/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
#define MX_N 10050
#define inf 0x3f3f3f3f

struct Suffix_Automata {
        struct Node {
            int len, link;
            int child[26];
            Node() { }
            void Reset() { memset(child, 0, sizeof child); }
        };

        Node DAG[MX_N];
        int sz, last, root;
        int match[MX_N], LCS[MX_N];

        void init() {
          sz = last = root = 0;
          DAG[root].len = 0;
          DAG[root].link = -1;
          DAG[root].Reset();
          memset(LCS, inf, sizeof LCS);
        }

        void add( int c ) {
          int cur = ++sz, p = last;
          DAG[cur].len = DAG[last].len + 1;
          DAG[cur].Reset();
          for(; ~p && !DAG[p].child[c]; p = DAG[p].link)
            DAG[p].child[c] = cur;

          if( !(p + 1) )
            DAG[cur].link = root;
          else {
            int q = DAG[p].child[c];
            if( DAG[q].len == DAG[p].len + 1 )
              DAG[cur].link = q;
            else {
              int clone = ++sz;
              DAG[clone].len = DAG[p].len + 1;
              DAG[clone].link = DAG[q].link;
              memcpy(DAG[clone].child, DAG[q].child, sizeof DAG[q].child);

              for(; ~p && DAG[p].child[c] == q; p = DAG[p].link)
                DAG[p].child[c] = clone;

              DAG[q].link = DAG[cur].link = clone;
            }
          }
          last = cur;
        }

        void findMatch( char P[] ) {
          memset(match, 0, sizeof match);
          int p = root, L = 0;
          for(int i = 0; P[i]; i++) {
            int c = P[i] - 'a';
            while( p && !DAG[p].child[c] )
              p = DAG[p].link, L = DAG[p].len;

            if( DAG[p].child[c] )
              p = DAG[p].child[c], L++;

            match[p] = max(match[p], L);
          }
          for(int i = sz; i > 0; i--)
            match[i] = max(match[i], match[DAG[i].link]);
          for(int i = 0; i <= sz; i++)
            LCS[i] = min(LCS[i], match[i]);
        }

        int longestCommonSubstr() {
          int ret = 0;
          for(int i = 0; i <= sz; i++)
            ret = max(ret, LCS[i]);
          return ret;
        }
};

Suffix_Automata SA;
char s[MX_N];

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    SA.init();
    scanf("%s", s);
    for(int i = 0; s[i]; i++)
      SA.add( s[i] - 'a' );

    for(int i = 1; i <= 2; i++) {
      scanf("%s", s);
      SA.findMatch( s );
    }
    int res = SA.longestCommonSubstr();
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
