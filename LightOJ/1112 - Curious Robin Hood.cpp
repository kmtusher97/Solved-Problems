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
ll tree[MX];

void update_BIT( int pos, int vlu, int maxpos )
{
    while( pos <= maxpos )
    {
        tree[pos] += vlu;
        pos += (pos & (-pos));
    }
}

ll query_BIT( int pos, int maxpos )
{
    ll sm = 0;
    while( pos > 0 )
    {
        sm += tree[pos];
        pos -= (pos & (-pos));
    }
    return sm;
}

int main()
{
    int cases, caseno = 0, n, Q;
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%d %d", &n, &Q);
        memset(tree, 0, sizeof tree);
        for(int i=1, a; i<=n; i++)
        {
            scanf("%d", &a);
            update_BIT( i, a, n );
        }
        printf("Case %d:\n", ++caseno);
        while( Q-- )
        {
            int typ, x, y;
            scanf("%d %d", &typ, &x);
            if( typ == 1 )
            {
                ll sm = query_BIT( x+1, n );
                sm -= query_BIT( x, n );
                printf("%lld\n", sm);
                update_BIT( x+1, -sm, n );
            }
            else if( typ == 2 )
            {
                scanf("%d", &y);
                update_BIT( x+1, y, n );
            }
            else
            {
                scanf("%d", &y);
                ll sm = query_BIT( y+1, n );
                sm -= query_BIT( x, n );
                printf("%lld\n", sm);
            }
        }
    }
    return 0;
}
