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
int a[MX+100], tree[3*MX+100];

void build( int node, int L, int R )
{
    if( L == R )
    {
        tree[node] = a[L];
        return;
    }

    int mid = L+(R-L)/2;
    build( node*2, L, mid );
    build( node*2+1, mid+1, R );
    tree[node] = tree[node*2] + tree[node*2+1];
}

void update( int node, int i, int vlu, int L, int R )
{
    if( i > R || i < L ) return;
    if( L >= i && R <= i )
    {
        tree[node] = vlu;
        return;
    }

    int mid = L+(R-L)/2;
    update( node*2, i, vlu, L, mid );
    update( node*2+1, i, vlu, mid+1, R );
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query( int node, int L, int R, int i, int j )
{
    if( L > j || R < i ) return 0;
    if( L >= i && R <= j ) return tree[node];

    int mid = L+(R-L)/2;
    int p = query( node*2, L, mid, i, j );
    int q = query( node*2+1, mid+1, R, i, j );
    return (p+q);
}

int main()
{
    int cases, caseno = 0;
    scanf("%d", &cases);
    while( cases-- )
    {
        int N, Q, T, P, V, I, J;
        scanf("%d %d", &N, &Q);
        for(int i=0; i<N; i++) scanf("%d", a+i);
        build( 1, 0, N-1 );
        printf("Case %d:\n", ++caseno);
        while( Q-- )
        {
            scanf("%d", &T);
            if( T == 1 )
            {
                scanf("%d", &P);
                printf("%d\n", a[P]);
                update( 1, P, 0, 0, N-1 );
                a[P] = 0;
            }
            else if( T == 2 )
            {
                scanf("%d %d", &P, &V);
                update( 1, P, V+a[P], 0, N-1 );
                a[P] += V;
            }
            else
            {
                scanf("%d %d", &I, &J);
                printf("%d\n", query( 1, 0, N-1, I, J ));
            }
        }
    }

    return 0;
}
