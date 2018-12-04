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

const int MX = 1e5;
int tree[4*MX];
char bnryStrng[MX+100], typ[10];

void build( int node, int lo, int hi ) {
        if( lo == hi ) {
                tree[node] = 0;
                return;
        }

        int mid = lo + (hi-lo)/2;
        build( node*2, lo, mid );
        build( node*2+1, mid+1, hi );
        tree[node] = tree[node*2] + tree[node*2+1];
}

void updateLegy( int node, int lo, int hi, int lft, int rgt ) {
        if( hi < lft || lo > rgt ) return;
        if( lo >= lft && hi <= rgt ) {
                tree[node] += 1;
                return;
        }

        int mid = lo+(hi-lo)/2;
        updateLegy( node*2, lo, mid, lft, rgt );
        updateLegy( node*2+1, mid+1, hi, lft, rgt );
}

void query( int node, int lo, int hi, int pos, int x ) {
        if( hi < pos || lo > pos ) return;
        if( lo >= pos && hi <= pos ) {
                if( (tree[node]+x)&1 ) printf("%d\n", !(int)(bnryStrng[pos]-'0'));
                else printf("%d\n", (int)(bnryStrng[pos]-'0'));
                return;
        }

        int mid = lo + (hi-lo)/2;
        query( node*2, lo, mid, pos, x+tree[node] );
        query( node*2+1, mid+1, hi, pos, x+tree[node] );
}

int main() {
        //ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int cases, caseno=0, Q, L, R;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%s", bnryStrng);
                int lnth = strlen(bnryStrng);
                build( 1, 0, lnth-1 );
                printf("Case %d:\n", ++caseno);
                scanf("%d", &Q);
                while( Q-- ) {
                        scanf("%s", typ);
                        if( typ[0] == 'I' ) {
                                scanf("%d %d", &L, &R);
                                updateLegy( 1, 0, lnth-1, L-1, R-1 );
                        }
                        else {
                                scanf("%d", &L);
                                query( 1, 0, lnth-1, L-1, 0 );
                        }
                }
        }
        return 0;
}
