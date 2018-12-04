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
int fibs[650][500];

void all_fibs() {
        fibs[1][499] = fibs[2][499] = 1;
        for(int i=3; i<600; i++) {
                int crry = 0;
                for(int j=499; j>=0; j--) {
                        int dgt = fibs[i-1][j] + fibs[i-2][j] + crry;
                        fibs[i][j] = dgt%10;
                        crry = dgt/10;

                }
        }

        fibs[1][499] = 0;
}

int cmp( string s, int n ) {
        int pos = 499, sz = s.length();
        for(int i=0; i<500; i++) if( fibs[n][i] ) {
                pos = i; break;
        }

        if( sz < 500-pos ) return 1;
        if( sz > 500-pos ) return 0;

        for(int i=0; i<sz; i++, pos++) {
                if( s[i]-48 < fibs[n][pos] ) return 1;
                if( s[i]-48 > fibs[n][pos] ) return 0;
        }

        return 2;
}

int main() {
        ios_base :: sync_with_stdio(false); cin.tie(0);

        all_fibs();
        string n1, n2;
        while( cin >> n1 >> n2 ) {
                if( n1 == "0" && n2 == "0" ) break;

                int p1, p2, ans=0;
                for(int i=0; i<600; i++) {
                        int chk = cmp(n1, i);
                        if( chk == 1 ) {
                                p1 = i; break;
                        }
                        else if( chk == 2 ) {
                                ans=1;
                        }
                }
                if( n1 == "0" ) ans = 0;

                for(int i=p1; i<600; i++) {
                        int chk = cmp( n2, i );
                        if( chk == 1 ) break;
                        ans++;
                        if( chk == 2 ) break;
                }

                cout << ans << endl;
        }

        return 0;
}
