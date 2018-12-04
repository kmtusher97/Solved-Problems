#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long intl;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 123456;
int tree[3*MX][2];
char s[MX];

void build( int node, int lo, int hi ) {
  if( lo==hi ) {
    s[lo]=='(' ? (tree[node][0]=1, tree[node][1]=0) : (tree[node][0]=0, tree[node][1]=1);
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  build( lft, lo, mid );
  build( rgt, mid+1, hi );
  ///merge
  int rmv = min(tree[lft][0], tree[rgt][1]);
  tree[node][0] = tree[rgt][0] + tree[lft][0] - rmv;
  tree[node][1] = tree[lft][1] + tree[rgt][1] - rmv;
}

void update( int node, int lo, int hi, int pos ) {
  if( lo==hi ) {
    tree[node][0] = !tree[node][0];
    tree[node][1] = !tree[node][1];
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( pos<=mid ) update( lft, lo, mid, pos );
  else update( rgt, mid+1, hi, pos );
  ///merge
  int rmv = min(tree[lft][0], tree[rgt][1]);
  tree[node][0] = tree[rgt][0] + tree[lft][0] - rmv;
  tree[node][1] = tree[lft][1] + tree[rgt][1] - rmv;
}

int main() {
  int n, Q, caseno = 0;
  while( ~scanf("%d", &n) ) {
    scanf("%s %d", s, &Q);
    build( 1, 0, n-1 );
    printf("Test %d:\n", ++caseno);
    while( Q-- ) {
      int p;
      scanf("%d", &p);
      if( !p ) {
        ( !tree[1][0] && !tree[1][1] ) ? printf("YES\n") : printf("NO\n");
      }
      else {
        update( 1, 0, n-1, p-1 );
      }
    }
  }
  return 0;
}
