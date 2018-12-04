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

const int MX = 2e5;
int rcrd[MX][2];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    while( cin >> n >> q && n && q )
    {
        for(int i=0; i<=n+2; i++)
            rcrd[i][0] = i-1, rcrd[i][1] = i+1;
        while( q-- )
        {
            int l, r;
            cin >> l >> r;
            rcrd[ rcrd[l][0] ][1] = rcrd[r][1];
            rcrd[ rcrd[r][1] ][0] = rcrd[l][0];
            if( rcrd[l][0] < 1 )
                cout << "* ";
            else
                cout << rcrd[l][0] << " ";
            if( rcrd[r][1] > n )
                cout << "*";
            else
                cout << rcrd[r][1];
            cout << endl;
        }
        cout << "-" << endl;
    }

    return 0;
}
