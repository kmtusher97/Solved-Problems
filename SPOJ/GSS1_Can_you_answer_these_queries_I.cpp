#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define pbk pop_back
#define mk_pr make_pair
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;
 
const int MX = 112345;
int a[MX];
 
class node {
    public:
        int sm, mx_sm, prfx_sm, sufx_sm;
        void reset( int x ) {
            sm = mx_sm = prfx_sm = sufx_sm = x;
        }
} tree[3*MX];
 
node marge( node p, node q ) {
    node aa;
    aa.sm = p.sm + q.sm;
    aa.mx_sm = max( max(p.mx_sm, q.mx_sm), p.sufx_sm + q.prfx_sm );
    aa.prfx_sm = max( p.prfx_sm, p.sm + q.prfx_sm );
    aa.sufx_sm = max( q.sufx_sm, q.sm + p.sufx_sm );
    return aa;
}
 
void build( int nd, int lo, int hi ) {
    if( lo == hi ) {
        tree[nd].reset( a[lo] );
        return;
    }
    int mid = lo+(hi-lo)/2;
    build( nd<<1, lo, mid );
    build( nd<<1|1, mid+1, hi );
    tree[nd] = marge( tree[nd<<1], tree[nd<<1|1] );
}
 
node query( int nd, int lo, int hi, int l, int r ) {
    if( lo >= l && hi <= r ) return tree[nd];
    int mid = lo+(hi-lo)/2;
    if( r <= mid ) return query( nd<<1, lo, mid, l, r );
    else if( l > mid ) return query( nd<<1|1, mid+1, hi, l, r );
    else return marge( query( nd<<1, lo, mid, l, r ), query( nd<<1|1, mid+1, hi, l, r ) );
}
 
int main() {
    int n, Q;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", a+i);
    }
    build( 1, 0, n-1 );
    scanf("%d", &Q);
    while( Q-- ) {
        int l, r;
        scanf("%d %d", &l, &r);
        node ans = query( 1, 0, n-1, l-1, r-1 );
        printf("%d\n", ans.mx_sm);
    }
    return 0;
}
