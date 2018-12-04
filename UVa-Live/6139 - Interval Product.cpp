#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 1123456;
int a[MX], tree[MX];

void build( int node, int lo, int hi ) {
    if( hi == lo ) {
        tree[node] = a[lo];
        return;
    }
    int mid = lo+(hi-lo)/2;
    build( node*2, lo, mid );
    build( node*2+1, mid+1, hi );
    tree[node] = tree[node*2] * tree[node*2+1];
}

void update( int node, int lo, int hi, int pos, int vlu ) {
    if( lo == hi ) {
        tree[node] = vlu;
        return;
    }
    int mid = lo+(hi-lo)/2;
    if( mid >= pos ) update( node*2, lo, mid, pos, vlu );
    else update( node*2+1, mid+1, hi, pos, vlu );
    tree[node] = tree[node*2] * tree[node*2+1];
}

int query( int node, int lo, int hi, int lft, int rgt ) {
    if( lo > rgt || hi < lft ) return 1;
    if( lo >= lft && hi <= rgt ) return tree[node];
    int mid = lo+(hi-lo)/2;
    int p = query( node*2, lo, mid, lft, rgt ) * query( node*2+1, mid+1, hi, lft, rgt );
    return p;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    while( cin >> n >> k ) {
        for(int i=0; i<n; i++) {
            cin >> a[i];
            if( a[i] > 0 ) a[i] = 1;
            if( a[i] < 0 ) a[i] = -1;
        }
        build( 1, 0, n-1 );
        string ans = "";
        while( k-- ) {
            string s;
            int l, r;
            cin >> s >> l >> r;
            if( s[0] == 'C' ) {
                if( r > 0 ) r = 1;
                if( r < 0 ) r = -1;
                update( 1, 0, n-1, l-1, r );
            }
            else {
                int x = query( 1, 0, n-1, l-1, r-1 );
                if( x == 0 ) ans += "0";
                else if( x > 0 ) ans += "+";
                else ans += "-";
            }
        }
        cout << ans << endl;
    }
    return 0;
}
