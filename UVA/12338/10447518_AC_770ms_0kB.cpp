#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MX = 112345;
const int modulo1 = 10000007;
const int modulo2 = 1000000007;
const int base1 = 31, base2 = 37;
string ss[MX];
vii hs[MX];

void gnrte_hash( int indx ) {
    ll pwr1 = 1, pwr2 = 1, hs_vlu1 = 0, hs_vlu2 = 0;
    for(int i=0, sz=ss[indx].length(); i<sz; ++i) {
        pwr1 = ( (pwr1%modulo1) * base1 ) % modulo1;
        pwr2 = ( (pwr2%modulo2) * base2 ) % modulo2;
        hs_vlu1 = ( hs_vlu1%modulo1 + ( (ss[indx][i]-96) * pwr1 ) % modulo1 ) % modulo1;
        hs_vlu2 = ( hs_vlu2%modulo2 + ( (ss[indx][i]-96) * pwr2 ) % modulo2 ) % modulo2;
        hs[indx].pb( mk_pr( (int)(hs_vlu1%modulo1), (int)(hs_vlu2%modulo2) ) );
    }
}

bool chk( int l, int r, int m ) {
    if( hs[l][m].first == hs[r][m].first && hs[l][m].second == hs[r][m].second ) return true;
    return false;
}

int srch_ans( int lft, int rgt ) {
    int lo = 0, mid, hi = min(ss[lft].size(), ss[rgt].size())-1, mx = -1;
    while(lo <= hi) {
        mid = lo + (hi-lo)/2;
        if( chk( lft, rgt, mid ) ) mx = max(mx, mid), lo = mid+1;
        else hi = mid-1;
    }
    return mx;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cases, caseno = 0, n, Q, l, r;
    cin >> cases;
    while( cases-- ) {
        cin >> n;
        for(int i=0; i<n; ++i) {
            cin >> ss[i];
            hs[i].clear();
            gnrte_hash(i);
        }
        cin >> Q;
        cout << "Case " << ++caseno << ":" << endl;
        while( Q-- ) {
            cin >> l >> r;
            cout << srch_ans( l-1, r-1 )+1 << endl;
        }
    }
    return 0;
}
