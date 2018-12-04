/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
#define MX_N 512345

struct AhoChorasick {
        struct Node {
            int next[52];
            Node() { memset(next, -1, sizeof next); }
        };
        int sz, len, root;
        Node tree[MX_N];
        int suffix[MX_N], path[MX_N];
        int ff[MX_N], ed[MX_N];

        void init() {
          sz = len = root = 0;
          tree[root] = Node();
          for(int i = 0; i < MX_N; i++)
            ff[i] = suffix[i] = 0;
        }

        int ID( char c ) {
          return ( c >= 'A' && c <= 'Z' ) ? c - 65 : c - 71;
        }

        void Insert( char p[], int id ) {
          int now = root;
          for(int i = 0; p[i]; i++) {
            int ltr = ID( p[i] );
            if( !(tree[now].next[ltr] + 1) )
              tree[now].next[ltr] = ++sz, tree[sz] = Node();
            now = tree[now].next[ltr];
          }
          ed[id] = now;
        }

        void reverseLink() {
          queue<int> Q;
          for(int i = 0; i < 52; i++) {
            if( ~tree[root].next[i] )
              Q.push(tree[root].next[i]);
            else
              tree[root].next[i] = root;
          }

          while( !Q.empty() ) {
            int u = Q.front(); Q.pop();
            for(int i = 0; i < 52; i++) {
              int v = tree[u].next[i];
              if( !(v + 1) ) {
                tree[u].next[i] = tree[suffix[u]].next[i];
                continue;
              }
              suffix[v] = tree[suffix[u]].next[i];
              Q.push(v), path[len++] = v;
            }
          }
        }

        void Search( char t[] ) {
          int now = root;
          for(int i = 0; t[i]; i++) {
            int ltr = ID( t[i] );
             now = tree[now].next[ltr];
             ff[now]++;
          }
          for(int i = len - 1; i >= 0; i--)
            ff[suffix[path[i]]] += ff[path[i]];
        }
};

char T[100005], P[1004];
AhoChorasick aho;

int main() {
  int cases;
  scanf("%d", &cases);
  while( cases-- ) {
    int Q;
    scanf("%s %d", T, &Q);
    aho.init();
    for(int i = 1; i <= Q; i++) {
      scanf("%s", P);
      aho.Insert( P, i );
    }
    aho.reverseLink();
    aho.Search( T );
    for(int i = 1; i <= Q; i++)
      (aho.ff[aho.ed[i]]) ? printf("y\n") : printf("n\n");
  }
  return 0;
}
