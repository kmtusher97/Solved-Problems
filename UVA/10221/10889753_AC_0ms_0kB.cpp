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
const double PI = acos(-1);

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    double s, a, arc, crd;
    string dgmn;
    while( cin >> s >> a >> dgmn ) {
        s += 6440.0;
        if( dgmn == "min" ) a /= 60.0;
        if( a > 180.0 ) a = 360.0-a;
        a = (a*PI)/180.0;
        arc = a*s;
        crd = 2 * (s*sin(a/2.0));
        cout << fixed << setprecision(6) << arc << " " << crd << endl;
    }
    return 0;
}
