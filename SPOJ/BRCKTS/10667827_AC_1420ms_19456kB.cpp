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
string s;
int tree[3*MX][3];
/*  tree[node][0][1][2]
    0 - sum
    1 - number of opened parenthesis in a segment
    2 - number of closed parenthesis in a segment
*/
void build( int node, int lo, int hi ) {
    if( lo == hi ) {
        if( s[lo] == '(' ) {
            tree[node][0] = 1, tree[node][1] = 1, tree[node][2] = 0;
        }
        else {
            tree[node][0] = -1, tree[node][1] = 0, tree[node][2] = 1;
        }
        return;
    }

    int mid = lo + (hi-lo)/2, lft = node<<1, rgt = lft|1;
    build( lft, lo, mid );
    build( rgt, mid+1, hi );

    tree[node][0] = tree[lft][0] + tree[rgt][0];
    int cmplt = min( tree[lft][1], tree[rgt][2] );
    tree[node][1] = tree[lft][1] + tree[rgt][1] - cmplt;
    tree[node][2] = tree[lft][2] + tree[rgt][2] - cmplt;
}


void update( int node, int lo, int hi, int pos ) {
    if( lo == hi ) {
        tree[node][0] *= -1; // replace with the opposite parenthesis
        s[lo] == '(' ? s[lo] = ')' : s[lo] = '(';
        if( s[lo] == '(' ) {
            tree[node][1] = 1, tree[node][2] = 0;
        }
        else {
            tree[node][1] = 0, tree[node][2] = 1;
        }
        return;
    }

    int mid = lo + (hi-lo)/2, lft = node<<1, rgt = lft|1;
    if( pos <= mid ) {
        update( lft, lo, mid, pos );
    }
    else {
        update( rgt, mid+1, hi, pos );
    }

    tree[node][0] = tree[lft][0] + tree[rgt][0];
    int cmplt = min( tree[lft][1], tree[rgt][2] );
    tree[node][1] = tree[lft][1] + tree[rgt][1] - cmplt;
    tree[node][2] = tree[lft][2] + tree[rgt][2] - cmplt;
}

int main() {
    ios_base :: sync_with_stdio(0);
    int n, Q, caseno = 0;
    while( cin >> n ) {
        cin >> s >> Q;
        build( 1, 0, n-1 );
        cout << "Test " << ++caseno << ":" << endl;
        while( Q-- ) {
            int pos;
            cin >> pos;
            if( !pos ) {
                cout << ( ( !tree[1][0] && !tree[1][1] && !tree[1][2] ) ? "YES" : "NO" ) << endl;
            }
            else update( 1, 0, n-1, pos-1 );
        }
    }
    return 0;
}
