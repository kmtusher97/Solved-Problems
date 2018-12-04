// segment tree
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 1e5;
const int inf = 1e9;
int ar[MX+100], tree[MX*3];

void build( int node, int lo, int hi ) {
        if( lo == hi ) {
                tree[node] = ar[lo];
                return;
        }

        int mid = lo + (hi-lo)/2;
        build( node*2, lo, mid );
        build( node*2+1, mid+1, hi );
        tree[node] = min( tree[node*2], tree[node*2+1] );
}

int query( int node, int i, int j, int lo, int hi ) {
        if( i > hi || j < lo ) return inf;
        if( lo >= i && hi <= j ) return tree[node];
        int mid = lo + (hi-lo)/2;
        return min( query( node*2, i, j, lo, mid ), query( node*2+1, i, j, mid+1, hi ) );
}

int main() {
        int cases, caseno = 0, n, q;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%d %d", &n, &q);
                for(int i=0; i<n; i++) scanf("%d", ar+i);
                build( 1, 0, n-1 );
                printf("Case %d:\n", ++caseno);
                while( q-- ) {
                        int i, j;
                        scanf("%d %d", &i, &j);
                        printf("%d\n", query( 1, i-1, j-1, 0, n-1 ));
                }
        }

        return 0;
}
