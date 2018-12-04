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

const int MX = 123456;
const int inf = 1123456789;

int a[MX], pwr[MX], sp[17][MX];

void mn_pwr_2() {
    for(int i=2, p=0; i<100050; i++) {
        int nw = 1<<p;
        if( i%nw == 0 && i/nw == 2 ) p++;
        pwr[i] = p;
} }

void build_sprctbl( int n ) {
    for(int i=0; i<17; i++) {
        for(int j=0; j<n; j++) {
            if( i == 0 ) sp[i][j] = a[j];
            else {
                int sg_ln = 1 << (i-1);
                if( j+sg_ln >= n ) sp[i][j] = inf;
                else sp[i][j] = min(sp[i-1][j], sp[i-1][j+sg_ln]);
            }
} } }

int query( int lft, int rgt ) {
    int ln = rgt-lft+1, nxt = rgt-(1<<pwr[ln])+1;
    return min(sp[pwr[ln]][lft], sp[pwr[rgt-nxt+1]][nxt] );
}

int main() {
    mn_pwr_2();
    int cases, caseno =0, n, Q, L, R;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d", &n, &Q);
        for(int i=0; i<n; i++) {
            scanf("%d", a+i);
        }
        build_sprctbl(n);
        printf("Case %d:\n", ++caseno);
        while( Q-- ) {
            scanf("%d %d", &L, &R);
            printf("%d\n", query(L-1, R-1));
    } }
    return 0;
}
