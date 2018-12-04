#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> q;

#define scn scanf
#define sn1(a) scanf("%d", &a)
#define sn2(a, b) scanf("%d %d", &a, &b);
#define sn3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sn4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define snl1(a) scanf("%lld", &a)
#define snl2(a, b) scanf("%lld %lld", &a, &b)
#define snl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define prnt printf
#define pb push_back
#define NL printf("\n")
#define PI acos(-1)
#define MX 5008
#define modulo 1000007

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    LL i, j, n, ar[20], tc=0;
    while( snl1(n) == 1 ) {
        LL m = 1, mx = 0;
        for(i=0; i<n; i++) {
            snl1(ar[i]);

        }
        for(i=0; i<n; i++) {
            for(j=i, m=1; j<n; j++) {
                m*=ar[j];
                mx = max(mx, m);
            }

        }
        prnt("Case #%lld: The maximum product is %lld.\n\n", ++tc, mx);
    }
}
