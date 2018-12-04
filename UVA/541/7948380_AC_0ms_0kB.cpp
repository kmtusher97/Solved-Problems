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

    int n, i, j;
    while( sn1(n) && n ) {
        int ar[n+4][n+4];
        for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            sn1(ar[i][j]);
        }

        int r, c, cnt = 0, sm = 0, sm1 = 0;
        bool f = true;
        for(i=0; i<n; i++) {
            if(cnt>1) {f=false; break;}
            for(j=0, sm=0, sm1 = 0; j<n; j++) {
                sm+=ar[i][j];
            }
            if(sm&1) cnt++, r=i+1;
        }
        if(!f) prnt("Corrupt\n");
        else {
            f = true;
            for(i=0, cnt=0; i<n; i++) {
                if(cnt>1) {f=false; break;}
                for(j=0, sm=0, sm1 = 0; j<n; j++) {
                    sm+=ar[j][i];
                }
                if(sm&1) cnt++, c=i+1;
            }
            if(!f) prnt("Corrupt\n");
            else if(cnt == 0) prnt("OK\n");
            else {
                prnt("Change bit (%d,%d)\n", r, c);
            }
        }
    }
}
