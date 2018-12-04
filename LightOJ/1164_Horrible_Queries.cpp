#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MX = 112345;
ll tree[3*MX], lazy[3*MX];
 
void propagate( int node, int lo, int hi ) {
    if( lazy[node] == 0 ) return;
    tree[node] += (hi-lo+1)*lazy[node];
    if( lo != hi ) {
        lazy[node<<1] += lazy[node];
        lazy[node<<1|1] += lazy[node];
    }
    lazy[node] = 0;
}
 
void update_range( int node, int lo, int hi, int l, int r, ll vlu ) {
    propagate( node, lo, hi );
    if( lo > r || hi < l ) return;
    if( lo >= l && hi <= r ) {
        tree[node] += (hi-lo+1)*vlu;
        if( lo != hi ) {
            lazy[node<<1] += vlu;
            lazy[node<<1|1] += vlu;
        }
        return;
    }
    int mid = lo+(hi-lo)/2;
    update_range( node<<1, lo, mid, l, r, vlu );
    update_range( node<<1|1, mid+1, hi, l, r, vlu );
    tree[node] = tree[node<<1] + tree[node<<1|1];
}
 
ll query_range( int node, int lo, int hi, int l, int r ) {
    propagate( node, lo, hi );
    if( lo > r || hi < l ) return 0;
    if( lo >= l && hi <= r ) return tree[node];
    int mid = lo+(hi-lo)/2;
    ll p = query_range( node<<1, lo, mid, l, r );
    ll q = query_range( node<<1|1, mid+1, hi, l, r );
    return p+q;
}
 
int main() {
    int cases, caseno = 0, n, Q;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d", &n, &Q);
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
        printf("Case %d:\n", ++caseno);
        while( Q-- ) {
            int typ, l, r, v;
            scanf("%d %d %d", &typ, &l, &r);
            if( typ == 1 ) {
                ll ans = query_range( 1, 0, n-1, l, r );
                printf("%lld\n", ans);
            }
            else {
                scanf("%d", &v);
                update_range( 1, 0, n-1, l, r, (ll)v );
            }
        }
    }
    return 0;
}
