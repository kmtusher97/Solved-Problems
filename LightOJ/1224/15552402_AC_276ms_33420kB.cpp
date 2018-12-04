/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;
#define MX_N 812345
struct Trie {
    struct Node {
      intl frq, len;
      int next[6];
      Node() { }
      void clr() {
        frq = len = 0;
        memset(next, -1, sizeof next);
      }
    };
    int sz;
    intl res;
    Node trie[MX_N];
 
    void init() {
      sz = res = 0;
      trie[0].clr();
    }
 
    int ID( char c ) {
      if( c == 'A' ) return 1;
      if( c == 'T' ) return 2;
      if( c == 'G' ) return 3;
      if( c == 'C' ) return 4;
    }
 
    void Insert( char s[] ) {
      int cur = 0;
      for(int i = 0, ln = strlen(s); i < ln; i++) {
        int ltr = ID( s[i] );
        if( !(trie[cur].next[ltr] + 1) ) {
          trie[cur].next[ltr] = ++sz;
          trie[sz].clr();
          trie[sz].len = trie[cur].len + 1;
        }
        int pre = cur;
        cur = trie[cur].next[ltr];
        trie[cur].frq++;
        res = max(res, trie[cur].len * trie[cur].frq);
      }
    }
};
 
int n;
char dna[100];
Trie T;
 
int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    T.init();
    for(int i = 0; i < n; i++) {
      scanf("%s", dna);
      T.Insert( dna );
    }
    printf("Case %d: %lld\n", ++caseno, T.res);
  }
  return 0;
}