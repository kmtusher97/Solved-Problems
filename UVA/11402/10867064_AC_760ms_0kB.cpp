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

const int MX = 1123456;
string pirt;
int tree[3*MX], Lazy[3*MX];
/*
    * tree[i] = number of Buccaneer Pirates in that segment
    * Lazy[i] = -1 no change
    * Lazy[i] = 0 make all pirates into Barbary Pirates,
                just update tree[i] = 0;
    * Lazy[i] = 1 make all pirates into Buccaneer Pirates,
                update tree[i] = hi-lo+1
    * Lazy[i] = 2 , inverse the segment, ( tree[i] = (hi-lo+1)-tree[i] )
                if previous Lazy[i] = 0 then update Lazy[i] = 1
                if previous Lazy[i] = 1 then update Lazy[i] = 0
                if previous Lazy[i] = 2 then update Lazy[i] = -1 no change

*/

void update_Lazy( int node, int prp ) {
    if( prp == 1 ) Lazy[node] = 1;
    else if( prp == 0 ) Lazy[node] = 0;
    else if( prp == 2 ) {
        if( Lazy[node] == 0 ) Lazy[node] = 1;
        else if( Lazy[node] == 1 ) Lazy[node] = 0;
        else if( Lazy[node] == 2 ) Lazy[node] = -1;
        else Lazy[node] = 2;
    }
}

void update_tree( int node, int lo, int hi, int prp ) {
    if( prp == 0 ) tree[node] = 0;
    else if( prp == 1 ) tree[node] = hi-lo+1;
    else if( prp == 2 ) tree[node] = (hi-lo+1) - tree[node];
}

void propagation( int node, int lo, int hi, int prp ) {
    if( lo != hi ) {
        update_Lazy( node<<1, prp ); /// left child
        update_Lazy( node<<1|1, prp ); /// right child
    }
    Lazy[node] = -1;
}

void build( int node, int lo, int hi ) {
    if( lo == hi ) {
        tree[node] = pirt[lo]-'0';
        Lazy[node] = -1;
        return;
    }
    int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
    build( lft, lo, mid );
    build( rgt, mid+1, hi );
    tree[node] = tree[lft] + tree[rgt];
    Lazy[node] = -1;
}

void update_range( int node, int lo, int hi, int l, int r, int typ ) {
    if( Lazy[node] != -1 ) {
        update_tree( node, lo, hi, Lazy[node] );
        propagation( node, lo, hi, Lazy[node] );
    }
    if( lo > r || hi < l ) return;
    if( lo >= l && hi <= r ) {
        update_tree( node, lo, hi, typ );
        propagation( node, lo, hi, typ );
        return;
    }
    int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
    update_range( lft, lo, mid, l, r, typ );
    update_range( rgt, mid+1, hi, l, r, typ );
    tree[node] = tree[lft] + tree[rgt];
}

int query_range( int node, int lo, int hi, int l, int r ) {
    if( Lazy[node] != -1 ) {
        update_tree( node, lo, hi, Lazy[node] );
        propagation( node, lo, hi, Lazy[node] );
    }
    if( lo > r || hi < l ) return 0;
    if( lo >= l && hi <= r ) return tree[node];
    int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
    int p = query_range( lft, lo, mid, l, r );
    int q = query_range( rgt, mid+1, hi, l, r );
    return p+q;
}

int main() {
    ios_base :: sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int cases, caseno = 0;
    cin >> cases;
    while( cases-- ) {
        int n, Q, t, q=0, a, b;
        string tmp;
        pirt = "";
        cin >> n;
        while( n-- ) {
            cin >> t >> tmp;
            while( t-- ) {
                pirt += tmp;
            }
        }
        int ln = pirt.length();
        build( 1, 0, ln-1 );
        cin >> Q;
        cout << "Case " << ++caseno << ":" << endl;
        while( Q-- ) {
            cin >> tmp >> a >> b;
            int typ;
            if( tmp[0] == 'F' ) typ = 1;
            else if( tmp[0] == 'E' ) typ = 0;
            else if( tmp[0] == 'I' ) typ = 2;
            else if( tmp[0] == 'S' ) typ = 3;
            if( typ == 3 ) {
                cout << "Q" << ++q << ": " << query_range( 1, 0, ln-1, a, b ) << endl;
            }
            else {
                update_range( 1, 0, ln-1, a, b, typ );
            }
        }
    }
    return 0;
}
