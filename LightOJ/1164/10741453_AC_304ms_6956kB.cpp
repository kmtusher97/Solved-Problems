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
ll tree[3*MX][2];

void update_lazy( int node, int lo, int hi, int l, int r, ll vlu ) {
    if( lo > r || hi < l ) return;
    if( lo >= l && hi <= r ) {
        tree[node][0] += (hi-lo+1)*vlu;
        tree[node][1] += vlu;
        return;
    }
    int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
    update_lazy( lft, lo, mid, l, r, vlu );
    update_lazy( rgt, mid+1, hi, l, r, vlu );
    tree[node][0] = tree[lft][0] + tree[rgt][0] + (hi-lo+1)*tree[node][1];
}

ll query( int node, int lo, int hi, int l, int r, ll x ) {
    if( lo > r || hi < l ) return 0LL;
    if( lo >= l && hi <= r ) {
        return (tree[node][0]+(hi-lo+1)*x);
    }
    int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
    ll p = query( lft, lo, mid, l, r, x+tree[node][1] );
    ll q = query( rgt, mid+1, hi, l, r, x+tree[node][1] );
    return p+q;
}

int main() {
    int cases, caseno = 0, n, Q;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d", &n, &Q);
        for(int i=0; i<=3*n+10; i++) {
            tree[i][0] = tree[i][1] = 0;
        }
        printf("Case %d:\n", ++caseno);
        while( Q-- ) {
            int a, b, c, d;
            scanf("%d %d %d", &a, &b, &c);
            if( a == 0 ) {
                scanf("%d", &d);
                update_lazy( 1, 0, n-1, b, c, (ll)d );
            }
            else {
                 printf("%lld\n", query( 1, 0, n-1, b, c, 0LL ));
            }
        }
    }
    return 0;
}
